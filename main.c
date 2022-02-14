/***************************************************************
  Student Name: Rocio Krebs
  File Name: main.c
  Assignment number 2

  This is the main function that takes a file name when is called. Once an file name is entered the funcion will run the  check.
***************************************************************/
#include "lexer.h"
#include "parser.h"
#include "table.h"
#include <stdio.h>

int main(int argc, char *argvc[]) {
  if (argc == 2) {
    initSymbolTable();   // initilize symboltable
    initLexer(argvc[1]); // initialize lexer analyzer
    printf("\nCompiling %s\n", argvc[1]);
    parse();
  }
  return 0;
}