/***************************************************************
  Student Name: Rocio Krebs
  File Name: parser.c
  Assignment number 1

  This file contains all the required functions to parse the statements, 
  keep track of where you are in the string, and report whether or not 
  the input program is legal
***************************************************************/
#include "parser.h"
// this function will run until we finish succesfully
// or we have to finish because an error happened.
void parse() {

  if (lookahead != BEGIN) {
    printf("Line: %d syntax error expected 'begin'\n", lineNr);
    free_table();
    fclose(file);
    exit(1);
  } else {
    match(BEGIN);
    while (lookahead != DONE && lookahead != END) {
      if (lookahead != BEGIN) {
        AssignStmt();
      }
      if (lookahead == END) {
        printf("Success\n");
        printTable();
        free_table();
        fclose(file);
        exit(0);
      }
    }
  }
}

// funcion to check if the assgment operation is right
void AssignStmt() {
  match(ID);
  if (lookahead != '=') {
    printf("Line: %d syntax error expected '='\n", lineNr);
  } else {
    match(lookahead);
    expression();
    match(';');
  }
}

// function to check if the term or operation needed
// is on the file.
void match(int t) {
  if (lookahead == t)
    lookahead = lexan();
  else
    printError(t);
}

// funcion to check if the expression is correct
void expression(void) {
  term();
  while (lookahead == '+' || lookahead == '-') {
    match(lookahead);
    term();
  }
}

// function to check if a term was built proper
void term(void) {
  factor();
  while (lookahead == '*' || lookahead == '/') {
    match(lookahead);
    factor();
  }
}

// funcion to check if the factor contains the right
// experssion and if ( ) were missed.
void factor(void) {
  if (lookahead == ID)
    match(ID);
  else if (lookahead == NUM)
    match(NUM);
  else if (lookahead == '(') {
    match('(');
    expression();
    match(')');
  } else {
    free_table();
    fclose(file);
    exit(1);
  }
}

// This is a help funcion that will print out the erros and the
// line number where the errro was found.
void printError(char c) {
  if (lookahead == START_U) {
    printf("Line: %d Identifier cannot start with underscore\n", lineNr);
  } else if (lookahead == END_U) {
    printf("Line: %d Identifier cannot end with underscore\n", lineNr);
  } else if (lookahead == TWO_U) {
    printf("Line: %d Identifier has underscore followed by other underscore\n",
           lineNr);
  } else if (c == '(') {
    printf("Line: %d syntax error expected '%c'\n", lineNr, c);
  } else if (c == ')') {
    printf("Line: %d syntax error expected '%c'\n", lineNr, c);
  } else if (c == ';') {
    printf("Line: %d syntax error expected '%c'\n", lineNr, c);
  }
  free_table();
  fclose(file);
  exit(1);
}
