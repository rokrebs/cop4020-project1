/***************************************************************
  Student Name:Rocio Krebs
  File Name: table.h
  Assignment number 1

  This is the header for table.c
***************************************************************/
#ifndef TABLE
#define TABLE
#include "lexer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// required values for the table
#define MAX 500
#define ID 300
#define NUM 301
#define BEGIN 400
#define END 401
#define NOT_FOUND -1
#define DONE 800
#define START_U 801
#define END_U 802
#define TWO_U 803

char end[MAX];
char start[MAX];
char under[MAX];

// This is the struc used to create
// the symble table, linkedList
struct Entry {
  char value[MAX];
  int typ;
  struct Entry *next;
  int line;
};

struct Entry *head;
struct Entry *newEntry;

// function
void initSymbolTable(void);
int insertEntry(char *lexema, int line, int size);
int lookup(char *lexem);
int getTyp(char *lexema, int size);
void free_table();
void printTable();

#endif