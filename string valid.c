#include <stdio.h>
#include <stdbool.h>

bool isValidString(const char *str) {
    while (*str) {
        if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9')))
            return false;
        str++;
    }
    return true;
}

int main() {
    const char *inputString = "HelloWorld123";
    if (isValidString(inputString)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is NOT valid.\n");
    }
    return 0;
}
