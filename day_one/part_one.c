#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int first_last(const char str[]) {
    int first = -1;
    int last = -1;
    for (int i = 0; i < strlen(str); ++i) {
        const int strnum = (int)(str[i]);
        if (48 <= strnum && strnum <= 57) {
            if (first < 0) {
                first = strnum-48;
            }
            last = strnum-48;
        }
    }
    return (first*10)+last;
}

void day_one_one() {
    char * line = NULL;
    size_t len = 0;
    FILE* fptr = fopen("/home/othember/CLionProjects/advent-of-code/day_one/day_one.txt", "r");
    int sum = 0;

    while (getline(&line, &len, fptr) != -1) {
        sum += first_last(line);
    }

    printf("Total: %d\n", sum);

}

