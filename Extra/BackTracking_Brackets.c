#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateParenthesisUtil(int n, int open, int close, char* str, int pos) {
    // Base Case: If the current position is 2n, print the string
    if (pos == 2 * n) {
        str[pos] = '\0'; // Null terminate
        printf("%s\n", str);
        return;
    }

    // If we can add an open bracket, do so
    if (open < n) {
        str[pos] = '(';
        generateParenthesisUtil(n, open + 1, close, str, pos + 1);
    }

    // If we can add a closing bracket
    if (close < open) {
        str[pos] = ')';
        generateParenthesisUtil(n, open, close + 1, str, pos + 1);
    }
}

void generateParenthesis(int n) {
    char* str = (char*)malloc(sizeof(char) * (2 * n + 1));
    generateParenthesisUtil(n, 0, 0, str, 0);
    free(str);
}

int main() {
    int n;
    printf("Enter number of pairs of parentheses: ");
    scanf("%d", &n);
    printf("All combinations of well-formed parentheses:\n");
    generateParenthesis(n);
    return 0;
}
