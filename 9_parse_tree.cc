#include <stdio.h>
     #include <stdlib.h>
     #include <ctype.h>
     char next;
     void E(void);void T(void);
     void S(void);void F(void);
     void error(int);void scan(void);
     void enter(char);
     void leave(char);
     void spaces(int);
     int level = 0;



    //The main should always be very simple
    //First scan the string
    //second check for end of string reached , if yes success and if not error.

    //P ---> E '#'
    int main(void){
       printf("Input:");
       scan();  E();
       if (next != '#') error(1);
       else printf("***** Successful parse *****\n");
    }

    //E ---> T {('+'|'-') T}
    void E(void){
       enter('E');
       T();
       while (next == '+' || next == '-') {
          scan();
          T();
       }
       leave('E');
    }


    //T ---> S {('*'|'/') S}
    void T(void)
    {
       enter('T');  S();
       while (next == '*' || next == '/') {
          scan(); S();
       }
       leave('T');
    }

    //S ---> F '^' S | F
    void S(void)
    {
       enter('S'); F();
       if (next == '^') {
          scan();  S();
       }
       leave('S');
    }

    //F ---> char | '(' E ')'
    void F(void)
    {
       enter('F');
       if (isalpha(next)) 
       { 
           scan();
       }
       else if (next == '(') {
          scan(); E();
          if (next == ')')
              scan();
          else
              error(2);
       }
       else { 
          error(3);
       }
       leave('F');
    }
    //Scan the entire input
    void scan(void){
       while (isspace(next = getchar()));
    }

    void error(int n)
    {
       printf("\n*** ERROR: %i\n", n);
       exit(1);
    }

    void enter(char name)
    {
       spaces(level++);
       printf("+-%c\n", name);
    }

    void leave(char name)
    {
      spaces(--level);
      printf("+-%c\n", name);

    }
    //TO display the parse tree
    void spaces(int local_level)
    {
       while (local_level-- > 0)
       printf("| ");
    }