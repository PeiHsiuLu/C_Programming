# C_Programming
# 小專題
[1. 井字遊戲](https://github.com/PeiHsiuLu/C_Programming/blob/main/tic.c)  
[2. ATM 系統](https://github.com/PeiHsiuLu/C_Programming/blob/main/atm.c)  
# 期末專題
# 筆記
## ANSI escape codes

## 基本語法
- (1.布林值)[#1.布林值]
### 1.布林值
以下是使用布林值與 if condition 判斷 true or false 
```c
#include <stdio.h>
#include <stdbool.h> //若是使用C++語法撰寫，不需要寫這一行，因為C++內就有涵蓋布林值
int main(){
    bool is_valid = false;//使用布林值 //false
    if(is_valid){
        printf("The value is true."); //is_valid=true 時，輸出這一行程式
    }else{
        printf("The value is false.");//is_valid=false 時，輸出這一行程式
    }
    printf("\n"); //換行
    return 0;
}
```
布林值中的true or false 可以用整數來表示 
```c
#include <stdio.h>
#include <stdlib.h>
int main(){
    bool is_true = true; //true
    bool is_false = false; //false
    printf("%d\n",is_true); //輸出1
    printf("%d\n",is_false); //輸出0
    return 0;
}
```

範例：簡易計算器  
```c
#include <stdio.h>
#include <stdbool.h>
int main(){
    int num_1; //第一個數字
    int num_2; //第二個數字
    bool is_true; //布林值判斷
    printf("Please enter two integer numbers: ");
    scanf("%d %d",&num_1,&num_2);
    printf("%d + %d = %4d\n",num_1,num_2,num_1+num_2); //加法
    printf("%d - %d = %4d\n",num_1,num_2,num_1-num_2); //減法
    printf("%d * %d = %4d\n",num_1,num_2,num_1*num_2); //乘法

    //if 判斷 num_2是否為0，非0是true;0則是false
    if(num_2 != 0){ 
        is_true = true; //當 num_2 不是 0 時，輸出這一行
    }else{
        is_true = false; // 當 num_2 不是 0 時，輸出這一行
    }

    if (is_true){
        printf("%d / %d = %4d\n",num_1,num_2,num_1/num_2); //除法，只有當 num_2 不是 0 時，才會輸出這一行
        printf("%d %% %d = %4d\n",num_1,num_2,num_1%num_2); //餘數，只有當 num_2 不是 0 時，才會輸出這一行
    }else{
        printf("Division: The second operand cannot be zero.\n"); //num_2 是0時，輸出這一行
        printf("Modules: The second operand cannot be zero.\n"); //num_2 是0時，輸出這一行
    }
    
}
```
