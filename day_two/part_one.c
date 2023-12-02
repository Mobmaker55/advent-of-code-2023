#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/split.c"

const int max_red = 12;
const int max_green = 13;
const int max_blue = 14;

typedef struct {
    int red;
    int green;
    int blue;
} Bag;

void print_bag(Bag bag) {
    printf("Red: %d, Green: %d, Blue: %d\n", bag.red, bag.green, bag.blue);
}

Bag get_color_count(char in[]) {
    char* hand_contents = in;
    Bag ret = {0,0,0};
    char *save;
    const char s_color[2] = ",";
    const char space[2] = " ";

    char* color = strtok_r(hand_contents, s_color, &save);
    while (color != NULL) {
        char *space_save;
        const char* num = strtok_r(color, space, &space_save);
        char* color_word = strtok_r(NULL, space, &space_save);
        char color_char = color_word[strlen(color_word)-1];
        if (color_char == 'e') {
            ret.blue = atoi(num);
        }
        if (color_char == 'n') {
            ret.green = atoi(num);
        }
        if (color_char == 'd') {
            ret.red = atoi(num);
        }

        color = strtok_r(NULL, s_color, &save);
    }
    print_bag(ret);
    return ret;

}

//if the game is within bounds return true
bool handle_game(char input[]) {
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
    if (ret.red > max_red || ret.green > max_green || ret.blue > max_blue) {
        return false;
    }
    return true;
}

int get_game_info(char input[]) {
    const char s_game[2] = ":";
    int game_num = 0;
    char *game;
    char *save;
    game = strtok_r(input, s_game, &save);
    game_num = atoi(&game[5]);
    char* data = strtok_r(NULL, s_game, &save);
    if (handle_game(data)) {
        return game_num;
    }
    return 0;
}

void day_two_one() {
    char str[80] = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";

    char * line = NULL;
    size_t len = 0;
    FILE* fptr = fopen("/home/othember/CLionProjects/advent-of-code/day_two/input.txt", "r");
    int sum = 0;

    while (getline(&line, &len, fptr) != -1) {
        line[strlen(line)-1] = '\0';
        sum += get_game_info(line);
    }
    printf("\nSum: %d", sum);

    get_game_info(str);
}
