#include "printer.h"

void Printer::visit(CompUnitAST &ast) {
    PUT(depth);
    cout << "CompUnit:" << endl;
    depth += 2;
    for (auto &i : ast.declDefList) {
        i->accept(*this);
    }
    depth -= 2;
}

void Printer::visit(DeclDefAST &ast) {
    if (ast.Decl != nullptr) {
        ast.Decl->accept(*this);
    } else {
        ast.funcDef->accept(*this);
    }
}

void Printer::visit(DeclAST &ast) {
    PUT(depth);
    cout << "Decl:" << endl;
    depth += 2;
    if (ast.isConst) {
        PUT(depth);
        cout << "const" << endl;
    }
    PUT(depth);
    if (ast.bType == TYPE_INT) cout << "BType:int" << endl;
    else cout << "BType:float" << endl;
    for (auto &def: ast.defList) {
        def->accept(*this);
    }
    depth -= 2;
}

void Printer::visit(DefAST &ast) {
    PUT(depth);
    cout << "Def:" << endl;
    depth += 2;
    PUT(depth);
    cout << "id:" << *(ast.id) << endl;
    if (!ast.arrays.empty()) {
        PUT(depth);
        cout << "Arrays:" << endl;
        depth += 2;
        for (auto &i : ast.arrays) {
            i->accept(*this);
        }
        depth -= 2;
    }
    if (ast.initVal != nullptr) ast.initVal->accept(*this);
    depth -= 2;
}

void Printer::visit(InitValAST &ast) {
    PUT(depth);
    cout << "InitValAST：";
    depth += 2;
    if (ast.exp != nullptr) {
        cout << endl;
        ast.exp->accept(*this);
    } else if (!ast.initValList.empty()) {
        cout << endl;
        PUT(depth);
        cout << "InitValList:" << endl;
        depth += 2;
        for (auto &initVal: ast.initValList) {
            initVal->accept(*this);
        }
        depth -= 2;
    } else {
        cout << "{}" << endl;
    }
    depth -= 2;
}

void Printer::visit(FuncDefAST &ast) {
    PUT(depth);
    cout << "FuncDef:" << endl;
    depth += 2;
    PUT(depth);
    if (ast.funcType == TYPE_VOID) cout << "funcType:void" << endl;
    else if (ast.funcType == TYPE_INT) cout << "funcType:int" << endl;
    else cout << "funcType:float" << endl;
    PUT(depth); cout << "id:" << *ast.id << endl;
    if (!ast.funcFParamList.empty()) {
        PUT(depth);
        cout << "FuncFParamList:" << endl;
        depth += 2;
        for (auto &i : ast.funcFParamList) {
            i->accept(*this);
        }
        depth -= 2;
    }
    ast.block->accept(*this);
    depth -= 2;
}

void Printer::visit(FuncFParamAST &ast) {
    PUT(depth);
    cout << "FuncFParam:" << endl;
    depth += 2;
    PUT(depth);
    if (ast.bType == TYPE_INT) cout << "BType:int" << endl;
    else cout << "BType:float" << endl;
    PUT(depth); cout << "id:" << *ast.id << endl;
    if (ast.isArray) {
        PUT(depth);
        cout << "Array:[]" << endl;

    }
    if (!ast.arrays.empty()) {
        PUT(depth);
        cout << "Arrays:" << endl;
        depth += 2;
        for (auto &i : ast.arrays) {
            i->accept(*this);
        }
        depth -= 2;
    }
    depth -= 2;
}

void Printer::visit(BlockAST &ast) {
    PUT(depth);
    cout << "Block:" << endl;
    depth += 2;
    if (!ast.blockItemList.empty()) {
        PUT(depth);
        cout << "BlockItemList:" << endl;
        depth += 2;
        for (auto &i : ast.blockItemList) {
            i->accept(*this);
        }
        depth -= 2;
    }
    depth -= 2;
}

void Printer::visit(BlockItemAST &ast) {
    if (ast.decl != nullptr) {
        ast.decl->accept(*this);
    } else {
        ast.stmt->accept(*this);
    }
}

void Printer::visit(StmtAST &ast) {
    PUT(depth);
    cout << "Stmt:";
    switch (ast.sType) {
        case SEMI:
            cout << "semicolon" << endl;
            break;
        case ASS:
            cout << endl;
            depth += 2;
            ast.lVal->accept(*this);
            ast.exp->accept(*this);
            depth -= 2;
            break;
        case EXP:
            cout << endl;
            depth += 2;
            ast.exp->accept(*this);
            depth -= 2;
            break;
        case CONT:
            cout << "continue" << endl;
            break;
        case BRE:
            cout << "break" << endl;
            break;
        case RET:
            cout << endl;
            depth += 2;
            ast.returnStmt->accept(*this);
            depth -= 2;
            break;
        case BLK:
            cout << endl;
            depth += 2;
            ast.block->accept(*this);
            depth -= 2;
            break;
        case SEL:
            cout << endl;
            depth += 2;
            ast.selectStmt->accept(*this);
            depth -= 2;
            break;
        case ITER:
            cout << endl;
            depth += 2;
            ast.iterationStmt->accept(*this);
            depth -= 2;
            break;
    }

}

void Printer::visit(ReturnStmtAST &ast) {
    PUT(depth);
    cout << "return:";
    if (ast.exp == nullptr) cout << "void" << endl;
    else {
        cout << endl;
        depth += 2;
        ast.exp->accept(*this);
        depth -= 2;
    }
}

void Printer::visit(SelectStmtAST &ast) {
    PUT(depth);
    cout << "SelectStmt:" << endl;
    depth += 2;
    ast.cond->accept(*this);
    ast.ifStmt->accept(*this);
    if (ast.elseStmt != nullptr) ast.elseStmt->accept(*this);
    depth -= 2;
}

void Printer::visit(IterationStmtAST &ast) {
    PUT(depth);
    cout << "IterationStmt:" << endl;
    depth += 2;
    ast.cond->accept(*this);
    ast.stmt->accept(*this);
    depth -= 2;
}

void Printer::visit(AddExpAST &ast) {
    PUT(depth);
    cout << "AddExp:" <<endl;
    depth += 2;
    if (ast.addExp != nullptr) {
        ast.addExp->accept(*this);
        PUT(depth);
        cout << "AOP:";
        if (ast.op == AOP_ADD) cout << "+" << endl;
        else cout << "-" << endl;
    }
    ast.mulExp->accept(*this);
    depth -= 2;
}

void Printer::visit(MulExpAST &ast) {
    PUT(depth);
    cout << "MulExp:" << endl;
    depth += 2;
    if (ast.mulExp != nullptr) {
        ast.mulExp->accept(*this);
        PUT(depth);
        cout << "MOP:";
        if (ast.op == MOP_MUL) cout << "*" << endl;
        else if(ast.op == MOP_DIV) cout << "/" << endl;
        else cout << "%" << endl;
    }
    ast.unaryExp->accept(*this);
    depth -= 2;
}

void Printer::visit(UnaryExpAST &ast) {
    PUT(depth);
    cout << "UnaryExp:" << endl;
    depth += 2;
    if (ast.primaryExp != nullptr) {
        ast.primaryExp->accept(*this);
    } else if (ast.call != nullptr) {
        ast.call->accept(*this);
    } else {
        PUT(depth);
        cout << "UnaryOp:";
        if (ast.op == UOP_ADD) cout << "+" <<endl;
        if (ast.op == UOP_MINUS) cout << "-" <<endl;
        if (ast.op == UOP_NOT) cout << "!" <<endl;
        ast.unaryExp->accept(*this);
    }
    depth -= 2;
}

void Printer::visit(PrimaryExpAST &ast) {
    PUT(depth);
    cout << "PrimaryExp:" << endl;
    depth += 2;
    if (ast.exp != nullptr) {
        ast.exp->accept(*this);
    } else if (ast.lval != nullptr) {
        ast.lval->accept(*this);
    } else {
        ast.number->accept(*this);
    }
    depth -= 2;
}

void Printer::visit(CallAST &ast) {
    PUT(depth);
    cout << "Call:" << endl;
    depth += 2;
    PUT(depth);
    cout << "id:" << (*ast.id) << endl;
    if (!ast.funcCParamList.empty()) {
        PUT(depth);
        cout << "FuncCParamList:" << ast.funcCParamList.size() << endl;
        depth += 2;
        for (auto &i : ast.funcCParamList) {
            i->accept(*this);
        }
        depth -= 2;
    }
    depth -= 2;
}

void Printer::visit(LValAST &ast) {
    PUT(depth);
    cout << "LVal:" << endl;
    depth += 2;
    PUT(depth);cout << "id:" << (*ast.id) << endl;
    if (!ast.arrays.empty()) {
        cout << "Arrays:" << endl;
        depth += 2;
        for (auto &i : ast.arrays) {
            i->accept(*this);
        }
        depth -= 2;
    }
    depth -= 2;
}

void Printer::visit(NumberAST &ast) {
    PUT(depth);
    cout << "number:";
    if (ast.isInt) cout <<  ast.intval << endl;
    else cout <<  ast.floatval << endl;
}

void Printer::visit(RelExpAST &ast) {
    PUT(depth);
    cout << "RelExp:" << endl;
    depth += 2;
    if (ast.relExp != nullptr) {
        ast.relExp->accept(*this);
        PUT(depth);
        cout << "RelOP:";
        if (ast.op == ROP_GTE) cout << ">=" << endl;
        else if (ast.op == ROP_LTE) cout << "<=" << endl;
        else if (ast.op == ROP_GT) cout << ">" << endl;
        else if (ast.op == ROP_LT) cout << "<" << endl;
    }
    ast.addExp->accept(*this);
    depth -= 2;
}

void Printer::visit(EqExpAST &ast) {
    PUT(depth);
    cout << "EqExp:" << endl;
    depth += 2;
    if (ast.eqExp != nullptr) {
        ast.eqExp->accept(*this);
        PUT(depth);
        cout << "EqOP:";
        if (ast.op == EOP_EQ) cout << "==" << endl;
        else cout << "!=" <<endl;
    }
    ast.relExp->accept(*this);
    depth -= 2;
}

void Printer::visit(LAndExpAST &ast) {
    PUT(depth);
    cout << "LAndExp:" << endl;
    depth += 2;
    if (ast.lAndExp != nullptr) {
        ast.lAndExp->accept(*this);
        PUT(depth);
        cout << "AND_OP:&&";
    }
    ast.eqExp->accept(*this);
    depth -= 2;
}

void Printer::visit(LOrExpAST &ast) {
    PUT(depth);
    cout << "LOrExp:" << endl;
    depth += 2;
    if (ast.lOrExp != nullptr) {
        ast.lOrExp->accept(*this);
        PUT(depth);
        cout << "OR_OP:||";
    }
    ast.lAndExp->accept(*this);
    depth -= 2;
}

