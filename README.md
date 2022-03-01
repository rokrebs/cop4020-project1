# cop4020-project1
# Recursive-descent Parser
# Project Description

You will implement this program in the C programming language. You must provide a makefile and your program must run on the ssh server in Linux. Your program will implement the pseudocode described in class as needed, adding, removing or editing elements as needed. Your application must take one command-line argument, the name of the file to be checked. The file will contain a number of assignment statements. Each assignment statement will be terminated by a semicolon (;). Furthermore, your group of assignment statements must be delimited by the "begin"  and "end" reserved words with a dot (.) after the "end" token. The intent is that programs will be free format, meaning that indentations do not matter, multiple statements are permitted on a line,  a statement may appear on multiple lines (with no continuation character). Finally, your program must include a capability to provide comments. Comments will be on a single line and they will start with a tilda:
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ~ This is a comment 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 You will parse the statements, keeping track of where you are in the string, and report whether or not the input program is legal. Your program will report either

- The program is legal: "success".
- Line <integer> contains error <errormsg> (missing ']', missing ')', expected assignment operator, expected operator, etc)
  
  If all statements are legal, you must report all the identifiers that were used. Therefore, you will need at symbol table. Your symboltable can be implemented however you wish, but a hashtable is the logical choice. If the program is illegal, you do not need to list the identifiers.

You will implement both a lexical analyzer and a parser. These are clearly different functions and they should be implemented in different physical files. The lexical analyzer will simply decide what comes next in the token stream and return it. The parser will decide if the token is OK at that spot.

In your program, you will need to have an

    int lookahead;

that always holds the next token.
 
  The structure of Number and Identifier

You should detect whether or not a character string comprises an integer.

These are valid numbers:
     123, 1234567, 456789, etc ...
 

A legal <identifier> will start with a letter followed by combinations of letters, numbers, and underscores, subject to the following two rules:

 

1. You cannot have consecutive underscores

2. An identifier cannot end with an underscore.

These are valid identifiers:
      e123, e, qwert5yuio, a_b_7

These are not:

      e__7, abc_,  7yght, _iuh
  
 Typical  Statements (legal and illegal)

a = b; <br />
a=af+= <br />
a=; <br />
a_5 = 2; <br />
6 = j; <br />
a=d* <br />
dd5=((3+5*8); <br />
%iii=0 <br />
a=b2-(((x_yz + 99)* abc)*d); <br />
qwerty=((6 - abcd)*(a + b)); <br />
 xyz = (9*8*7*6)/(a+b+c); <br />

A legal program

~ a typical, minimal legal program 
 
begin <br />
  qwerty=((6 - ab_cd)*(a + b)); <br />
  xyz = (9*8*7765*6)/(a+b+c); <br />
end

