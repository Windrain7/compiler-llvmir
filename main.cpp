#include <iostream>
#include "printer.h"
//#include "genIR.h"
extern unique_ptr<CompUnitAST> root;
extern int yyparse();
extern FILE *yyin;
std::string filename = "-";

int main(int argc, char **argv) {
    std::cout << "------open------" <<std::endl;
    yyin = fopen(argv[1], "r");
    filename = argv[1];
    if (yyin == nullptr) return -1;
    std::cout << "------parse------" <<std::endl;
    yyparse();
    std::cout << "------printast------" <<std::endl;
    Printer printer;
    root->accept(printer);
//    std::cout << "------GenIR------" <<std::endl;
//    GenIR genir;
//    root->accept(genir);
//    std::cout << "------printIR------" <<std::endl;
//    auto m = genir.getModule();
//    auto IR = m->print();
//    std::cout << IR;
    std::cout << "------end------" <<std::endl;
    return 0;
}
