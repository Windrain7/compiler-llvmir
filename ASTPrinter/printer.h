#ifndef TEST_PRINTER_H
#define TEST_PRINTER_H

#include "ast.h"

class Printer: public Visitor {
public:
    int depth = 0;
    void visit(CompUnitAST &ast) override;
    void visit(DeclDefAST &ast) override;
    void visit(DeclAST &ast) override;
    void visit(DefAST &ast) override;
    void visit(InitValAST &ast) override;
    void visit(FuncDefAST &ast) override;
    void visit(FuncFParamAST &ast) override;
    void visit(BlockAST &ast) override;
    void visit(BlockItemAST &ast) override;
    void visit(StmtAST &ast) override;
    void visit(ReturnStmtAST &ast) override;
    void visit(SelectStmtAST &ast) override;
    void visit(IterationStmtAST &ast) override;
    void visit(ExpAST &ast) override;
    void visit(AddExpAST &ast) override;
    void visit(LValAST &ast) override;
    void visit(MulExpAST &ast) override;
    void visit(UnaryExpAST &ast) override;
    void visit(PrimaryExpAST &ast) override;
    void visit(CondAST &ast) override;
    void visit(CallAST &ast) override;
    void visit(NumberAST &ast) override;
    void visit(RelExpAST &ast) override;
    void visit(EqExpAST &ast) override;
    void visit(LAndExpAST &ast) override;
    void visit(LOrExpAST &ast) override;
};



#endif //TEST_PRINTER_H
