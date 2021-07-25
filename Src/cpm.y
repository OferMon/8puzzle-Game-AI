%{

	#include <malloc.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <ctype.h>
	#include "symcpm.h"
	#include "strsplit.h"

	#define NHASH 9997
	#define MAX_FILE_NAME 50
	#define YYERROR_VERBOSE 1
	
	typedef struct symTbls
	{
		symcpm symTblScope[NHASH];
		struct symTbls* nextSymTbl;
	} symTbl;

	typedef enum
	{
		redef_e,
		typesmismtch_e,
		undec_e,
		argsmismtch_e,
		zero_e,
		opermismtch_e,
		constasgn_e,
		swexpr_e
	} ERRORS;

	typedef enum
	{
		if_e,
		while_e,
		for_e,
		dowhile_e
	} BMODE;

	void yyerror(const char* str);
	void mError(const int typeOfError, const symcpm* var, const char* str);
	void emit(FILE* file, const char* str);
	void emitDec(const symcpm* tempVar);
	void freeSymbolTable();

	extern int yylex (void);
	extern int yylineno, column;
	extern char* yytext;
	symTbl* listOfSymTbl;
	static int currLevelNum = 1;
	FILE* errorsLog, *mipsOut, *tempOutBody, *tempOutHeader;
	char* variablsTemp[NHASH];
	char* fileName1, *saveStmt;
	BMODE mode;
	/* The global variables below responsible for different labels
		in the code, in situations where there are multiple "if" statments,
		while loops etc.. and if there are inner statements.
		(like if inside if etc..) */
	int numOfVar = 0, numOfSent = 1, numOfLoops = 1, iRegs = 0, fRegs = 0;
	int numOfIf = 0, numOfJ = 0, numOfCond = 2, numOfTemps = 0, numOfW = 0;
	int numOfFor = 0, numOfDW = 0, numOfSw = 0;
	static bool gProg = true;

%}

%union
{
	struct 
	{
		enum
		{
			I,
			F,
			S
		} type;
		union
		{
			float fval;
			int   ival;
		};
	} nval;
   char* sval;
   enum {PLUS, MINUS, MUL, DIV, EQUAL, NOT_EQUAL, LESS, MORE, GREATER_EQUAL, LESS_EQUAL, ASSIGN, OR, AND} op;
}

%token <nval> num
%token <op>   relop addop mulop assignop orop andop
%token <sval> sentence id
%token BREAK CASE CONST DEFAULT DO ELSE END FOR IF INT MAIN PRINT REAL READ START STRING SWITCH TILL THEN VAR WHILE

%type <sval> type list step
%type <nval> factor term expression

%left addop
%left mulop
%left orop
%left andop
%left relop
%right assignop

%%
program         : MAIN id START { emit(tempOutHeader, "#Noam Hadad & Ofer Montano\n.data"); } declarations { emit(tempOutBody, "\n.text"); } stmtlist END
						| error {gProg=false; yyerrok;}
;
declarations    : VAR declarlist cdecl 
						|
;
declarlist      : declarlist { numOfVar = 0; } decl 
				      | { numOfVar = 0; } decl 
;
decl            : type ':' list 
			  	      {
							/* Iterate on the array and assign the type
								to the variables */
							symcpm* tempVar;
							while(numOfVar != -1)
							{
								tempVar = lookup(variablsTemp[numOfVar]);
								tempVar->type = $1;
								emitDec(tempVar);
								free(variablsTemp[numOfVar--]);
							}
						}
						| type error list {gProg=false; yyerrok;}
;
list            : id 
						{
							symcpm* tempVar = lookup($1);
							if(tempVar->isDecleared)
							{
								gProg = false;
								mError(redef_e, tempVar, NULL);
							}
							tempVar->isDecleared = true;
							tempVar->isConst = false;
							
							/* Add variable name to an array to assign
								type to them later on */
							variablsTemp[numOfVar++] = strdup($1);
						}
						',' list
						| id ';'
						  {
								symcpm* tempVar = lookup($1);
								if(tempVar->isDecleared)
								{
									gProg = false;
									mError(redef_e, tempVar, NULL);
								}
								tempVar->isDecleared = true;
								tempVar->isConst = false;
								variablsTemp[numOfVar] = strdup($1);
						  }
						| id error list {gProg=false; yyerrok;}
;
type	          : INT { $$ = "int"; } 
				      | REAL { $$ = "real"; }
						| STRING { $$ = "string"; }
;
cdecl           : CONST type id assignop num';' cdecl 
						{
							symcpm* tempVar = lookup($3);
							if(tempVar->isDecleared)
							{
								gProg = false;
								mError(redef_e, tempVar, NULL);
							}
							tempVar->isDecleared = true;
							tempVar->type = $2;
							tempVar->isConst = true;

							/* If the variable has a type of string or he is int
								but the num is float- raise an error */
							if(!strcmp(tempVar->type, "string") || (!strcmp(tempVar->type, "int") && $5.type == F))
							{
								gProg = false;
								mError(typesmismtch_e, tempVar, "real");
							}
							if($5.type == F)
								tempVar->value.rval = $5.fval;
							else
								tempVar->value.ival = $5.ival;
							emitDec(tempVar);
						} |
;
stmtlist        : stmtlist stmt 
						|
;
stmt            : assignment_stmt
						| id assignop sentence';' 
						  {
								symcpm* tempVar = lookup($1);
								if(!tempVar->isDecleared)
								{
									gProg = false;
									mError(undec_e, tempVar, NULL);
								}
								else if(strcmp(tempVar->type, "string"))
								{
									gProg = false;
									mError(typesmismtch_e, tempVar, "string");
								}
								else
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									sprintf(s, "sentc%d: .asciiz %s", numOfSent, $3);
									emit(tempOutHeader, s);
									sprintf(s, "li $t0, 0\nlb $t1, sentc%d($t0)\nloop%d:\n\tsb $t1, %s($t0)\n\taddi $t0, $t0, 1\n\tlb $t1, sentc%d($t0)\n\tbne $t1, \'\\0\', loop%d", numOfSent, numOfLoops, tempVar->name, numOfSent, numOfLoops);
									numOfSent++;
									numOfLoops++;
									emit(tempOutBody, s);
									free(s);
								}
						  }
						| id error sentence ';' {gProg=false; yyerrok;}
						| control_stmt 
						| read_stmt						
						| write_stmt				
						| stmt_block
;
write_stmt      : PRINT'('expression')'';'
						{
							char* s = (char *) malloc(sizeof(char) * 256);
							if($3.type == I)
									sprintf(s, "li $v0, 1\nmove $a0, $t%d\nsyscall", iRegs - 1);
							else if($3.type == F)
								sprintf(s, "li $v0, 2\nmov.s $f12, $f%d\nsyscall", fRegs - 1);
							else
								sprintf(s, "li $v0, 4\nsyscall");
							emit(tempOutBody, s);
							free(s);
						}
						| PRINT'('sentence')'';' 
						  {
								char* s = (char *) malloc(sizeof(char) * 256);
								sprintf(s, "sentc%d: .asciiz %s", numOfSent, $3);
								emit(tempOutHeader, s);
								sprintf(s, "li $v0, 4\nla $a0, sentc%d\nsyscall", numOfSent);
								numOfSent++;
								emit(tempOutBody, s);
								free(s);
						  }
						| PRINT '('error')' ';' {gProg=false; yyerrok;}
						| PRINT '('error ';' {gProg=false; yyerrok;}
;
read_stmt       : READ'('id')'';'
						{
							symcpm* tempVar = lookup($3);
							if(!tempVar->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar, NULL);
							}
							else
							{
								char* s = (char*) malloc(sizeof(char)* 256);
								if(!strcmp(tempVar->type, "int"))
									sprintf(s, "li $v0, 5\nsyscall\nsw $v0, %s", tempVar->name);
								else if(!strcmp(tempVar->type, "real"))
									sprintf(s, "li $v0, 6\nsyscall\ns.s $f0, %s", tempVar->name);
								else
									sprintf(s, "li $v0, 8\nla $a0, %s\nli $a1, 256\nsyscall", tempVar->name);
								emit(tempOutBody, s);
								free(s);
							}
						}
						| error ';' {gProg=false; yyerrok;}
;
assignment_stmt : id assignop expression';'
						{
							symcpm* tempVar = lookup($1);
							if(!tempVar->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar, NULL);
							}

							/* If the variable or the expression is string and the other
								one is not, raise an error */
							else if((!strcmp(tempVar->type, "string") && $3.type != S) || (strcmp(tempVar->type, "string") && $3.type == S))
							{
									gProg = false;
									mError(typesmismtch_e, tempVar, "string");
							}
							else if(!strcmp(tempVar->type, "int") && $3.type == F)
							{
								gProg = false;
								mError(typesmismtch_e, tempVar, "real");
							}

							// If it is a const variable, raise an error
							else if(tempVar->isConst)
							{
								gProg = false;
								mError(constasgn_e, tempVar, NULL);
							}
							else
							{
								char* s = (char *) malloc(sizeof(char) * 256);
								if(!strcmp(tempVar->type, "int") && $3.type == I)
								{
									sprintf(s, "sw $t%d, %s", iRegs - 1, tempVar->name);
									iRegs--;
								}
								else if(!strcmp(tempVar->type, "real") && $3.type == F)
								{
									sprintf(s, "s.s $f%d, %s", fRegs - 1, tempVar->name);
									fRegs--;
								}
								else if(!strcmp(tempVar->type, "real") && $3.type == I)
								{
									sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\ns.s $f%d, %s", iRegs - 1, fRegs - 1, fRegs - 1, fRegs - 1, fRegs - 1, tempVar->name);
									iRegs--;
									fRegs--;
								}
								else
								{
									sprintf(s, "la $t%d, %s\nloop%d:\nlb $t%d, 0($a0)\nsb $t%d, 0($t%d)\naddi $a0, $a0, 1\naddi $t%d, $t%d, 1\nbne $t%d, \'\\0\', loop%d",
									iRegs, tempVar->name, numOfLoops, iRegs + 1, iRegs + 1, iRegs, iRegs, iRegs, iRegs + 1, numOfLoops);
									numOfLoops++;
								}
								emit(tempOutBody, s);
								free(s);
							}
						}
						| id error expression';' {gProg=false; yyerrok;}
						| id assignop error ';' {gProg=false; yyerrok;}
;
control_stmt    : IF '('boolexpr')' { fprintf(tempOutBody, "beq $t%d, $0, ELSE%d\n", iRegs - 1, numOfIf++); } THEN stmt { fprintf(tempOutBody, "j L%d\n", numOfJ); } ELSE { fprintf(tempOutBody, "ELSE%d:\n", --numOfIf); } stmt { fprintf(tempOutBody, "L%d:\n", numOfJ++); }
						| WHILE { fprintf(tempOutBody, "wLoop%d:\n", numOfW); } '('boolexpr')' { fprintf(tempOutBody, "beq $t%d, $0, ewLoop%d\n", iRegs - 1, numOfW++); }
						  stmt_block 
						  { 
								numOfW--;
								fprintf(tempOutBody, "j wLoop%d\newLoop%d:\n", numOfW, numOfW);
						  }
						| FOR '('assignment_stmt { fprintf(tempOutBody, "fLoop%d:\n", numOfFor); } boolexpr';' { fprintf(tempOutBody, "beq $t%d, $0, efLoop%d\n", iRegs - 1, numOfFor++); } step')' stmt 
						  { 
								emit(tempOutBody, $8);
								numOfFor--;
								fprintf(tempOutBody, "j fLoop%d\nefLoop%d:\n", numOfFor, numOfFor);
						  }
						| DO { fprintf(tempOutBody, "dLoop%d:\n", numOfDW++); } stmt_block TILL'('boolexpr')'
						  {
								fprintf(tempOutBody, "bne $t%d, $0, dLoop%d\n", iRegs - 1, --numOfDW);
						  }
						| switch
						| error '\n' {gProg=false; yyerrok;}
						| error THEN {gProg=false; yyerrok;}
;
stmt_block      : '{' stmtlist '}'
;
switch          : SWITCH '('choice')' '{' cases '}'
;
choice          : id
						{
							symcpm* tempVar = lookup($1);
							if(!tempVar->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar, NULL);
							}
							if(!strcmp(tempVar->type, "string") || !strcmp(tempVar->type, "real"))
							{
								gProg = false;
								mError(swexpr_e, NULL, "float/string");
							}
							char* s = (char *) malloc(sizeof(char) * 256);
							snprintf(s, 256, "lw $t%d, %s", iRegs, $1);
							iRegs++;
							emit(tempOutBody, s);
							free(s);
						}
						| num
						  {
								// The choice cant be from type float
								if($1.type == F)
								{
									gProg = false;
									mError(swexpr_e, NULL, "float");
								}
								else
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									snprintf(s, 256, "li $t%d, %d", iRegs, $1.ival);
									iRegs++;
									emit(tempOutBody, s);
									free(s);
								}
						  }					
;
cases           : CASE num':'
						{
							if($2.type == F)
							{
								gProg = false;
								mError(swexpr_e, NULL, "float");
							}
							char* s = (char *) malloc(sizeof(char) * 256);
							snprintf(s, 256, "li $t%d, %d\nbne $t%d, $t%d, C%d_COND", iRegs, $2.ival, iRegs - 1, iRegs, numOfCond);
							iRegs--;
							emit(tempOutBody, s);
							free(s);
						}
						stmtlist BREAK';'
						{
							char* s = (char *) malloc(sizeof(char) * 256);
							snprintf(s, 256, "j eSwtch%d\nC%d_COND:", numOfSw, numOfCond++);
							emit(tempOutBody, s);
							free(s);
						}
						cases 
						| DEFAULT':' stmtlist { fprintf(tempOutBody, "eSwtch%d:\n", numOfSw++); }
						| CASE num error '\n' {gProg=false; yyerrok;}
						| DEFAULT error stmtlist {gProg=false; yyerrok;}
;
step            : id assignop id addop num
						{
							symcpm* tempVar1 = lookup($1);
							symcpm* tempVar2 = lookup($3);

							/* If one of the variables is not declared or is a string
								or left side is const, raise an error */
							if(!tempVar1->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar1, NULL);
							}
							if(!tempVar2->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar2, NULL);
							}
							if(!strcmp(tempVar1->type, "string") || (!strcmp(tempVar1->type, "int") && strcmp(tempVar2->type, "int")))
							{
								gProg = false;
								mError(typesmismtch_e, tempVar1, tempVar2->type);
							}
							if(tempVar1->isConst)
							{
								gProg = false;
								mError(constasgn_e, tempVar1, NULL);
							}
							$$ = (char *) malloc(sizeof(char) * 256);
							char* s = (char *) malloc(sizeof(char) * 256);
							sprintf($$, "li $t%d, %d\nlw $t%d, %s\n", iRegs, $5.ival, iRegs + 1, tempVar2->name);
							if($4 == PLUS)
								sprintf(s, "add $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, $1);
							else
								sprintf(s, "sub $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, $1);
							iRegs--;
							strcat($$, s);
							free(s);
					   }
						| id assignop id mulop num
						  {
							symcpm* tempVar1 = lookup($1);
							symcpm* tempVar2 = lookup($3);
							if(!tempVar1->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar1, NULL);
							}
							if(!tempVar2->isDecleared)
							{
								gProg = false;
								mError(undec_e, tempVar2, NULL);
							}
							if(!strcmp(tempVar1->type, "string") || (!strcmp(tempVar1->type, "int") && strcmp(tempVar2->type, "int")))
							{
								gProg = false;
								mError(typesmismtch_e, tempVar1, tempVar2->type);
							}
							if(tempVar1->isConst)
							{
								gProg = false;
								mError(constasgn_e, tempVar1, NULL);
							}
							$$ = (char *) malloc(sizeof(char) * 256);
							char* s = (char *) malloc(sizeof(char) * 256);
							sprintf($$, "li $t%d, %d\nlw $t%d, %s\n", iRegs, $5.ival, iRegs + 1, tempVar2->name);
							if($4 == MUL)
								sprintf(s, "mul $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, $1);
							else
								sprintf(s, "div $t%d, $t%d, $t%d\nsw $t%d, %s", iRegs + 1, iRegs + 1, iRegs, iRegs + 1, $1);
							iRegs--;
							strcat($$, s);
							free(s);
						  }
						| id error id addop num {gProg=false; yyerrok;}
						| id assignop id error num {gProg=false; yyerrok;}
;
boolexpr        : boolexpr orop boolterm
						{
							fprintf(tempOutBody, "or $t%d, $t%d, $t%d\n", iRegs - 2, iRegs - 2, iRegs - 1);
							iRegs--;
						}
						| boolterm
						| error '\n' {gProg=false; yyerrok;}
;
boolterm        : boolterm andop boolfactor
						{	
							fprintf(tempOutBody, "and $t%d, $t%d, $t%d\n", iRegs - 2, iRegs - 2, iRegs - 1);
							iRegs--;
						}
						| boolfactor
;
boolfactor      : '!' '('boolfactor')' { fprintf(tempOutBody, "xori $t%d, $t%d, 1\n", iRegs - 1, iRegs - 1); }
						| expression
						  {
								/* If the expression is a string, in this point it means
									that its in $a0. Because we relop between two expressions
									if the other expression is also a string, 
									we need to move that value to another register. */
								if($1.type == S)
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									sprintf(s, "move $t%d, $a0", iRegs);
									iRegs++;
									emit(tempOutBody, s);
									free(s);
								}
						  }
						  relop  expression
						  {
								char* s = (char *) malloc(sizeof(char) * 256);
								switch($3)
								{
									case EQUAL:
										if($1.type == S && $4.type == S)
										{

											/* We divided the sprintf to a couple of statements only
												because it is more readable and easy to track the arguments */
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "seq $t%d, $t%d, $t%d\nbeq $t%d, $0, eLoop%d", iRegs + 2, iRegs + 1, iRegs, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nseq $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);											
										}
										else if($1.type == S || $4.type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "==");
										}
										else
										{
											if($1.type == I && $4.type == I)
											{
												sprintf(s, "seq $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(($1.type == I && $4.type == F) || ($1.type == F && $4.type == I))
											{
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nseq $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											}
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nseq $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case NOT_EQUAL:
										if($1.type == S && $4.type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sne $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs + 1, iRegs, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);		
										}
										else if($1.type == S || $4.type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "!=");
										}
										else
										{
											if($1.type == I && $4.type == I)
											{
												sprintf(s, "sne $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(($1.type == I && $4.type == F) || ($1.type == F && $4.type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsne $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsne $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}		
									break;
									case LESS:
										if($1.type == S && $4.type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sgt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs + 1, iRegs, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if($1.type == S || $4.type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "<");
										}
										else
										{
											if($1.type == I && $4.type == I)
											{
												sprintf(s, "slt $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(($1.type == I && $4.type == F) || ($1.type == F && $4.type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nslt $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nslt $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case GREATER_EQUAL:
										if($1.type == S && $4.type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sgt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs, iRegs + 1, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs + 1, numOfLoops, iRegs + 2, iRegs, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if($1.type == S || $4.type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "<=");
										}
										else
										{
											if($1.type == I && $4.type == I)
											{
												sprintf(s, "sge $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(($1.type == I && $4.type == F) || ($1.type == F && $4.type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsge $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsge $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case MORE:
										if($1.type == S && $4.type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "sgt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs, iRegs + 1, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs + 1, numOfLoops, iRegs + 2, iRegs, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if($1.type == S || $4.type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, ">");
										}
										else
										{
											if($1.type == I && $4.type == I)
											{
												sprintf(s, "sgt $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(($1.type == I && $4.type == F) || ($1.type == F && $4.type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsgt $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsgt $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
									case LESS_EQUAL:
										if($1.type == S && $4.type == S)
										{
											sprintf(s, "loop%d:\nlb $t%d, 0($t%d)\nlb $t%d, 0($a0)", numOfLoops, iRegs, iRegs - 1, iRegs + 1);
											emit(tempOutBody, s);
											sprintf(s, "slt $t%d, $t%d, $t%d\nbne $t%d, $0, eLoop%d", iRegs + 2, iRegs, iRegs + 1, iRegs + 2, numOfLoops);
											emit(tempOutBody, s);
											sprintf(s, "addi $a0, $a0, 1\naddi $t%d, $t%d, 1", iRegs - 1, iRegs - 1);
											emit(tempOutBody, s);
											sprintf(s, "bne $t%d, \'\\0\', loop%d\nsne $t%d, $t%d, \'\\0\'\neLoop%d:\nmove $t%d, $t%d", iRegs, numOfLoops, iRegs + 2, iRegs + 1, numOfLoops, iRegs - 1, iRegs + 2);
											numOfLoops++;
											emit(tempOutBody, s);
											free(s);
										}
										else if($1.type == S || $4.type == S)
										{
											gProg = false;
											mError(opermismtch_e, NULL, "<=");
										}
										else
										{
											if($1.type == I && $4.type == I)
											{
												sprintf(s, "sle $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
												iRegs--;
											}
											else if(($1.type == I && $4.type == F) || ($1.type == F && $4.type == I))
												sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsle $t%d, $t%d, $0", iRegs - 1, fRegs, fRegs, fRegs, fRegs - 1, fRegs - 1, fRegs, iRegs, fRegs - 1, iRegs - 1, iRegs);
											else
											{
												sprintf(s, "sub.s $f%d, $f%d, $f%d\nmfc1 $t%d, $f%d\nsle $t%d, $t%d, $0", fRegs - 2, fRegs - 2, fRegs - 1, iRegs, fRegs - 2, iRegs, iRegs);
												iRegs++;
												fRegs--;
											}
											emit(tempOutBody, s);
											free(s);
										}
									break;
								}
						  }
;
expression      : expression addop term
						{
							$$.type = F;
							if($1.type == S || $3.type == S)
							{
									gProg = false;
									mError(opermismtch_e, NULL, "+/-");
							}
							else
							{
								char* s = (char *) malloc(sizeof(char) * 256);
								if($2 == PLUS)
								{
									if($1.type == F && $3.type == F)
									{
										sprintf(s, "add.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if($1.type == F || $3.type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nadd.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										$$.type = I;
										sprintf(s, "add $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
									}
									emit(tempOutBody, s);
									free(s);
								}
								else
								{
									if($1.type == F && $3.type == F)
									{
										sprintf(s, "sub.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if($1.type == F || $3.type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nsub.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										$$.type = I;
										sprintf(s, "sub $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
									}
									emit(tempOutBody, s);
									free(s);
								}
							}
						}
						| term { $$.type = $1.type; }
						| error '\n' {gProg=false; yyerrok;}
;
term				 : term mulop factor
						{
							$$.type = F;
							if($1.type == S || $3.type == S)
							{
									gProg = false;
									mError(opermismtch_e, NULL, "*//");
							}
							else
							{
								char* s = (char *) malloc(sizeof(char) * 256);
								if($2 == MUL)
								{
									if($1.type == F && $3.type == F)
									{
										sprintf(s, "mul.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if($1.type == F || $3.type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\nmul.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										$$.type = I;
										sprintf(s, "mul $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
									}
									emit(tempOutBody, s);
									free(s);
								}	
								else if(($3.type == F && !$3.fval) || ($3.type == I && !$3.ival))
								{
										gProg = false;
										mError(zero_e, NULL, NULL);
								}
								else
								{
									if($1.type == F && $3.type == F)
									{
										sprintf(s, "div.s $f%d, $f%d, $f%d", fRegs - 2, fRegs - 2, fRegs - 1);
										fRegs--;
									}
									else if($1.type == F || $3.type == F)
										sprintf(s, "mtc1 $t%d, $f%d\ncvt.s.w $f%d, $f%d\ndiv.s $f%d, $f%d, $f%d", iRegs - 1, fRegs +1, fRegs +1, fRegs +1, fRegs - 1, fRegs + 1, fRegs - 1);
									else
									{
										sprintf(s, "div $t%d, $t%d, $t%d", iRegs - 2, iRegs - 2, iRegs - 1);
										iRegs--;
										$$.type = I;
									}
									emit(tempOutBody, s);
									free(s);
								}
							}	
						}
						| factor { $$.type = $1.type; }
						| error mulop term {gProg=false; yyerrok;}
;
factor			 : '(' expression ')' { $$.type = $2.type; }
						| id
						  {
								symcpm* tempVar = lookup($1);
								if(!tempVar->isDecleared)
								{
									gProg = false;
									mError(undec_e, tempVar, NULL);
								}
								else
								{
									char* s = (char *) malloc(sizeof(char) * 256);
									if(!strcmp(tempVar->type, "real"))
									{
										sprintf(s, "l.s $f%d, %s", fRegs, $1);
										fRegs++;
										$$.type = F;
									}
									else if(!strcmp(tempVar->type, "int"))
									{
										sprintf(s, "lw $t%d, %s", iRegs, $1);
										iRegs++;
										$$.type = I;
									}
									else
									{
										sprintf(s, "la $a0, %s", $1);
										$$.type = S;
									}
									emit(tempOutBody, s);
									free(s);
								}
						  }
						| num 
						  {
								char* s = (char *) malloc(sizeof(char) * 256);
								if($1.type == F)
								{
									//sprintf(s, "tempF%d: .float %.2f", numOfTemps, $1.fval);
									//emit(tempOutHeader, s);
									sprintf(s, "tempF%d: .float %.2f\nl.s $f%d, tempF%d", numOfTemps, $1.fval, fRegs, numOfTemps);
									numOfTemps++;
									fRegs++;
								}
								else
								{
									sprintf(s, "li $t%d, %d", iRegs, $1.ival);
									iRegs++;
								}
								$$.type = $1.type;
								emit(tempOutBody, s);
								free(s);
						  }
;
%%

int main(int argc, char* argv[])
{

	// Check if user entered enough parameters
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "Please provide an input file!");
		return 1;
	}
	char** inputFile = strsplit(argv[1], ".");

	// Check if the input file is of type cpl or CPL
	if(!inputFile || strcmp(strlwr(inputFile[1]), "cpl"))
	{
		free(inputFile);
		fprintf(stderr, "%s\n", "Please provide a .cpl or .CPL file!");
		return 1;
	}
	extern FILE* yyin, *yyout;
	errorsLog = fopen("errorsLog.txt", "w+");
	yyin = fopen(argv[1], "r");
	char* fileName = strtok(argv[1], ".");
	strcat(fileName, ".lst");
	yyout = fopen(fileName, "w");

	/* Open one file for mips .text instructions
		and one file for .data instructions */
	tempOutBody = fopen("tempOutBody.txt", "w+");
	tempOutHeader = fopen("tempOutHeader.txt", "w+");
	
	// Check if one of the files didnt opened correctly
	if(!errorsLog || !yyin || !yyout || !tempOutBody || !tempOutHeader)
	{
		free(fileName);
		free(inputFile);
		fclose(yyin);
		fclose(yyout);
		fclose(errorsLog);
		fclose(tempOutBody);
		remove("errorsLog.txt");
		remove("tempOutBody.txt");
		fprintf(stderr, "%s\n", "Unexpected open file error!");
		return 1;
	}

	fprintf(yyout, "Noam Hadad & Ofer Montano\n%d: ", 1);

	// Initialize a list of symbol tables
	listOfSymTbl = (symTbl*) malloc(sizeof(symTbl));
	listOfSymTbl->nextSymTbl = NULL;

	yyparse();

	// Copy errors occurred during parsing
	rewind(errorsLog);
	char ch = fgetc(errorsLog);
	while (ch != EOF)
   {
		fputc(ch, yyout);
      ch = fgetc(errorsLog);
   }
	
	/* open a final mips file, copy the data and text instructions 
		to that file and delete the other files */
	strcpy(fileName, inputFile[0]);
	strcat(fileName, ".s");
	mipsOut = fopen(fileName, "w");
	if(!mipsOut)
	{
		free(fileName);
		free(inputFile);
		fclose(yyin);
		fclose(yyout);
		fclose(errorsLog);
		fclose(tempOutBody);
		fclose(tempOutHeader);
		remove("errorsLog.txt");
		remove("tempOutBody.txt");
		remove("tempOutHeader.txt");
		fprintf(stderr, "%s\n", "Unexpected open file error!");
		return 1;
	}
	rewind(tempOutHeader);
	rewind(tempOutBody);
	ch = fgetc(tempOutHeader);
	while (ch != EOF)
   {
		fputc(ch, mipsOut);
      ch = fgetc(tempOutHeader);
   }
	ch = fgetc(tempOutBody);
	while (ch != EOF)
   {
		fputc(ch, mipsOut);
      ch = fgetc(tempOutBody);
   }

	fprintf(stderr, "Noam Hadad & Ofer Montano");

	// Cleanup
	freeSymbolTable();
	fclose(errorsLog);
	fclose(tempOutBody);
	fclose(tempOutHeader);
	fclose(yyin);
	fclose(yyout);
	fclose(mipsOut);
	if(!gProg)
		remove(fileName);
	free(fileName);
	free(inputFile);
   remove("errorsLog.txt");
	remove("tempOutBody.txt");
	remove("tempOutHeader.txt");
	return 0;
}

/* This function responsible for printing the instructions to the
	different files, according to the "file" argument */
void emit(FILE* file, const char* str)
{
	fprintf(file,"%s\n", str);
}

void freeSymbolTable()
{
	int scount;
	symcpm* sp;
	while(listOfSymTbl)
	{
		scount = NHASH;
		sp = listOfSymTbl->symTblScope;
		while(--scount >= 0)
		{
			if(sp->name)
				free(sp->name);
		}
		listOfSymTbl = listOfSymTbl->nextSymTbl;
	}
}

/* This function responsible for printing instructions to .data
	file, specifically variables declarations */
void emitDec(const symcpm* tempVar)
{
	char* s = (char*) malloc(sizeof(char)* 256);
	if(!strcmp(tempVar->type, "int"))
		sprintf(s, "%s: .word %d", tempVar->name, tempVar->value.ival);
	else if(!strcmp(tempVar->type, "real"))
		sprintf(s, "%s: .float %.2f", tempVar->name, tempVar->value.rval);
	else
		sprintf(s, "%s: .space %d", tempVar->name, 256);
	emit(tempOutHeader, s);
	free(s);
}

/* This function responsible for printing lexical and parsing errors */
void yyerror(const char* str)
{
	char** errorMsg = strsplit(str, " ");
	if(!errorMsg)
		return;
	fprintf(errorsLog,"\nERROR line %d, column %d: Expected %s, found %s instead.", yylineno, column, errorMsg[5], strsplit(errorMsg[3], ",")[0]);
	free(errorMsg);
}

/* This function responsible for printing runtime errors */
void mError(const int typeOfError, const symcpm* var, const char* str)
{
	switch(typeOfError)
	{
		case redef_e:
			fprintf(errorsLog,"\nERROR \'%s %s\': redefinition. (line %d)", var->type, var->name, yylineno);
		break;
		case typesmismtch_e:
			fprintf(errorsLog,"\nERROR \':=\': types mismatch from %s to %s. (line %d)", str, var->type, yylineno);
		break;
		case undec_e:
			fprintf(errorsLog,"\nERROR \'%s\': undeclared identifier. (line %d)", var->name, yylineno);
		break;
		case argsmismtch_e:
			fprintf(errorsLog,"\nERROR \'%s\':  cannot convert argument from \'string\' to \'%s\'. (line %d)", str, var->type, yylineno);
		break;
		case zero_e:
			fprintf(errorsLog,"\nERROR: devide or mod by zero. (line %d)", yylineno);
		break;
		case opermismtch_e:
			fprintf(errorsLog,"\nERROR \'%s\': operator not defined for type \'string\'. (line %d)", str, yylineno);
		break;
		case constasgn_e:
			fprintf(errorsLog,"\nERROR \'%s\': you cannot assign to a variable that is const. (line %d)", var->name, yylineno);
		break;
		case swexpr_e:
			fprintf(errorsLog,"\nERROR : a switch expression of type \'%s\' is not valid. (line %d)", str, yylineno);
		break;
	}
}

/* This function responsible for assigning a unique index for
	variables in the symbol tables */
static unsigned symhash(char* sym)
{
	unsigned int hash = 0;
	unsigned c;
	while(c = *sym++)
		hash = hash * 9 ^ c;
	return hash;
}

/* This function responsible for searching variables in the
	list of symbol tables, if the variable does not exists
	it enters it to the symbol table */
symcpm* lookup(char* sym)
{
	symTbl* tempList = listOfSymTbl;
	symcpm* sp;
	int scount;
	while(tempList)
	{
		sp = &tempList->symTblScope[symhash(sym) % NHASH];
		scount = NHASH;
		while(--scount >= 0)
		{
			if(sp->name && !strcmp(sp->name, sym))
				return sp;
			if(!sp->name)
			{
				sp->name = strdup(sym);
				sp->isDecleared = false;
				return sp;
			}
			if(++sp >= tempList->symTblScope + NHASH)
				sp = tempList->symTblScope;
		}
		tempList = tempList->nextSymTbl;
	}
	fprintf(stderr, "%s\n", "symbol table overflow");
	abort();
}

/* This function responsible for splitting strings */
static char** _strsplit(const char* s, const char* delim, size_t* nb)
{
	void* data;
	char* _s = (char*)s;
	const char** ptrs;
	size_t
		ptrsSize,
		nbWords = 1,
		sLen = strlen( s ),
		delimLen = strlen( delim );

	while((_s = strstr(_s, delim)))
	{
		_s += delimLen;
		++nbWords;
	}
	ptrsSize = (nbWords + 1) * sizeof(char*);
	ptrs = data = malloc(ptrsSize + sLen + 1);
	if(data)
	{
		*ptrs = _s = strcpy(((char*)data) + ptrsSize, s);
		if(nbWords > 1)
		{
			while((_s = strstr(_s, delim)))
			{
				*_s = '\0';
				_s += delimLen;
				*++ptrs = _s;
			}
		}
		*++ptrs = NULL;
	}
	if(nb)
	{
		*nb = data ? nbWords : 0;
	}
	return data;
}

/* This function responsible for splitting strings */
char** strsplit(const char* s, const char* delim)
{
	return _strsplit(s, delim, NULL);
}