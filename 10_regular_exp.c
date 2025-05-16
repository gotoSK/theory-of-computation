#include <stdio.h>

int matchRegex(const char* str) {
    if (str[0] == 'a') {
        int i = 1;
        while (str[i] == 'a' || str[i] == 'b') {
            i++;
        }
        if (str[i] == 'b' && str[i + 1] == '\0') {
            return 1;  // Matched the regular expression
        }
    }
    return 0;  // Did not match the regular expression
}

int main() {
    const char* testString = "aabb";

    if (matchRegex(testString)) {
        printf("The string matches the regular expression.\n");
    } else {
        printf("The string does not match the regular expression.\n");
    }

    return 0;
}
