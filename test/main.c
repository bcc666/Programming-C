#include <stdio.h>
#include <stdarg.h> // 必须包含此头文件

// 可变参数函数：n表示参数个数，后续是可选的int参数
int add(int n, ...) {
    int sum = 0;
    va_list args; // 定义可变参数列表

    // 初始化args，指向第一个可选参数（n是固定参数，作为参数个数标记）
    va_start(args, n);

    // 遍历所有可选参数
    for (int i = 0; i < n; i++) {
        // 从args中取出一个int类型的参数
        sum += va_arg(args, int);
    }

    va_end(args); // 释放可变参数列表
    return sum;
}

int main() {
    // 可选参数的使用：
    printf("只传1个参数（加0）：%d\n", add(1, 10));    // 输出：10
    printf("传2个参数：%d\n", add(2, 10, 20));         // 输出：30
    printf("传3个参数：%d\n", add(3, 10, 20, 30));     // 输出：60
    return 0;
}
