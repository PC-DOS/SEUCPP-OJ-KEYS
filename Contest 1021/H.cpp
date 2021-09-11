#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;
 
bool pop(int sta[], int in[], int &curin, int &cur, int out);
 
int main(){
    int numin, numout, current = 1, total = 0, currentin = 0;    //需要设出两个表示下标的变量，分别代表栈的下标和输入序列读取到的下标
    cin >> numin;
    numout = numin;
    int *p, *q, *stack;
    p = new int[numin];
    q = new int[numout];
    stack = new int[numin];
    for (int i = 0; i < numin; ++i) cin >> p[i];  //读入输入序列
    for (int i = 0; i < numout; ++i) cin >> q[i]; //读入输出序列
    stack[0] = p[0];     //输入序列第一个数入栈
 
    for (int i = 0; i < numout; ++i)     //从第一个输出序列的数字依次开始寻找
        if (pop(stack, p, currentin, current, q[i]) == false){   //如果没有寻找到某一个输出数字，直接输出结果0
            total = 0; break;
        }
        else { 
            total += 1; currentin -= 1;
        }   //找到输出数字，那么出栈后栈的下标数字减1
        cout << (total ? "YES" : "NO");
        return 0;
}
 
bool pop(int sta[], int in[], int &curin, int &cur, int out){   //判断并出栈的函数
    for (; in[cur - 1] != '\0'; ++cur){                           //依次遍历栈顶和输入序列剩余的数字
        if (sta[curin] == out) { sta[curin] = in[cur]; return true; }   //找到则更替栈顶数字，返回true
        else{ curin += 1; sta[curin] = in[cur]; }
    }
    return false;                                           //没找到，返回false
}