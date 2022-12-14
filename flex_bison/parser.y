%define parse.error verbose
%locations
%{
    #include "ast.h"
    #include "define.h"
    #include <memory>
    #include<stdarg.h>
    using namespace std;
    unique_ptr<CompUnitAST> root; /* the top level root node of our final AST */

    extern int yylineno;
    extern int yylex();
    extern void yyerror(const char *s);
%}

%union {
    CompUnitAST* compUnit;
    DeclDefAST* declDef;
    DeclAST* decl;
    DefListAST* defList;
    DefAST* def;
    ArraysAST* arrays;
    InitValListAST* initValList;
    InitValAST* initVal;
    FuncDefAST* funcDef;
    FuncFParamListAST* FuncFParamList;
    FuncFParamAST* funcFParam;
    BlockAST* block;
    BlockItemListAST* blockItemList;
    BlockItemAST* blockItem;
    StmtAST* stmt;
    ReturnStmtAST* returnStmt;
    SelectStmtAST* selectStmt;
    IterationStmtAST* iterationStmt;
    LValAST* lVal;
    PrimaryExpAST* primaryExp;
    NumberAST* number;
    UnaryExpAST* unaryExp;
    CallAST* call;
    FuncCParamListAST* funcCParamList;
    MulExpAST* mulExp;
    AddExpAST* addExp;
    RelExpAST* relExp;
    EqExpAST* eqExp;
    LAndExpAST* lAndExp;
    LOrExpAST* lOrExp;

    TYPE ty;
    UOP op;
	string* token;
	int int_val;
	float float_val;
};

//%union is not used, and %token and %type expect genuine types, not type tags
%type <compUnit> CompUnit;
%type <declDef> DeclDef;
%type <decl> Decl;
%type <defList> DefList;
%type <def> Def;
%type <arrays> Arrays;
%type <initValList> InitValList;
%type <initVal> InitVal;
%type <funcDef> FuncDef;
%type <FuncFParamList> FuncFParamList
%type <funcFParam> FuncFParam;
%type <block> Block;
%type <blockItemList> BlockItemList;
%type <blockItem> BlockItem;
%type <stmt> Stmt;
%type <returnStmt> ReturnStmt;
%type <selectStmt> SelectStmt;
%type <iterationStmt> IterationStmt;
%type <lVal> LVal;
%type <primaryExp> PrimaryExp;
%type <number> Number;
%type <unaryExp> UnaryExp;
%type <call> Call;
%type <funcCParamList> FuncCParamList;
%type <mulExp> MulExp;
%type <addExp> Exp, AddExp;
%type <relExp> RelExp;
%type <eqExp> EqExp;
%type <lAndExp> LAndExp;
%type <lOrExp> Cond, LOrExp;

%type <ty> BType VoidType
%type <op> UnaryOp

//% token ?????????????????????????????????
%token <int_val> INT           // ??????INT????????????????????????type_int?????????????????????????????????
%token <float_val> FLOAT       // ??????FLOAT????????????????????????type_float?????????????????????????????????
%token <token> ID            // ??????ID
%token GTE LTE GT LT EQ NEQ    // ????????????
%token INTTYPE FLOATTYPE VOID  // ????????????
%token CONST RETURN IF ELSE WHILE BREAK CONTINUE
%token LP RP LB RB LC RC COMMA SEMICOLON
//???bison?????????????????????????????????-d????????????exp.tab.h???????????????????????????????????????lex.l?????????parser.tab.h???????????????????????????
%token NOT POS NEG ASSIGN MINUS ADD MUL DIV MOD AND OR

%left ASSIGN
%left OR AND
%left EQ NEQ
%left GTE LTE GT LT
%left ADD MINUS
%left MOD MUL DIV
%right NOT POS NEG 

%nonassoc LOWER_THEN_ELSE
%nonassoc ELSE

%start Program

%%
Program:CompUnit {
          root = unique_ptr<CompUnitAST>($1);
		}
		;

// ????????????
CompUnit:CompUnit DeclDef {
            $$ = $1;
            $$->declDefList.push_back(unique_ptr<DeclDefAST>($2));
		}
		|DeclDef {
            $$ = new CompUnitAST();
		    $$->declDefList.push_back(unique_ptr<DeclDefAST>($1));
		}
		;

//????????????????????????
DeclDef: Decl {
			$$ = new DeclDefAST();
			$$->Decl = unique_ptr<DeclAST>($1);
		}
		|FuncDef {
            $$ =  new DeclDefAST();
			$$->funcDef = unique_ptr<FuncDefAST>($1);
		}
        ;

// ?????????????????????
Decl:	CONST BType DefList SEMICOLON {
            $$ = new DeclAST();
            $$->isConst = true;
			$$->bType = $2;
			$$->defList.swap($3->list);
		}
        |BType DefList SEMICOLON {
            $$ = new DeclAST();
            $$->isConst = false;
			$$->bType = $1;
			$$->defList.swap($2->list);
        }
		;

// ????????????
BType:	INTTYPE {
			$$ = TYPE_INT;
		}
		|FLOATTYPE {
            $$ = TYPE_FLOAT;
        }
		;

// ????????????
DefList:Def {
			$$ = new DefListAST();
            $$->list.push_back(unique_ptr<DefAST>($1));
		}				
		|DefList COMMA Def {
			$$ = $1;
            $$->list.push_back(unique_ptr<DefAST>($3));
		}
		;

// ??????
Def:	ID Arrays ASSIGN InitVal {
			$$ = new DefAST();
			$$->id = unique_ptr<string>($1);
			$$->arrays.swap($2->list);
			$$->initVal = unique_ptr<InitValAST>($4);
		}
        |ID ASSIGN InitVal {
			$$ = new DefAST();
			$$->id = unique_ptr<string>($1);
			$$->initVal = unique_ptr<InitValAST>($3);
        }
        |ID Arrays {
            $$ = new DefAST();
            $$->id = unique_ptr<string>($1);
            $$->arrays.swap($2->list);
        }
        |ID {
            $$ = new DefAST();
            $$->id = unique_ptr<string>($1);
        }
		;

// ??????
Arrays: LB Exp RB {
			$$ = new ArraysAST();
			$$->list.push_back(unique_ptr<AddExpAST>($2));
		}
        |Arrays LB Exp RB {
			$$ = $1;
			$$->list.push_back(unique_ptr<AddExpAST>($3));
		}
		;


// ?????????????????????
InitVal: Exp {
			$$ = new InitValAST();
			$$->exp = unique_ptr<AddExpAST>($1);
		}		
		|LC RC	{
			$$ = new InitValAST();
		}	
		|LC InitValList RC {
			$$ = new InitValAST();
			$$->initValList.swap($2->list);
		}	
		;

// ????????????
InitValList:InitValList COMMA InitVal {
			$$ = $1;
			$$->list.push_back(unique_ptr<InitValAST>($3));
		}
		|InitVal {
			$$  = new InitValListAST();
			$$->list.push_back(unique_ptr<InitValAST>($1));
		}
		;

// ????????????
FuncDef: BType ID LP FuncFParamList RP Block {
			$$ = new FuncDefAST();
			$$->funcType = $1;
			$$->id = unique_ptr<string>($2);
			$$->funcFParamList.swap($4->list);
			$$->block = unique_ptr<BlockAST>($6);
		}
       	|BType ID LP RP Block {
			$$ = new FuncDefAST();
			$$->funcType = $1;
			$$->id = unique_ptr<string>($2);
			$$->block = unique_ptr<BlockAST>($5);
		}
        |VoidType ID LP FuncFParamList RP Block {
			$$ = new FuncDefAST();
			$$->funcType = $1;
			$$->id = unique_ptr<string>($2);
			$$->funcFParamList.swap($4->list);
			$$->block = unique_ptr<BlockAST>($6);
		}
       	|VoidType ID LP RP Block {
			$$ = new FuncDefAST();
			$$->funcType = $1;
			$$->id = unique_ptr<string>($2);
			$$->block = unique_ptr<BlockAST>($5);
		}
		;

VoidType: VOID {
			$$ = TYPE_VOID;
		}
		;

// ??????????????????
FuncFParamList: FuncFParam {
				$$ = new FuncFParamListAST();
				$$->list.push_back(unique_ptr<FuncFParamAST>($1));
			}	
			|FuncFParamList COMMA FuncFParam {
				$$ = $1;
				$$->list.push_back(unique_ptr<FuncFParamAST>($3));
			}	
			;

// ????????????
FuncFParam:	 BType ID {
				$$ = new FuncFParamAST();
				$$->bType = $1;
				$$->id = unique_ptr<string>($2);
				$$->isArray = false;
			}
			|BType ID LB RB	{
				$$ = new FuncFParamAST();
				$$->bType = $1;
				$$->id = unique_ptr<string>($2);
				$$->isArray = true;
			}
			|BType ID LB RB Arrays {
				$$ = new FuncFParamAST();
				$$->bType = $1;
				$$->id = unique_ptr<string>($2);
				$$->isArray = true;
				$$->arrays.swap($5->list);
			}	
			;

// ?????????
Block:	 LC RC {
			$$ = new BlockAST();
		}
		|LC BlockItemList RC {
			$$ = new BlockAST();
			$$->blockItemList.swap($2->list);
		}	
		;

// ??????????????????
BlockItemList:BlockItem	{
				$$ = new BlockItemListAST();
				$$->list.push_back(unique_ptr<BlockItemAST>($1));
			}
			|BlockItemList BlockItem {
				$$ = $1;
				$$->list.push_back(unique_ptr<BlockItemAST>($2));
			}		
			;

// ????????????
BlockItem:	 Decl {
				$$ = new BlockItemAST();
				$$->decl = unique_ptr<DeclAST>($1);
			}
			|Stmt {
				$$ = new BlockItemAST();
				$$->stmt = unique_ptr<StmtAST>($1);
			}	
			;

// ???????????????type????????????????????????Stmt
Stmt:	 SEMICOLON	{
			$$ = new StmtAST();
			$$->sType = SEMI;
		}				
		|LVal ASSIGN Exp SEMICOLON {
			$$ = new StmtAST();
			$$->sType = ASS;
			$$->lVal = unique_ptr<LValAST>($1);
			$$->exp = unique_ptr<AddExpAST>($3);
		}
		|Exp SEMICOLON {
			$$ = new StmtAST();
			$$->sType = EXP;
			$$->exp = unique_ptr<AddExpAST>($1);
		}				
    	|CONTINUE SEMICOLON	{
			$$ = new StmtAST();
			$$->sType = CONT;
		}	
    	|BREAK SEMICOLON {
			$$ = new StmtAST();
			$$->sType = BRE;
		}	
    	|Block {
			$$ = new StmtAST();
			$$->sType = BLK;
			$$->block = unique_ptr<BlockAST>($1);

		}
        |ReturnStmt {
			$$ = new StmtAST();
			$$->sType = RET;
			$$->returnStmt = unique_ptr<ReturnStmtAST>($1);

		}
        |SelectStmt {
			$$ = new StmtAST();
			$$->sType = SEL;
			$$->selectStmt = unique_ptr<SelectStmtAST>($1);
		}
        |IterationStmt {
			$$ = new StmtAST();
			$$->sType = ITER;
			$$->iterationStmt = unique_ptr<IterationStmtAST>($1);
		}
		;

//????????????
SelectStmt:	IF LP Cond RP Stmt %prec LOWER_THEN_ELSE {
				$$ = new SelectStmtAST();
				$$->cond = unique_ptr<LOrExpAST>($3);
				$$->ifStmt = unique_ptr<StmtAST>($5);
			}
			|IF LP Cond RP Stmt ELSE Stmt {
				$$ = new SelectStmtAST();
				$$->cond = unique_ptr<LOrExpAST>($3);
				$$->ifStmt = unique_ptr<StmtAST>($5);
				$$->elseStmt = unique_ptr<StmtAST>($7);
			}   
			;

//????????????
IterationStmt:  WHILE LP Cond RP Stmt {
					$$ = new IterationStmtAST();
					$$->cond = unique_ptr<LOrExpAST>($3);
					$$->stmt = unique_ptr<StmtAST>($5);
				}
                ;
//????????????
ReturnStmt:	RETURN Exp SEMICOLON {
				$$ = new ReturnStmtAST();
				$$->exp = unique_ptr<AddExpAST>($2);
			}
            |RETURN SEMICOLON {
				$$ = new ReturnStmtAST();
			}
            ;
// ?????????
Exp:	AddExp {
			$$ = $1;
		}
		;

// ???????????????
Cond:	LOrExp {
			$$ = $1;
		}
		;

// ???????????????
LVal:	ID {
			$$ = new LValAST();
			$$->id = unique_ptr<string>($1);
		}
		|ID Arrays {
			$$ = new LValAST();
			$$->id = unique_ptr<string>($1);
			$$->arrays.swap($2->list);
		}
		;

// ???????????????
PrimaryExp:	 LP Exp RP {
				$$ = new PrimaryExpAST();
				$$->exp = unique_ptr<AddExpAST>($2);
				
			}
			|LVal {
				$$ = new PrimaryExpAST();
				$$->lval = unique_ptr<LValAST>($1);
				
			}	
			|Number	{
				$$ = new PrimaryExpAST();
				$$->number = unique_ptr<NumberAST>($1);
				
			}		
			;

// ??????
Number:	 INT {
			$$ = new NumberAST();
			$$->isInt = true;
			$$->intval = $1;
			
		}		
   		|FLOAT {
			$$ = new NumberAST();
			$$->isInt = false;
			$$->floatval = $1;
			
		}		
   		;

// ???????????????
UnaryExp:	 PrimaryExp	{
				$$ = new UnaryExpAST();
				$$->primaryExp = unique_ptr<PrimaryExpAST>($1);
				
			}					
			|Call {
				$$ = new UnaryExpAST();
				$$->call = unique_ptr<CallAST>($1);
				
			}
			|UnaryOp UnaryExp {
				$$ = new UnaryExpAST();
				$$->op = $1;
				$$->unaryExp = unique_ptr<UnaryExpAST>($2);
			}		
			;

//????????????
Call:ID LP RP {
		$$ = new CallAST();
		$$->id = unique_ptr<string>($1);
		
	}
	 |ID LP FuncCParamList RP {
		$$ = new CallAST();
		$$->id = unique_ptr<string>($1);
		$$->funcCParamList.swap($3->list);
		
	 }
	 ;	

// ???????????????,?????????????????????????????????????????????????????????
UnaryOp: ADD {
            $$ = UOP_ADD;
		}	
    	|MINUS {
            $$ = UOP_MINUS;
		}
    	|NOT {
            $$ = UOP_NOT;
		}	
		;

// ???????????????
FuncCParamList: Exp {
				$$ = new FuncCParamListAST();
				$$->list.push_back(unique_ptr<AddExpAST>($1));
			}
			|FuncCParamList COMMA Exp {
				$$ = (FuncCParamListAST*) $1;
				$$->list.push_back(unique_ptr<AddExpAST>($3));
			}
			;
				
//??????????????????
MulExp:	 UnaryExp {
			$$ = new MulExpAST();
			$$->unaryExp = unique_ptr<UnaryExpAST>($1);
			
		}		
		|MulExp MUL UnaryExp {
			$$ = new MulExpAST();
			$$->mulExp = unique_ptr<MulExpAST>($1);
			$$->op = MOP_MUL;
			$$->unaryExp = unique_ptr<UnaryExpAST>($3);
			
		}	
		|MulExp DIV UnaryExp {
			$$ = new MulExpAST();
			$$->mulExp = unique_ptr<MulExpAST>($1);
			$$->op = MOP_DIV;
			$$->unaryExp = unique_ptr<UnaryExpAST>($3);
			
		}	
		|MulExp MOD UnaryExp {
			$$ = new MulExpAST();
			$$->mulExp = unique_ptr<MulExpAST>($1);
			$$->op = MOP_MOD;
			$$->unaryExp = unique_ptr<UnaryExpAST>($3);
			
		}	
		;

// ???????????????
AddExp:	 MulExp	{
			$$ = new AddExpAST();
			$$->mulExp = unique_ptr<MulExpAST>($1);
			
		}			
		|AddExp ADD MulExp {
			$$ = new AddExpAST();
			$$->addExp = unique_ptr<AddExpAST>($1);
			$$->op = AOP_ADD;
			$$->mulExp = unique_ptr<MulExpAST>($3);
			
		}
		|AddExp MINUS MulExp {
			$$ = new AddExpAST();
			$$->addExp = unique_ptr<AddExpAST>($1);
			$$->op = AOP_MINUS;
			$$->mulExp = unique_ptr<MulExpAST>($3);
			
		}
		;

// ???????????????
RelExp:	 AddExp	{
			$$ = new RelExpAST();
			$$->addExp = unique_ptr<AddExpAST>($1);
			
		}				
		|RelExp GTE AddExp{
			$$ = new RelExpAST();
			$$->relExp = unique_ptr<RelExpAST>($1);
			$$->op = ROP_GTE;
			$$->addExp = unique_ptr<AddExpAST>($3);
			
		}  //??????????????????????????????????????????$2???
		|RelExp LTE AddExp{
			$$ = new RelExpAST();
			$$->relExp = unique_ptr<RelExpAST>($1);
			$$->op = ROP_LTE;
			$$->addExp = unique_ptr<AddExpAST>($3);
			
		}  //??????????????????????????????????????????$2???
		|RelExp GT AddExp {
			$$ = new RelExpAST();
			$$->relExp = unique_ptr<RelExpAST>($1);
			$$->op = ROP_GT;
			$$->addExp = unique_ptr<AddExpAST>($3);
			
		}  //??????????????????????????????????????????$2???
		|RelExp LT AddExp {
			$$ = new RelExpAST();
			$$->relExp = unique_ptr<RelExpAST>($1);
			$$->op = ROP_LT;
			$$->addExp = unique_ptr<AddExpAST>($3);
			
		}  //??????????????????????????????????????????$2???
		;

// ??????????????????
EqExp:	 RelExp	{
			$$ = new EqExpAST();
			$$->relExp = unique_ptr<RelExpAST>($1);
			
		}				
		|EqExp EQ RelExp{
			$$ = new EqExpAST();
			$$->eqExp = unique_ptr<EqExpAST>($1);
			$$->op = EOP_EQ;
			$$->relExp = unique_ptr<RelExpAST>($3);
			
		} 	
		|EqExp NEQ RelExp{
			$$ = new EqExpAST();
			$$->eqExp = unique_ptr<EqExpAST>($1);
			$$->op = EOP_NEQ;
			$$->relExp = unique_ptr<RelExpAST>($3);
			
		} 	
		;

// ??????????????????
LAndExp: EqExp {
			$$ = new LAndExpAST();
			$$->eqExp = unique_ptr<EqExpAST>($1);
			
		}		
		|LAndExp AND EqExp {
			$$ = new LAndExpAST();
			$$->lAndExp = unique_ptr<LAndExpAST>($1);
			$$->eqExp = unique_ptr<EqExpAST>($3);
		} 	
		;

// ??????????????????
LOrExp:	 LAndExp {
			$$ = new LOrExpAST();
			$$->lAndExp = unique_ptr<LAndExpAST>($1);
			
		}				
		|LOrExp OR LAndExp {
			$$ = new LOrExpAST();
			$$->lOrExp = unique_ptr<LOrExpAST>($1);
			$$->lAndExp = unique_ptr<LAndExpAST>($3);
			
		} 	
		;
%%

void yyerror(const char* fmt) {
    printf("line:%d\tcolumn:%d\n", yylloc.first_line,yylloc.first_column);
    printf("ERROR: %s\n", fmt);
}

