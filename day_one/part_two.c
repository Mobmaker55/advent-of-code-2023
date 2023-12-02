#include <stdio.h>
#include <string.h>

int word_to_num(char str[]) {
    int nums[60];
    int filled = 0;
    char* str_pointed = &str[0];
    while (strlen(str_pointed) > 0) {
        //printf("(%.3s), %s\n", str_pointed, str_pointed);
        if (!strncmp(str_pointed, "one", 3)) {
            nums[filled++] = 1;
            str_pointed += 3;
            continue;
        }
        if (!strncmp(str_pointed, "two", 3)) {
            nums[filled++] = 2;
            str_pointed += 3;
            continue;
        }
        if (!strncmp(str_pointed, "three", 5)) {
            nums[filled++] = 3;
            str_pointed += 5;
            continue;
        }
        if (!strncmp(str_pointed, "four", 4)) {
            nums[filled++] = 4;
            //str_pointed += 4;
            //i += 4;
        }
        if (!strncmp(str_pointed, "five", 4)) {
            nums[filled++] = 5;
            str_pointed += 4;
            continue;
        }
        if (!strncmp(str_pointed, "six", 3)) {
            nums[filled++] = 6;
            str_pointed += 3;
            continue;
        }
        if (!strncmp(str_pointed, "seven", 5)) {
            nums[filled++] = 7;
            str_pointed += 5;
            continue;
        }
        if (!strncmp(str_pointed, "eight", 5)) {
            nums[filled++] = 8;
            str_pointed += 5;
            continue;
        }
        if (!strncmp(str_pointed, "nine", 4)) {
            nums[filled++] = 9;
            str_pointed += 4;
            continue;
        }

        const int strnum = (int)str_pointed[0];
        if (48 <= strnum && strnum <= 57) {
            nums[filled++] = strnum-48;
        }
        str_pointed += 1;
    }
    printf("%d%d\n", nums[0], nums[filled-1]);
    int res;
    if (filled > 1) {
        res = nums[0]*10 + nums[filled-1];
    } else {
        res = nums[0];
    }

    memset(nums, 0, 4*60);
    return res;

}


void day_one_two() {
    int test = word_to_num("eightwothree");
    int more_test = word_to_num("eightxfcmkqjqxzxjvrfive");
    printf("debug: %d, %d\n", test, more_test);
    char * line = NULL;
    size_t len = 0;
    FILE* fptr = fopen("/home/othember/CLionProjects/advent-of-code/day_one/day_one.txt", "r");
    int sum = 0;

    while (getline(&line, &len, fptr) != -1) {
        line[strlen(line)-1] = '\0';
        sum += word_to_num(line);
    }
    printf("\nSum: %d", sum);
}
