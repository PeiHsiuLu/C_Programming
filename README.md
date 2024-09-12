# C_Programming
# 筆記
## 布林值
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
    bool is_true = true;
    bool is_false = false;
    printf("%d\n",is_true); \\輸出1
    printf("%d\n",is_false); \\輸出0
    return 0;
}
```
