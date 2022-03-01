/***************************************************************
  Student Name:Rocio Krebs
  File Name: table.c
  Assignment number 1

  This file contains the symbol table and the functionality
  of adding searching and printing its content.
***************************************************************/
#include "table.h"

// this functuons iniztialize the table.
void initSymbolTable() {
  strcpy(end, "end.");
  strcpy(start, "begin");
  strcpy(under, "-");
  insertEntry(under, 0, 0);
}

// this function insert lexemas at the end table
int insertEntry(char *lexema, int line, int size) {
  int typEntry = getTyp(lexema, size);
  newEntry = (struct Entry *)malloc(sizeof(struct Entry));
  strncpy(newEntry->value, lexema, sizeof(newEntry->value) - 1);
  newEntry->typ = typEntry;
  newEntry->next = NULL;
  newEntry->line = line;

  if (head == NULL) {
    head = newEntry;
  } else {
    struct Entry *lastEntry = head;
    while (lastEntry->next != NULL) {
      lastEntry = lastEntry->next;
    }
    lastEntry->next = newEntry;
  }
  return typEntry;
}

// this is a help function that identifies the type of the lexema
// and it will return its correct type.
int getTyp(char *lexema, int size) {
  if (strcmp(lexema, under) == 0) {
    return 0;
  }
  if (strcmp(lexema, start) == 0) {
    return BEGIN;
  } else if (strcmp(lexema, end) == 0) {
    return END;
  } else if (lexema[0] == '_') {
    return START_U;
  } else if (lexema[size - 1] == '_') {
    return END_U;
  } else {
    for (int i = 0; i < MAX - 1; i++) {
      if (lexema[i] == '_' && lexema[i + 1] == '_') {
        return TWO_U;
      }
    }
  }
  return ID;
}

// this function will find if the lexema is stored in the table
// and will return its type or an error.
int lookup(char *lexem) {
  struct Entry *current = head;
  while (strcmp(current->value, lexem) != 0) {
    if (current->next == NULL) {
      return NOT_FOUND;
    } else {
      current = current->next;
    }
  }
  return current->typ;
}

// This function print just the IDlexemas stored in the table
void printTable() {
  struct Entry *temp = head;
  while (temp != NULL) {
    if (temp->typ == ID) {
      if (temp->next->next != NULL)
        printf("%s, ", temp->value);
      else
        printf("%s\n", temp->value);
    }
    temp = temp->next;
  }
}

// this funcion is to free the space allocate each time
// a new element was added to the table
void free_table() {
  struct Entry *pNode = head, *pNext;

  while (NULL != pNode) {
    pNext = pNode->next;
    free(pNode);
    pNode = pNext;
  }
}