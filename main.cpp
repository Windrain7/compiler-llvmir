#include <getopt.h>
#include <fstream>
#include <iostream>
#include "genIR.h"
#include "printer.h"
extern unique_ptr<CompUnitAST> root;
extern int yyparse();
//extern int GenS(Module* Mod, std::string output_s_file, bool print_s_verbosity);
extern FILE* yyin;
void preprocess(std::string srcFileName);

//功能测试：compiler -S -o testcase.s testcase.sy
//性能测试：compiler -S -o testcase.s testcase.sy -O2
//打印AST：compiler -a [testcase.ast] testcase.sy [-O2]
/*
-a
-A testcase.ast
-i
-I testcase.ir
-S
-o testcase.s
-O2
testcase.sy
*/
//./compiler -a -i -S -o 1.s 1.sy
int main(int argc, char** argv) {
    assert(argc >= 2);
    std::string filename = "-";
    bool print_debug_info = false;
    bool print_ast = false;
    std::string output_ast_file = "-";
    bool print_ir = false;
    std::string output_ir_file = "-";
    bool print_s = false;
    bool print_s_verbosity = false;
    std::string output_s_file = "-";
    int optlevel = 0;

    //读入并解析命令行参数
    int commandopt;
    while (-1 != (commandopt = getopt(argc, argv, "hDaA:iI:So:O::"))) {
        switch (commandopt) {
            case 'h':
                // std::cout<<"Usage: ./compiler [-h] [-a] [-A testcase.ast] [-i] [-I testcase.ir] [-S] [-o testcase.s] [-O<optlevel>] testcase.sy\n";
                std::cout << "Usage: ./compiler [-h] [-D] [-a] [-i] [-I testcase.ir] [-S] [-v] [-o testcase.s] [-O<optlevel>] testcase.sy\n";
                return 0;
            case 'D':
                print_debug_info = true;
                break;
            case 'a':
                print_ast = true;
                break;
                // case 'A':
                //     output_ast_file = optarg;
                //     break;
            case 'i':
                print_ir = true;
                break;
            case 'I':
                output_ir_file = optarg;
                break;
            case 'S':
                // print_s = true;
                break;
            case 'v':
                print_s_verbosity = true;
                break;
            case 'o':
                output_s_file = optarg;
                break;
            case 'O':
                optlevel = atoi(optarg);
                break;
            default:
                printf("Invalid argument!\n");
                return -1;
        }
    }
    filename = argv[optind];
    if (print_debug_info) {
        std::cout << "------open------" << std::endl;
    }
    preprocess(filename);
    yyin = fopen("temp.sy", "r");
    if (yyin == nullptr) {
        std::cout << "yyin open temp.sy failed" << std::endl;
        return -1;
    }
    if (print_debug_info) {
        std::cout << "------parse------" << std::endl;
    }
    yyparse();
    if (print_debug_info) {
        std::cout << "------printAST------" << std::endl;
    }
    if (print_ast) {
        Printer printer;
        root->accept(printer);
    }
    if (print_debug_info) {
        std::cout << "------GenIR------" << std::endl;
    }
    GenIR genir;
    root->accept(genir);
    if (print_debug_info) {
        std::cout << "------printIR------" << std::endl;
    }
    std::unique_ptr<Module> m = genir.getModule();
    std::string IR = m->print();
    if (print_ir) {
        std::cout << IR;
    }
    if (output_ir_file != "-") {
        std::ofstream output_stream;
        output_stream.open(output_ir_file, std::ios::out);
        output_stream << IR;
        output_stream.close();
    }
//    if (print_debug_info) {
//        std::cout << "------GenS------" << std::endl;
//    }
//    if (output_s_file != "-") {
//        GenS(m.get(), output_s_file, print_s_verbosity);
//    }
    if (print_debug_info) {
        std::cout << "------end------" << std::endl;
    }

    return 0;
}

void preprocess(std::string srcFileName) {
    //preprocess
    FILE* src_f = fopen(srcFileName.c_str(), "r");
    char ch;
    std::string src_content, dst_content;
    int lineno = 1;
    while ((ch = getc(src_f)) != EOF) {
        src_content += ch;
    }
    fclose(src_f);
    for (int i = 0; i < src_content.size(); i ++ ) {
        if (src_content[i] == '\n') {
            lineno ++ ;
            dst_content += '\n';
        }
        else if (src_content[i] == 's') {
            //starttime()
            if (i + 10 < src_content.size() && src_content.substr(i, 11) == "starttime()") {
                dst_content += "_sysy_starttime(" + to_string(lineno) + ')';
                i += 10;
            }
                //stoptime()
            else if (i + 9 < src_content.size() && src_content.substr(i, 10) == "stoptime()") {
                dst_content += "_sysy_stoptime(" + to_string(lineno) + ')';;
                i += 9;
            }
            else dst_content += 's';
        }
        else dst_content += src_content[i];
    }
    //std::cout << dst_content << std::endl;
    FILE* dst_f;
    if ((dst_f = fopen("temp.sy", "w+")) == NULL) {
        std::cout << "dst_f open temp.sy failed" << std::endl;
        exit(-1);
    }
    //std::cout << "dst_f open temp.sy ok" << std::endl;
    fprintf(dst_f, "%s\n", dst_content.c_str());
    fclose(dst_f);
}
