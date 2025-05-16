#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculateDeviation(const char* str, int* leftDeviation, int* rightDeviation) {
    int len = strlen(str);
    int deviation = 0;
    int maxDeviation = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'a') {
            deviation++;
        } else if (str[i] == 'b') {
            deviation--;
        }

        if (deviation > maxDeviation) {
            maxDeviation = deviation;
        }
    }

    *leftDeviation = maxDeviation;

    deviation = 0;
    maxDeviation = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == 'a') {
            deviation++;
        } else if (str[i] == 'b') {
            deviation--;
        }

        if (deviation > maxDeviation) {
            maxDeviation = deviation;
        }
    }

    *rightDeviation = maxDeviation;
}

int main() {
    const char* testString = "abbaabbbaaa";
    int left, right;

    calculateDeviation(testString, &left, &right);

    printf("Left-most deviation: %d\n", left);
    printf("Right-most deviation: %d\n", right);

    return 0;
}
