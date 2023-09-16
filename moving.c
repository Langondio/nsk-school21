#include <stdio.h>

/*
    Initialization
*/
int width = 80;
int height = 25;
int player_1_pos = 12;
int player_2_pos = 12;
int ball_x = 40;
int ball_y = 13;
int direction = 1;

void render();
void move_player(char action);

int main(void) {
    char start;
    printf("Control game:\n");
    printf("\t player 1: `a` - move up, `z` - move down\n");
    printf("\t player 2: `k` - move up, `m` - move down\n");
    printf("Enter space to start game...");
    scanf("%c", &start);
    if (start == ' ') {
        render();
        while (1) {
            char action = getchar();
            if (action == 'q') {
                break;
            }
            move_player(action);
        }
        printf("Game over");
    }
    return 0;
}

void render() {
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            if (h == 0 || h == height - 1) {
                printf("-"); // render walls
            } else if (w == 0 && (h == player_1_pos - 1 || h == player_1_pos || h == player_1_pos + 1)) {
                printf("|"); // render player 1
            } else if (w == width - 1 && (h == player_2_pos - 1 || h == player_2_pos || h == player_2_pos + 1)) {
                printf("|"); // render player 2
            } else if (w == ball_x && h == ball_y) {
                printf("*"); // render ball
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move_player(char action) {
    switch (action) {
        case 'a':
            player_1_pos--;
            render();
            break;
        case 'z':
            player_1_pos++;
            render();
            break;
        case 'k':
            player_2_pos--;
            render();
            break;
        case 'm':
            player_2_pos++;
            render();
            break;
        default:
            break;
    }
}
void move_ball_x() {

}
void move_ball_y() {

}