#include <stdio.h>

int maxDigit(int n) {
    int max = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit > max)
            max = digit;
        n = n / 10;
    }
    return max;
}

int main() {
    char str[100];
    printf("Enter the number: ");
    scanf("%s", str);

    int max = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] - '0' > max)
            max = str[i] - '0';
    }

    printf("Minimum number of deci-binary numbers needed: %d\n", max);
    return 0;
}
