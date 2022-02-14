/***************************************************************
  Student Name:Rocio Krebs
  File Name:lexer.h
  Assignment number 1

  This is the header file with the required funcions needed to run the lexic analyzer and inserting IDs into the symbol table
***************************************************************/
#ifndef LEXER
#define LEXER
#include "table.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 500
FILE *file;
int lineNr;
char ch;
int type;
int lookahead;

// functions
int lexan(void);
void initLexer(char *name);
char idLexeme[MAX];
char numLexeme[MAX];

#endif
