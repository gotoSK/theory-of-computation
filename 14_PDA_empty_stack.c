#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK 100
#define MAX_STATES 10
#define MAX_SYMBOLS 10

typedef struct {
    char symbol;
    char stack[MAX_STACK];
    int top;
} Stack;

typedef struct {
    int nextState;
    char inputSymbol;
    char popSymbol;
    char pushSymbol;
} Transition;

typedef struct {
    Transition transitions[MAX_STATES][MAX_SYMBOLS];
    int initialState;
    int numStates;
    int numSymbols;
} PDA;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push a symbol onto the stack
void push(Stack* stack, char symbol) {
    stack->top++;
    stack->stack[stack->top] = symbol;
}

// Function to pop a symbol from the stack
char pop(Stack* stack) {
    char symbol = stack->stack[stack->top];
    stack->top--;
    return symbol;
}

// Function to process a string with the PDA
bool processString(const PDA* pda, const char* str) {
    Stack stack;
    initStack(&stack);

    int currentState = pda->initialState;
    int i = 0;

    while (str[i] != '\0') {
        char inputSymbol = str[i];

        bool transitionFound = false;

        for (int j = 0; j < pda->numSymbols; j++) {
            Transition transition = pda->transitions[currentState][j];

            if (transition.inputSymbol == inputSymbol && transition.popSymbol == stack.stack[stack.top]) {
                currentState = transition.nextState;
                pop(&stack);
                if (transition.pushSymbol != 'E') {
                    push(&stack, transition.pushSymbol);
                }
                transitionFound = true;
                break;
            }
        }

        if (!transitionFound) {
            return false;  // Invalid transition, string not accepted
        }

        i++;
    }

    // Process the remaining input symbols with epsilon transitions
    bool epsilonTransitionFound = true;

    while (epsilonTransitionFound) {
        epsilonTransitionFound = false;

        for (int j = 0; j < pda->numSymbols; j++) {
            Transition transition = pda->transitions[currentState][j];

            if (transition.inputSymbol == 'E' && transition.popSymbol == stack.stack[stack.top]) {
                currentState = transition.nextState;
                pop(&stack);
                if (transition.pushSymbol != 'E') {
                    push(&stack, transition.pushSymbol);
                }
                epsilonTransitionFound = true;
                break;
            }
        }
    }

    // Check if the stack is empty
    return isStackEmpty(&stack);
}

int main() {
    PDA pda;

    // Define the PDA transitions
    pda.initialState = 0;
    pda.numStates = 3;
    pda.numSymbols = 2;

    pda.transitions[0][0].nextState = 1;
    pda.transitions[0][0].inputSymbol = '0';
    pda.transitions[0][0].popSymbol = 'E';
    pda.transitions[0][0].pushSymbol = 'E';

    pda.transitions[1][0].nextState = 1;
    pda.transitions[1][0].inputSymbol = '0';
    pda.transitions[1][0].popSymbol = 'E';
    pda.transitions[1][0].pushSymbol = '0';

    pda.transitions[1][1].nextState = 2;
    pda.transitions[1][1].inputSymbol = '1';
    pda.transitions[1][1].popSymbol = '0';
    pda.transitions[1][1].pushSymbol = 'E';

    const char* testString = "000111";

    if (processString(&pda, testString)) {
        printf("The string is accepted by the PDA.\n");
    } else {
        printf("The string is not accepted by the PDA.\n");
    }

    return 0;
}
