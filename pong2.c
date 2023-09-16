#include <math.h>
#include <stdio.h>
int move_racket_1(char a, int racket1);
int move_racket_2(char a, int racket2);
//void render (int racket1, int racket2, int ball, int score_player_1, int score_player_2);
void render (int racket1, int racket2, int ball);
int main() {
    int racket1 = 12;
    int racket2 = 12;
    int ball = 1;
    render(racket1,racket2,ball);
    while (1) {
        char c1, c2;
        if (scanf("%c%c", &c1, &c2) == 2) {
            if (c1 == 'q' || c2 == 'q')
                break;
            racket1 += move_racket_1(c1, racket1);
            racket2 += move_racket_2(c2, racket2);
            render(racket1,racket2,ball);
        }
    }
    return 0;
    
}
int move_racket_1(char a, int racket1) {
    switch (a) {
        case 'a':
            if (racket1 - 1 <= 10) {
                racket1++;
            }
            return -1;
            break;
        case 'z':
            if (racket1 + 1 <= 24) {
                racket1--;
            }
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
int move_racket_2(char a, int racket2) {
    switch (a) {
        case 'k':
            if (racket2 - 1 <= 10) {
                racket2++;
            }
            return -1;
            break;
        case 'm':
            if (racket2 + 1 <= 24) {
                racket2--;
            }
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
void render (int racket1, int racket2, int ball){
    for (int height = 0; height < 25; height++) {
        for (int width = 0; width < 80; width++) {
            if (height == 1){
                printf("-");
            } else if (height == 2 || height == 4 || height == 3 ){
                printf(" ");
            } else if (height == 5 || height == 24) {
                printf("-");
            } else if (((height == racket1 || height == racket1 + 1 || height == racket1 - 1) && width == 0) || ((height == racket2 || height == racket2 - 1 || height == racket2 + 1) && width == 79)) {
                printf("|");
            } else if (height == 12 && width == ball) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
