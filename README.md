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



## 基本語法
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

