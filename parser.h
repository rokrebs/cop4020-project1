/***************************************************************
  Student Name: Rocio Krebs
  File Name: parser.h
  Assignment number 1

  This the heard for parser.c
***************************************************************/
#ifndef PARSER
#define PARSER
#include "lexer.h"
#include <stdio.h>

void parse(void);
void AssignStmt(void);
void expression(void);
void term(void);
void factor(void);
void match(int id);
void printError(char c);

#endif