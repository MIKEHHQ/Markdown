# Caculator(+-)
## Description
https://leetcode.cn/problems/basic-calculator/
## Code
```C
int calculate(char* s) {
    int n = strlen(s);
    int ops[n], top = 0;
    int sign = 1;
    ops[top++] = sign;
    //ops[0] = 1;
    //top = 1

    int ret = 0;
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
            //空格跳过就行
        } else if (s[i] == '+') {
            sign = ops[top - 1];
            i++;
        } else if (s[i] == '-') {
            sign = -ops[top - 1];
            i++;
        } else if (s[i] == '(') {
            ops[top++] = sign;
            //将当前的 sign 取值压入栈中
            i++;
        } else if (s[i] == ')') {
            top--;
            //从栈中弹出一个元素
            i++;
        } else {
            long num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                // num*10 是读取高位数字
                // s[i] - '0' 字符转数字
                i++;
                //内部读取下一位数字看看
            }
            ret += sign * num;
            // 累计到ret中
        }
    }
    return ret;
}
```
因为只考虑加减号sign，括号前有负号则括号内数字符号取反。ops是一个栈来存储sign。
原先这么写，出现死循环：
```C
while(s[i] <= '9' && s[i] >= '0'){

	num = num*10 +s[i] - '0';

}

sum += sign * num;
```