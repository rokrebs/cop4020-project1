#  Semantic checker and code generator
# Project Description

You will implement this program in the C programming language. You must provide a makefile and your program must run on the ssh server. We will add integer variable declarations immediately after the begin token at the start of the program:

begin <br />
  int x, y, z, b; <br />
  x = y + z; <br />
  z = b - 5; <br />
end <br />

Declarations should also work as multi-line constructs: <br />

begin <br />
  int x; <br />
  int y; <br />
  int z, b; <br />
  x = (y + z) * (z - asdf_9); <br />
  z = b - 5; <br />
end <br />

Your program will do checks to ensure that variables have been declared before they are used and we will have two additional error messages "undefined variable <varname>" and "illegal redefinition <varname>." If the program is syntactically and semantically correct, it will generate low-level, register-based code for the assignment statements as shown below. <br />

As in project 1, your program will read multiple assignment statements from a text file specified by a command-line argument. Each statement will be terminated with a semicolon (;). Your group of assignment statements will again be delimited by the "begin"  and "end" reserved words. The intent is that legal programs will be free format, meaning that indentations do not matter, multiple statements are permitted on a line,  a statement may appear on multiple lines (with no continuation character). Finally, as before, your program must include a capability to provide comments. Comments will be single line and they will start with a tilda:

~ this is a comment

You will parse the statements (hopefully all this is good from Project 1), keeping track of where you are in the string, and report whether or not the input program is legal. Your program will report either

- The program is legal - output is in file <filename>. <br />
- Line <integer> contains error <errormsg> 
             (missing ']', missing ')', illegal number, illegal identifier, unterminated comment, undeclared variable, etc)

If all statements are legal, you will generate an assembly-like code loading registers, doing computations and storing register results. You will also show the postfix version of the expression. The output will go into a file with the file name of the input file and a file extension  .out. So, if the input file were named legal1.in, the generated code would go to a file named legal1.out. If the program is illegal for any reason, you do not need to generate code.

You will use the lexical analyzer and parser from Project 1. You will add variable declaration, semantic checks, and code generation capabilities to that project.

Input and output: 

Given this as the input file: 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ~ This is a comment 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

begin  <br />
  int ghgghg, abc_edef; <br />
  int a, b, c, abcd; <br />
  int qwerty; <br />
  ghgghg = (abc_edef * b); <br />
  qwerty=(6 * (a / b)); <br />
  qwerty=((6 - abcd)*(a + b)); <br />
  xyz = (9*8*7*6)/(a+b+c); <br />
end. <br />


Your program should produce output similar to this: 

Compiling legal1.in 
R0 = abc_edef 
R1 = b 
R0 = R0 * R1 
ghgghg = R0 
*****[abc_edef,b,*]***** 
R0 = 6
R1 = a
R2 = b
R1 = R1 / R2
R0 = R0 * R1
qwerty = R0
*****[6,a,b,/,*]*****
R0 = 6
R1 = abcd
R0 = R0 - R1
R1 = a
R2 = b
R1 = R1 + R2
R0 = R0 * R1
qwerty = R0
*****[6,abcd,-,a,b,+,*]*****
R0 = 9
R1 = 8
R0 = R0 * R1
R1 = 7
R0 = R0 * R1
R1 = 6
R0 = R0 * R1
R1 = a
R2 = b
R1 = R1 + R2
R2 = c
R1 = R1 + R2
R0 = R0 / R1
xyz = R0
*****[9,8,*,7,*,6,*,a,b,+,c,+,/]*****

For the following illegal program, output would be as indicated:

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ~ This is a comment
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
begin
  int ghgghg, abc_edef;
  abc = (abc_edef * b);
end.

Error line 6: variable abc is undefined.<br />
