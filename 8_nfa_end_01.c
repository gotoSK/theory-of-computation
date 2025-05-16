#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 5
char st[SIZE];

int nfa(){
    int state=1; // '1', '2', '3'
    for(int i=0; i<SIZE; i++){
        if(st[i]=='0')
            if(st[i+1]=='0')
                state=1;
            else
                state=2;
        if(st[i]=='1' && state==2)
            state=3;
        else
            state=1;
    }
    return state;
}

int main(){
    printf("Enter your string: ");
    scanf("%s", st);
    if(nfa()==3)
        printf("Accepted!");
    else
        printf("Not accepted.");
    getch();
    return 0;
}