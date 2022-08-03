#include <iostream>
#include <fstream>
#include "printer.h"
#include "genIR.h"
extern unique_ptr<CompUnitAST> root;
extern int yyparse();
extern FILE *yyin;
const char *inFile, *outFile;

int main(int argc, char **argv) {
    if (argc == 2) {
        inFile = argv[1];
    } else if (argc == 4) {
        inFile = argv[4];
        outFile = argv[2];
        ofstream fout(outFile);
        streambuf* old =cout.rdbuf(fout.rdbuf());
    }
    std::cout << "------open------" <<std::endl;
    yyin = fopen(inFile, "r");
    if (yyin == nullptr) return -1;
    std::cout << "------parse------" <<std::endl;
    yyparse();
    std::cout << "------printast------" <<std::endl;
    Printer printer;
    root->accept(printer);
    std::cout << "------GenIR------" <<std::endl;
    GenIR genir;
    root->accept(genir);
    std::cout << "------printIR------" <<std::endl;
    auto m = genir.getModule();
    auto IR = m->print();
    std::cout << IR;
    std::cout << "------end------" <<std::endl;
    return 0;
}