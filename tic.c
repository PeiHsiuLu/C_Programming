#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int Player = 1;
char mark;
int win_player1 = 0;
int win_player2 = 0;

int checkwin() {
    if (square[1] == square[2] && square[2] == square[3]) {
        return 1;
    } else if (square[4] == square[5] && square[5] == square[6]) {
        return 1;
    } else if (square[7] == square[8] && square[8] == square[9]) {
        return 1;
    } else if (square[1] == square[4] && square[4] == square[7]) {
        return 1;
    } else if (square[2] == square[5] && square[5] == square[8]) {
        return 1;
    } else if (square[3] == square[6] && square[6] == square[9]) {
        return 1;
    } else if (square[1] == square[5] && square[5] == square[9]) {
        return 1;
    } else if (square[3] == square[5] && square[5] == square[7]) {
        return 1;
    } else {
        return -1;
    }
}

void drawboard() {
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[1], square[2], square[3]);
    printf("     |     |     \n");
    printf("-----|-----|-----\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
    printf("     |     |     \n");
    printf("-----|-----|-----\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
    printf("     |     |     \n");
}

void regulation() {
    printf("\n\n");
    printf("\t\t\033[1m\033[33m 歡迎來玩井字遊戲！\033[0m\033[0m\n\n");
    printf("\033[31m遊戲規則：\033[0m\n");
    printf("\033[31m1. 遊戲由雙方各自輪流進行遊戲，每次玩家各自用所選定的記號填入特定方格中。\033[0m\n");
    printf("\033[31m2. 玩家在選擇方格時，只能選擇 1-9 的數字，若是選到其他玩家已填入的格子或是選擇不相干的數值，則視為本回合該玩家棄權。\033[0m\n");
    printf("\033[31m3. 遊戲採三戰兩勝制，玩家先取得兩次勝利者，即為勝出遊戲。否則將會持續進行遊戲(直到100輪結束，若還未有玩家取得兩勝，則該遊戲視為平手作結)\033[0m\n");
    printf("\033[31m4. 玩得開心才是最重要的！！！\033[0m\n");
    printf("\n\n\033[3m按Enter以開始遊戲... \033[0m\n");
    getchar();
    system("clear");
}

int main() {
    system("clear");
    regulation();
    int count = 1;  // 記錄總遊戲輪數

    while (count <= 100) {
        int n = 0; // 每輪遊戲中回合數
        while (n < 9) { // 每場遊戲最多 9 回合
            system("clear");
            printf("\033[33m第%d輪遊戲\033[0m\n\n", count);
            printf("玩家1 (O)、玩家2 (X)\n\n");
            drawboard();

            char selection;
            printf("玩家%d，請選擇這回合要選擇的位置：", Player);
            scanf(" %c", &selection);  // 解決輸入換行符號的問題

            mark = (Player == 1) ? 'O' : 'X';

            if (selection == '1' && square[1] == '1') {
                square[1] = mark;
            } else if (selection == '2' && square[2] == '2') {
                square[2] = mark;
            } else if (selection == '3' && square[3] == '3') {
                square[3] = mark;
            } else if (selection == '4' && square[4] == '4') {
                square[4] = mark;
            } else if (selection == '5' && square[5] == '5') {
                square[5] = mark;
            } else if (selection == '6' && square[6] == '6') {
                square[6] = mark;
            } else if (selection == '7' && square[7] == '7') {
                square[7] = mark;
            } else if (selection == '8' && square[8] == '8') {
                square[8] = mark;
            } else if (selection == '9' && square[9] == '9') {
                square[9] = mark;
            } else {
                printf("無效輸入！請選擇有效位置。\n");
                sleep(1);
                continue;
            }

            n++;  // 回合數加一
            drawboard();

            int result = checkwin();
            if (result == 1) {
                printf("本輪玩家%d勝利！\n", Player);
                if (Player == 1) {
                    win_player1++;
                } else {
                    win_player2++;
                }
                printf("目前玩家1勝利次數： %d\n", win_player1);
                printf("目前玩家2勝利次數： %d\n", win_player2);
                sleep(1);
  
                break; // 結束本輪遊戲
            }else if(n==9){
                printf("本輪無玩家勝出，各位再接再厲！\n");
                sleep(1);
            }

            Player = (Player == 1) ? 2 : 1;  // 切換玩家
        }
        

        if (win_player1 == 2 || win_player2 == 2) {
            printf("玩家%d取得勝利！恭喜玩家%d！\n", (win_player1 == 2) ? 1 : 2, (win_player1 == 2) ? 1 : 2);
            break;
        }

        if (count == 100) {
            printf("100輪已結束，未有玩家取得二勝，遊戲平手！\n");
            break;
        }

        // 重置棋盤
        for (int i = 1; i <= 9; i++) {
            square[i] = '0' + i;
        }

        count++;
    }

    return 0;
}
