# C_Programming
# 小專題
[1. 井字遊戲](https://github.com/PeiHsiuLu/C_Programming/blob/main/tic.c)  
[2. ATM 系統](https://github.com/PeiHsiuLu/C_Programming/blob/main/atm.c)  
# 期末專題
# 筆記
## ANSI escape codes
### 介紹
- ANSI escape codes 是一組標準化的代碼，用於控制視頻文本終端或終端仿真器的行為。這些代碼以 ESC (Escape) 字符開始，即 ASCII 編碼的 27（十六進制 0x1B）。
### 常用的 ANSI escape codes
- 顏色和格式設定：使用這些代碼可以改變文本的顏色或格式，例如加粗或下劃線。
- 文本顏色設定範例（前景色）：
  ```plaintext
  \033[31m     // 紅色
  \033[32m     // 綠色
  \033[33m     // 黃色
  ```
- 背景顏色設定範例
  ```plainttext
  \033[41m     // 紅色背景
  \033[42m     // 綠色背景
  \033[44m     // 藍色背景
  ```
- 格式設定範例：
  ```plaintext
  \033[1m      // 加粗
  \033[4m      // 下劃線
  ```
### 光標控制
- ANSI 代碼還可用於控制光標在終端中的位置，例如移動光標到特定位置或清除屏幕的一部分
- 移動光標到特定行和列：
  ```plaintext
  \033[10;15H  // 移動光標到第10行，第15列
  ```
- 清除屏幕：
  ```plaintext
  \033[2J      // 清除整個屏幕並將光標移動到左上角
  \033[K       // 清除從當前光標位置到行尾的部分
  ```
- 範例：格式化文本輸出
- 這個範例顯示如何在 C 程序中使用 ANSI escape codes 來格式化文本輸出：
  ```plaintext
  #include <stdio.h>

  int main() {
      printf("\033[1;31m這是紅色加粗的文本\033[0m\n");
      printf("\033[4;32m這是綠色下劃線的文本\033[0m\n");
      return 0;
  }
  ```
- \033[0m 用於重置所有屬性到默認狀態。






## 基本語法

1. [布林值（Boolean）](#布林值boolean)
2. [if/switch 條件判斷](#ifswitch-條件判斷)
3. [while/for 迴圈](#whilefor-迴圈)
4. [變數與類型](#變數與類型)
5. [數組（Array）](#數組array)
6. [指標（Pointer）](#指標pointer)
7. [結構體（Struct）](#結構體struct)
8. [列舉（Enum）](#列舉enum)
9. [位元運算（Bitwise Operation）](#位元運算bitwise-operation)
10. [函式（Function）](#函式function)
11. [字元（Character）](#字元character)
12. [字串（String）](#字串string)
### 1. 布林值

- **布林值（Boolean）**
  - 在 C 中，布林值並不是標準的數據類型，但可以透過標準庫 `<stdbool.h>` 使用 `bool` 類型。
  - 布林值有兩種：`true` 和 `false`，它們實際上是整數類型，其中 `true` 代表 1，`false` 代表 0。

    ```c
    #include <stdbool.h>

    bool a = true;
    bool b = false;
    ```

- **布林運算**
  - 在 C/C++ 中，布林值可以進行邏輯運算，這些運算符包括：
    - **`&&`（邏輯與運算）**：如果兩個條件都為 `true`，結果才會是 `true`。
      ```c
      bool a = true;
      bool b = false;
      printf("%d\n", a && b);  // 結果是 0（false）
      ```

    - **`||`（邏輯或運算）**：只要其中一個條件為 `true`，結果就是 `true`。
      ```c
      bool a = true;
      bool b = false;
      printf("%d\n", a || b);  // 結果是 1（true）
      ```

    - **`!`（邏輯非運算）**：將布林值的真偽進行反轉，`true` 變 `false`，`false` 變 `true`。
      ```c
      bool a = true;
      printf("%d\n", !a);  // 結果是 0（false）
      ```

- **比較運算符**
  - 常見的比較運算符可用於產生布林結果：
    - **`==`（等於）**：判斷兩個值是否相等，返回 `true` 或 `false`。
      ```c
      int x = 5;
      int y = 5;
      printf("%d\n", x == y);  // 結果是 1（true）
      ```

    - **`!=`（不等於）**：判斷兩個值是否不相等。
      ```c
      int x = 5;
      int y = 3;
      printf("%d\n", x != y);  // 結果是 1（true）
      ```

    - **`>`、`<`、`>=`、`<=`（比較運算）**：比較兩個值的大小。
      ```c
      int x = 5;
      int y = 3;
      printf("%d\n", x > y);  // 結果是 1（true）
      printf("%d\n", x <= y); // 結果是 0（false）
      ```

- **布林值的應用**
  - 在 C/C++ 中，布林值廣泛應用於條件判斷中，例如 `if` 語句：
    ```c
    int a = 5;
    if (a > 3) {
        printf("a 比 3 大\n");
    }
    ```

  - 布林值也常用於迴圈結構，例如 `while` 循環：
    ```c
    int a = 0;
    while (a < 5) {
        printf("%d\n", a);
        a++;
    }
    ```

  - 邏輯運算的結果可以用來控制程序的執行流程。
----
### 2. 整數（Integers）

- **基本介紹**
  - 在 C 語言中，整數類型用於表示不帶小數的數字。
  - 常見的整數數據類型有：
    - `int`：標準的整數類型。
    - `short`：較小範圍的整數類型。
    - `long`：較大範圍的整數類型。
    - `long long`：用於表示更大範圍的整數。
  - 各類型的範圍與具體值取決於系統架構，但通常可以使用 `<limits.h>` 來檢查。

    ```c
    #include <stdio.h>
    #include <limits.h>

    int main() {
        printf("int 的最小值: %d\n", INT_MIN);
        printf("int 的最大值: %d\n", INT_MAX);
        return 0;
    }
    ```

- **無符號整數**
  - 在 C 中，整數也可以是無符號的（`unsigned`），這意味著整數只能是正數或零。
  - 無符號類型的範例：
    - `unsigned int`：不允許負數，範圍是從 0 到 2 的 32 次方減 1。
      ```c
      unsigned int a = 100;
      printf("%u\n", a);  // 使用 %u 格式化無符號整數
      ```

- **格式化輸出**
  - 不同類型的整數在 `printf` 中有不同的格式說明符：
    - `%d`：有符號整數（`int`）
    - `%u`：無符號整數（`unsigned int`）
    - `%ld`：長整數（`long int`）
    - `%lld`：更大範圍的整數（`long long int`）

---

### 3. 浮點數（Floating Point）

- **基本介紹**
  - 浮點數用於表示帶有小數點的數值。
  - C 語言中常見的浮點數類型有：
    - `float`：單精度浮點數。
    - `double`：雙精度浮點數，能夠表示更高精度的小數。
    - `long double`：用於表示更高精度的浮點數。
  
  - `float` 通常佔用 4 個字節，`double` 佔用 8 個字節。具體大小可使用 `<float.h>` 檢查。

    ```c
    #include <stdio.h>
    #include <float.h>

    int main() {
        printf("float 的最小值: %e\n", FLT_MIN);
        printf("double 的最大值: %e\n", DBL_MAX);
        return 0;
    }
    ```

- **浮點數精度**
  - `float` 通常提供大約 6 位有效數字的精度，而 `double` 可以達到 15 位。

- **格式化輸出**
  - `printf` 常用的浮點數格式說明符有：
    - `%f`：格式化為十進制記法。
    - `%e`：科學記數法表示浮點數。
    - `%lf`：用於雙精度浮點數。

    ```c
    float a = 5.12;
    double b = 3.14159;
    printf("float: %f\n", a);   // 結果: 5.120000
    printf("double: %lf\n", b); // 結果: 3.141590
    ```

---

### 4. 字符（Characters）

- **基本介紹**
  - `char` 是 C 語言中的基本數據類型，用於存儲單個字符。
  - 實際上，`char` 在底層是 1 個字節的整數類型，對應於 ASCII 編碼表中的一個數值。

    ```c
    char letter = 'A';
    printf("字符: %c\n", letter);    // 輸出字符
    printf("ASCII 值: %d\n", letter); // 輸出字符的 ASCII 值
    ```

- **格式化輸出**
  - `%c`：用於輸出單個字符。
  - `%d`：可以用來查看字符的 ASCII 整數值。

- **轉義字符**
  - C 語言中有一些特殊的轉義字符可以用來控制輸出，例如：
    - `\n`：換行符。
    - `\t`：水平製表符（tab）。
    - `\\`：反斜槓。
    - `\'`：單引號。
    - `\"`：雙引號。

    ```c
    printf("Hello\nWorld!\n");  // 輸出時會換行
    printf("這是\t一個製表符。\n");
    ```

---

### 5. 字符串（Strings）

- **基本介紹**
  - C 語言中的字符串實際上是一個字符數組，並且以 `\0`（null 終止符）結尾。
  - 可以用雙引號來表示字符串，例如：
    ```c
    char str[] = "Hello, World!";
    ```

- **輸出字符串**
  - `%s` 用於輸出字符串：
    ```c
    printf("%s\n", str);  // 輸出: Hello, World!
    ```

- **常見的字符串操作**
  - C 標準庫提供了許多用於處理字符串的函數，這些函數定義在 `<string.h>` 中，例如：
    - `strlen()`：計算字符串的長度。
    - `strcpy()`：複製字符串。
    - `strcmp()`：比較兩個字符串。
    - `strcat()`：拼接兩個字符串。

    ```c
    #include <stdio.h>
    #include <string.h>

    int main() {
        char str1[20] = "Hello";
        char str2[] = ", World!";

        strcat(str1, str2);  // 拼接字符串
        printf("%s\n", str1);  // 結果: Hello, World!
        return 0;
    }
    ```

---

### 6. 陣列（Arrays）

- **基本介紹**
  - 陣列是用來存放相同類型數據的一組連續存儲空間。
  - 宣告陣列的語法如下：
    ```c
    int arr[5];  // 宣告一個能存放 5 個整數的陣列
    ```

- **陣列初始化**
  - 可以在宣告時直接初始化：
    ```c
    int arr[5] = {1, 2, 3, 4, 5};
    ```

- **訪問陣列元素**
  - 使用索引來訪問陣列元素，索引從 0 開始：
    ```c
    printf("%d\n", arr[0]);  // 輸出第一個元素 1
    ```

---

### 7. 指標（Pointers）

- **基本介紹**
  - 指標是存儲另一個變量的記憶體地址的變量。
  - 指標的基本語法：
    ```c
    int *ptr;
    ```

- **指標的操作**
  - 取地址符 `&` 可以獲取變量的地址，而解引用符 `*` 可以訪問指標所指向的數據。
    ```c
    int a = 10;
    int *p = &a;  // p 指向變量 a 的地址
    printf("%d\n", *p);  // 解引用，輸出 a 的值 10
    ```

- **指標與陣列**
  - 陣列的名字實際上是一個指向第一個元素的指標：
    ```c
    int arr[3] = {1, 2, 3};
    int *p = arr;  // p 指向 arr 的第一個元素
    printf("%d\n", *p);  // 輸出 1
    ```

---

---

### 8. 條件判斷（if/switch）

- **if 語句**
  - `if` 語句用於條件判斷，如果條件為真，則執行對應的程式區塊：
    ```c
    int a = 5;
    if (a > 3) {
        printf("a 大於 3\n");
    }
    ```

- **else if 和 else**
  - 當多個條件需要檢查時，可以使用 `else if` 和 `else`：
    ```c
    int a = 5;
    if (a > 10) {
        printf("a 大於 10\n");
    } else if (a == 5) {
        printf("a 等於 5\n");
    } else {
        printf("a 小於 5\n");
    }
    ```

- **switch 語句**
  - `switch` 語句用於檢查變量的多個值，通常用於取代多個 `if-else` 結構：
    ```c
    int day = 3;
    switch(day) {
        case 1:
            printf("星期一\n");
            break;
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        default:
            printf("無效的日期\n");
    }
    ```
  - 每個 `case` 代表一個條件，如果匹配到相應的值，執行對應的區塊並使用 `break` 終止。

---

### 9. 迴圈（while/for loop）

- **while 迴圈**
  - `while` 迴圈會在條件為真的情況下不斷執行，直到條件變為假：
    ```c
    int i = 0;
    while (i < 5) {
        printf("%d\n", i);
        i++;
    }
    ```

- **do-while 迴圈**
  - `do-while` 迴圈至少會執行一次，因為條件是在執行後檢查：
    ```c
    int i = 0;
    do {
        printf("%d\n", i);
        i++;
    } while (i < 5);
    ```

- **for 迴圈**
  - `for` 迴圈有一個初始化部分、條件部分和更新部分，通常用於執行固定次數的迴圈：
    ```c
    for (int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }
    ```

- **範例：計算總和**
  - 迴圈常用來執行重複計算，例如計算總和：
    ```c
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("1 到 100 的總和是: %d\n", sum);
    ```

- **break 和 continue**
  - `break`：在迴圈中使用 `break` 來提前終止迴圈。
  - `continue`：跳過本次迴圈的其餘部分，直接進入下一次迴圈。

    ```c
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;  // 當 i 等於 5 時，終止迴圈
        }
        if (i % 2 == 0) {
            continue;  // 當 i 是偶數時，跳過當前次的迴圈
        }
        printf("%d\n", i);  // 只會輸出奇數
    }
    ```

---
---

### 10. 函式（Function）

- **函式的定義**
  - 在 C 語言中，函式是一組執行特定任務的程式碼。函式通常包括函式名稱、參數列表和返回值類型。
  - 函式的基本結構如下：
    ```c
    返回值類型 函式名稱(參數類型 參數名稱) {
        // 函式主體
        return 返回值;
    }
    ```

- **範例：簡單的函式**
  - 例如，一個返回兩個整數和的函式：
    ```c
    int add(int a, int b) {
        return a + b;
    }

    int main() {
        int result = add(3, 5);
        printf("3 + 5 = %d\n", result);
        return 0;
    }
    ```

- **函式宣告與定義**
  - 在使用函式前，你需要先宣告它，這樣編譯器才知道它的存在：
    ```c
    int add(int a, int b);  // 函式宣告

    int main() {
        int result = add(3, 5);
        printf("3 + 5 = %d\n", result);
        return 0;
    }

    int add(int a, int b) {  // 函式定義
        return a + b;
    }
    ```

- **傳值呼叫（Call by Value）**
  - 在 C 語言中，函式的參數是按值傳遞的，也就是說，函式內部的變量是一個副本，對它的修改不會影響到原變量：
    ```c
    void modify(int x) {
        x = 10;
    }

    int main() {
        int a = 5;
        modify(a);
        printf("a = %d\n", a);  // 輸出仍然是 5
        return 0;
    }
    ```

---

### 11. 字元（Character）

- **字元類型**
  - 在 C 語言中，字元（`char`）是一個基本數據類型，用於儲存單一字元。每個字元都對應一個 ASCII 編碼值。
    ```c
    char letter = 'A';
    printf("字元: %c, ASCII 值: %d\n", letter, letter);  // 輸出：字元: A, ASCII 值: 65
    ```

- **範例：字元的操作**
  - 可以使用字元進行數學運算，因為字元實際上是數字的表現：
    ```c
    char ch = 'A';
    printf("下一個字母: %c\n", ch + 1);  // 輸出：下一個字母: B
    ```

- **特殊字元**
  - 常見的特殊字元有：
    - `\n`：換行
    - `\t`：水平製表符
    - `\\`：反斜槓
    - `\'`：單引號
    - `\"`：雙引號

---

### 12. 字串（String）

- **字串的定義**
  - 在 C 語言中，字串實際上是由 `char` 組成的字符陣列，並以空字元（`'\0'`）結尾。這樣編譯器才能識別字串的結尾。
    ```c
    char str[] = "Hello, World!";
    printf("%s\n", str);  // 輸出：Hello, World!
    ```

- **字串操作**
  - C 語言中有一些標準函式可以對字串進行操作，例如複製、連接和比較。這些函式通常包含在 `<string.h>` 中。
  
  - **字串長度：`strlen`**
    ```c
    #include <string.h>

    int main() {
        char str[] = "Hello";
        printf("字串長度: %lu\n", strlen(str));  // 輸出：字串長度: 5
        return 0;
    }
    ```

  - **複製字串：`strcpy`**
    ```c
    #include <string.h>

    int main() {
        char str1[20];
        char str2[] = "C Programming";
        strcpy(str1, str2);  // 將 str2 複製到 str1
        printf("str1: %s\n", str1);  // 輸出：str1: C Programming
        return 0;
    }
    ```

  - **連接字串：`strcat`**
    ```c
    #include <string.h>

    int main() {
        char str1[20] = "Hello, ";
        char str2[] = "World!";
        strcat(str1, str2);  // 將 str2 連接到 str1
        printf("str1: %s\n", str1);  // 輸出：str1: Hello, World!
        return 0;
    }
    ```

  - **比較字串：`strcmp`**
    ```c
    #include <string.h>

    int main() {
        char str1[] = "Hello";
        char str2[] = "World";
        int result = strcmp(str1, str2);  // 比較 str1 和 str2
        if (result == 0) {
            printf("字串相等\n");
        } else {
            printf("字串不相等\n");
        }
        return 0;
    }
    ```

- **注意事項**
  - 字串在 C 中的大小是固定的，因此需要事先分配足夠的記憶體空間，否則可能導致溢出問題。

---



