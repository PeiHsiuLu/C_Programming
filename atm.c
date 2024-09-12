#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <time.h>
#define PIN "1234"
int DEPOSIT = 5000;

// Disable echo for password input
void disable_echo() {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

// Enable echo after password input
void enable_echo() {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

int checkpin() {
    system("clear");
    char check_pin[20];  // Buffer to store user input
    static int failure = 0;  // Static variable to track number of login failures
    int i = 0;
    char ch;

    printf("\033[33m用戶登入\033[0m");
    printf("\n\n==================================");
    printf("\n\n請輸入您的密碼: ");

    disable_echo();  // Disable echo to hide user input

    // Read input characters one by one
    while (1) {
        ch = getchar();  // Read a character

        if (ch == '\n') {  // Enter key is pressed
            check_pin[i] = '\0';  // Null-terminate the input string
            break;
        } else if (ch == '\b' || ch == 127) {  // Handle Backspace key
            if (i > 0) {
                i--;
                printf("\b \b");  // Erase the last asterisk from the terminal
            }
        } else if (i < 19) {  // Ensure no overflow in input buffer
            check_pin[i++] = ch;  // Store the actual character in the buffer
            printf("*");  // Print asterisk to the screen for every character input
            fflush(stdout);  // Flush output buffer to ensure asterisk is displayed immediately
        }
    }

    enable_echo();  // Re-enable echo

    // Password verification
    if (strcmp(check_pin, PIN) == 0) {
        printf("\n\033[33m登入成功！\033[0m\n");
        sleep(1);
        system("clear");
        return 1;  // Return success
    } else {
        printf("\n\033[31m登入失敗！請重新輸入密碼！\033[0m\n");
        sleep(1);
        failure++;  // Increment failure count

        if (failure == 3) {
            printf("\n\033[1m\033[31m連續登入失敗3次！請15秒後再重新登入\033[0m\033[0m\n");
            sleep(2);
            for (int i = 15; i > 0; i--) {
                system("clear");
                printf("\n");
                printf("\033[33m%02d秒後可重新登入...\033[0m\n", i);
                fflush(stdout);  // Flush output buffer
                sleep(1);
            }
        } else if (failure == 5) {
            printf("\n\033[1m\033[31m連續登入失敗5次！請60秒後再重新登入！\033[0m\033[0m\n");
            sleep(2);
            for (int i = 60; i > 0; i--) {
                system("clear");
                printf("\n");
                printf("\033[33m%02d秒後可重新登入...\033[0m\n", i);
                fflush(stdout);  // Flush output buffer
                sleep(1);
            }
        } else if (failure == 10) {
            printf("\n\033[1m\033[31m連續登入失敗10次！卡片收回！若是要重新取回卡片，請洽詢門市人員協助！\033[0m\033[0m\n");
            sleep(1);
            exit(0);
        }

        return 0;  // Return failure
    }
}

// Function to check if a key is pressed
int kbhit(void) {
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

// Enter ATM screen function
void enter() {
    // Top clock display
    time_t s;
    struct tm* current_time;

    while (1) {
        system("clear");

        // Update current time each iteration
        s = time(NULL);
        current_time = localtime(&s);

        // Extract time information
        int hr = current_time->tm_hour;   // Hour
        int min = current_time->tm_min;   // Minute
        int sec = current_time->tm_sec;   // Second
        int day = current_time->tm_mday;  // Day
        int month = current_time->tm_mon + 1; // Month
        int year = current_time->tm_year + 1900; // Year

        // Print time
        printf("\033[033m%04d/%02d/%02d   %02d:%02d:%02d\033[0m", year, month, day, hr, min, sec);
        printf("\n\n==================================");
        printf("\n\n按下 Enter 鍵已開始執行交易程序... \n");
        if (kbhit()) {
            int ch = getchar();
            if (ch == '\n') {
                system("clear");
                break;  // Detected Enter key, exit loop
            }
        }
        fflush(stdout);  // Force flush buffer
        sleep(1);  // Refresh every second
    }
}

void withdrawl() {
    while (1) {
        system("clear");
        int withdrawl;
        printf("\n\n\t\t\033[33m請輸入您要取款的金額(只能是1000元的倍數,範圍在1000-100000)：(按0表示離開)\033[0m");
        scanf("%d", &withdrawl);
        if (withdrawl == 0) {
            sleep(1);
            break;
        }
        if (withdrawl % 1000 != 0 || withdrawl <= 0) {
            printf("\n\033[31m\033[1m對不起，請重新輸入1000元倍數的現金！\033[0m\033[0m");
            sleep(1);
            continue;
        }
        if (withdrawl > DEPOSIT) {
            printf("\n\033[31m\033[1m卡片餘額不足，請重新輸入1000元倍數的現金！\033[0m\033[0m");
            sleep(1);
            continue;
        }
        if (withdrawl > 100000) {
            printf("\n\033[31m\033[1m金額過大，請重新操作提取現金！\033[0m\033[0m");
            sleep(1);
            continue;
        }
        sleep(1);
        DEPOSIT -= withdrawl;
        printf("\n\n\033[33m\033[1m已提取%d元，戶頭剩餘%d元。\n", withdrawl, DEPOSIT);
        sleep(2);
        break;
    }
}

void deposit() {
    while (1) {
        system("clear");
        int dep;
        printf("\n\n\t\t\033[33m請輸入您要存取的金額(只能是1000元的倍數,範圍在1000-100000)：(按0表示離開)\033[0m");
        scanf("%d", &dep);
        if (dep == 0) {
            sleep(1);
            break;
        }
        if (dep % 1000 != 0 || dep <= 0) {
            printf("\n\033[31m\033[1m對不起，請重新存取1000元倍數的現金！\033[0m\033[0m");
            sleep(1);
            continue;
        }
        if (dep > 100000) {
            printf("\n\033[31m\033[1m金額過大，請重新操作提取現金！\033[0m\033[0m");
            sleep(1);
            continue;
        }
        sleep(1);
        DEPOSIT += dep;
        printf("\n\n\033[33m\033[1m已存取%d元，戶頭剩餘%d元。\n", dep, DEPOSIT);
        sleep(2);
        break;
    }
}

void remaining() {
    // Top clock display
    time_t s;
    struct tm* current_time;

    while (1) {
        system("clear");

        // Update current time each iteration
        s = time(NULL);
        current_time = localtime(&s);

        // Extract time information
        int hr = current_time->tm_hour;   // Hour
        int min = current_time->tm_min;   // Minute
        int sec = current_time->tm_sec;   // Second
        int day = current_time->tm_mday;  // Day
        int month = current_time->tm_mon + 1; // Month
        int year = current_time->tm_year + 1900; // Year

        // Print time
        printf("\033[033m%04d/%02d/%02d   %02d:%02d:%02d\033[0m", year, month, day, hr, min, sec);
        printf("\n\n==================================");
        printf("\n\n卡片餘額%d元 \n", DEPOSIT);
        printf("\n\n==================================");
        printf("\n\n按下 Enter 鍵回到主選單... \n");
        if (kbhit()) {
            int ch = getchar();
            if (ch == '\n') {
                break;  // Detected Enter key, exit loop
            }
        }
        fflush(stdout);  // Force flush buffer
        sleep(1);  // Refresh every second
    }
}

void option() {
    while (1) {
        system("clear");
        printf("\n\n\033[33m\t\t歡迎使用中華銀行自動櫃員機\033[0m");
        printf("\n\n\t\t===============================");
        printf("\n\n\t\t\033[1m1.提取現金");
        printf("\n\n\t\t2.存取現金");
        printf("\n\n\t\t3.餘額查詢");
        printf("\n\n\t\t0.退出卡片\033[0m");
        printf("\n\n\t\t===============================");
        printf("\n\n\t\t請選擇你所需要的操作：");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                withdrawl();
                break;
            case 2:
                deposit();
                break;
            case 3:
                remaining();
                break;
            case 0:
                printf("\n\n\033[33m\033[1m感謝您的使用，請收好您的卡片！\033[0m\n");
                sleep(2);
                exit(0);
            default:
                printf("\n\n\033[31m\033[1m輸入無效！\033[0m\n");
                sleep(1);
                break;
        }
    }
}

int main() {
    while (!checkpin()) {
        // do nothing, just wait for a successful login
    }

    enter();  // Display the ATM entry screen
    option(); // Display ATM options

    return 0;
}
