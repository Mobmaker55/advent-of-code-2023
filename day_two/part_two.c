#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum_bag(const Bag bag) {
    return bag.red + bag.green + bag.blue;
}

int power_bag(const Bag bag) {
    return bag.red * bag.green * bag.blue;
}

//if the game is within bounds return true
int handle_game_two(char input[]) {
    char *save;
    const char s_hand[2] = ";";
    Bag ret = {0,0,0};

    char* hand = strtok_r(input, s_hand, &save);
    while (hand != NULL) {
        const Bag baggy = get_color_count(hand);
        if (baggy.red > ret.red) {
            ret.red = baggy.red;
        }
        if (baggy.green > ret.green) {
            ret.green = baggy.green;
        }
        if (baggy.blue > ret.blue) {
            ret.blue = baggy.blue;
        }
        hand = strtok_r(NULL, s_hand, &save);
    }
    return power_bag(ret);
}

int part_two_game(char input[]) {
    const char s_game[2] = ":";
    char *save;
    strtok_r(input, s_game, &save);
    char* data = strtok_r(NULL, s_game, &save);
    return handle_game_two(data);
}

void day_two_two() {
    char * line = NULL;
    size_t len = 0;
    FILE* fptr = fopen("/home/othember/CLionProjects/advent-of-code/day_two/input.txt", "r");
    int sum = 0;

    while (getline(&line, &len, fptr) != -1) {
        line[strlen(line)-1] = '\0';
        sum += part_two_game(line);
    }
    printf("\nSum: %d", sum);
}
//
// Created by othember on 12/2/23.
//
