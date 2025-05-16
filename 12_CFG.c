#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUCTIONS 100
#define MAX_SYMBOLS 20

typedef struct {
    char nonTerminal;
    char production[MAX_SYMBOLS];
} Production;

typedef struct {
    Production productions[MAX_PRODUCTIONS];
    int count;
} CFG;

// Function to check if a string is derived from a CFG
bool isDerived(const CFG* grammar, const char* str, char nonTerminal) {
    if (strlen(str) == 1 && str[0] == nonTerminal) {
        return true;
    }

    for (int i = 0; i < grammar->count; i++) {
        if (grammar->productions[i].nonTerminal == nonTerminal) {
            const char* production = grammar->productions[i].production;

            if (strlen(production) == 1 && production[0] == str[0]) {
                return true;
            }

            if (strlen(production) <= strlen(str)) {
                bool valid = true;

                for (int j = 0; j < strlen(production); j++) {
                    if (production[j] != str[j]) {
                        valid = false;
                        break;
                    }
                }

                if (valid && isDerived(grammar, str + strlen(production), nonTerminal)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    CFG grammar;

    // Define the CFG productions
    grammar.count = 4;
    grammar.productions[0].nonTerminal = 'S';
    strcpy(grammar.productions[0].production, "AB");
    grammar.productions[1].nonTerminal = 'A';
    strcpy(grammar.productions[1].production, "aA");
    grammar.productions[2].nonTerminal = 'A';
    strcpy(grammar.productions[2].production, "b");
    grammar.productions[3].nonTerminal = 'B';
    strcpy(grammar.productions[3].production, "cB");

    const char* testString = "abbc";

    if (isDerived(&grammar, testString, 'S')) {
        printf("\nThe string is derived from the CFG.\n");
    } else {
        printf("\nThe string is not derived from the CFG.\n");
    }

    return 0;
}
