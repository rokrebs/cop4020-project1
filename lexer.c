/***************************************************************
  Student Name:Rocio Krebs
  File Name:lexer.c
  Assignment number 1

  This file implements the required functions needed to run the 
  lexical analyzer and inserting IDs into the symbol table
***************************************************************/
#include "lexer.h"

// This function open a file for reading
// and starts reading the contect
void initLexer(char *name) {
  file = fopen(name, "r");
  lineNr = 1;
  lookahead = lexan();
}

// This function reads char by char the file
// and depending of the char it will store them
// in an array to store in the table symbol.
// This function will return the value of a char or
// the type of lexema.
int lexan() {
  memset(idLexeme, 0, MAX);
  memset(numLexeme, 0, MAX);
  int idLen = 0;
  while (1) {
    ch = fgetc(file);
    if (ch == ' ' || ch == '\t') {
      ; // do nothing
    } else if (ch == '\n') {
      lineNr++;
    } else if (ch == '~') {
      while (ch != '\n') {
        // read the comment until finding \n
        ch = fgetc(file);
      }
      ungetc(ch, file);
    } else if (isdigit(ch)) {
      while (isdigit(ch)) {
        // inser into numLexeme
        strncat(numLexeme, &ch, 1);
        ch = fgetc(file);
      }
      ungetc(ch, file);
      return NUM;
    } else if (isalpha(ch)) {
      while (isalpha(ch) || isdigit(ch) || ch == '.' || ch == '_') {
        // insert into idLExeme
        strncat(idLexeme, &ch, 1);
        idLen++;
        ch = fgetc(file);
      }
      // check if id is already in the table
      type = lookup(idLexeme);
      if (type == NOT_FOUND) {
        // insert idLExeme to the  table
        type = insertEntry(idLexeme, lineNr, idLen);
      }
      ungetc(ch, file);
      return type;
    } else if (ch == EOF) {
      return DONE;
    } else {
      return ch;
    }
  }
}