%option noyywrap yylineno

%{

	#include <stdio.h>
	#include <malloc.h>
	#include <string.h>
	#include "cpm.h"

	/* These defines responsible for keeping track after the columns
		and printing the code */
	#define HANDLE_COLUMN column = next_column; next_column += strlen(yytext)
	#define TRCK_COL_N_PRINT HANDLE_COLUMN; fprintf(yyout, "%s", yytext)

	char* proc_reserved(char* s);

	static int next_column = 1;
	int column = 1;

%}

LETTER [a-zA-Z]
DIGIT [0-9]
%x comment

%%
"/*"									  { BEGIN(comment); }
<comment>[^*]*
<comment>"*/"						  { BEGIN(0); }
"break"								  { TRCK_COL_N_PRINT; return BREAK  ; }
"case"								  { TRCK_COL_N_PRINT; return CASE   ; }
"const"								  { TRCK_COL_N_PRINT; return CONST  ; }
"default"							  { TRCK_COL_N_PRINT; return DEFAULT; }
"do"									  { TRCK_COL_N_PRINT; return DO     ; }
"else"								  { TRCK_COL_N_PRINT; return ELSE   ; }
"end"									  { TRCK_COL_N_PRINT; return END    ; }
"for"									  { TRCK_COL_N_PRINT; return FOR    ; }
"if"									  { TRCK_COL_N_PRINT; return IF     ; }
"int"									  { TRCK_COL_N_PRINT; return INT    ; }
"main"								  { TRCK_COL_N_PRINT; return MAIN   ; }
"print"								  { TRCK_COL_N_PRINT; return PRINT  ; }
"real"								  { TRCK_COL_N_PRINT; return REAL   ; }
"read"								  { TRCK_COL_N_PRINT; return READ   ; }
"start"								  { TRCK_COL_N_PRINT; return START  ; }
"string"								  { TRCK_COL_N_PRINT; return STRING ; }
"switch"								  { TRCK_COL_N_PRINT; return SWITCH ; }
"till"								  { TRCK_COL_N_PRINT; return TILL   ; }
"then"								  { TRCK_COL_N_PRINT; return THEN   ; }
"var"									  { TRCK_COL_N_PRINT; return VAR    ; }
"while"								  { TRCK_COL_N_PRINT; return WHILE  ; }
"("|")"|"{"|"}"|","|":"|";"|"!" { return *proc_reserved(yytext); }
{LETTER}({LETTER}|{DIGIT}){0,8} { TRCK_COL_N_PRINT;
											 yylval.sval = strdup(yytext);
											 return id;
										  }
{DIGIT}+								  { TRCK_COL_N_PRINT;
											 yylval.nval.ival = atoi(yytext);
											 yylval.nval.type = I;
											 return num;
										  }
{DIGIT}+"."{DIGIT}*				  { TRCK_COL_N_PRINT;
											 yylval.nval.fval = atof(yytext);
											 yylval.nval.type = F;
											 return num;
										  }
"=="									  { TRCK_COL_N_PRINT;
											 yylval.op = EQUAL;
											 return relop;
										  }
"!="									  { TRCK_COL_N_PRINT;
											 yylval.op = NOT_EQUAL;
											 return relop;
										  }
"<"									  { TRCK_COL_N_PRINT;
											 yylval.op = LESS;
											 return relop;
										  }
">"									  { TRCK_COL_N_PRINT;
											 yylval.op = MORE;
											 return relop;
										  }
">="									  { TRCK_COL_N_PRINT;
											 yylval.op = GREATER_EQUAL;
											 return relop;
										  }
"<="									  { TRCK_COL_N_PRINT;
											 yylval.op = LESS_EQUAL;
											 return relop;
										  }
"+"									  { TRCK_COL_N_PRINT;
											 yylval.op = PLUS;
											 return addop;
										  }
"-"									  { TRCK_COL_N_PRINT;
											 yylval.op = MINUS;
											 return addop;
										  }
"*"									  { TRCK_COL_N_PRINT;
											 yylval.op = MUL;
											 return mulop;
										  }
"/"									  { TRCK_COL_N_PRINT;
											 yylval.op = DIV;
											 return mulop;
										  }
":="									  { TRCK_COL_N_PRINT;
											 yylval.op = ASSIGN;
											 return assignop;
										  }
"||"									  { TRCK_COL_N_PRINT;
											 yylval.op = OR;
											 return orop;
										  }
"&&"									  { TRCK_COL_N_PRINT;
											 yylval.op = AND;
											 return andop;
										  }
\"([a-zA-Z|.|,|!|?|" "|0-9])*\" { TRCK_COL_N_PRINT;
											 yylval.sval = strdup(yytext);
											 return sentence;
										  }
.										  { TRCK_COL_N_PRINT; }
\n										  { TRCK_COL_N_PRINT;
											 next_column = 1;
											 fprintf(yyout, "%d: ", yylineno);
										  }
%%

char* proc_reserved(char* s)
{
	TRCK_COL_N_PRINT;
	return s;
}