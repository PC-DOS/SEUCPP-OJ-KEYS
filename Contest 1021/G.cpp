#include <iostream>  
#include <cstring>  
#include <cstdlib>  
using namespace std;
int factor_value();//读入一个因子并且返回其值  
int term_value();//读入一项的并且返回其值  
int expression_value();//读入一个表达式并返回值  
int main(){
    cout << expression_value() << endl;
    return 0;
}
int expression_value(){ //读入一个表达式并返回值
    int result = term_value();//求第一项的值  
    bool more = true;
    while (more){
        char op = cin.peek();//看一个字符不取走  
        if (op == '+' || op == '-'){
            cin.get();//从输入流中取走一个字符('+'或者'-')  
            int value = term_value();//读入下一个项  
            if (op == '+')
                result += value;
            else
                result -= value;
        }
        else
            more = false;
    }
    return result;
}
int term_value(){ //读入一项的并且返回其值  
    int result = factor_value();//读入一个因子  
    while (true){
        char op = cin.peek();//取出一个字符判断还有没有因子  
        if (op == '*' || op == '/'){
            cin.get();
            int value = factor_value();//读入下一个因子  
            if (op == '*')
                result *= value;
            else
                result /= value;
        }
        else
            break;
    }
    return result;
}
int factor_value(){ //读入一个因子并返回值  
    int result = 0;
    char c = cin.peek();//取出一个字符判断输入流中是一个因子还是一个整数  
    if (c == '('){
        cin.get();//去掉左括号  
        result = expression_value();//读入表达式  
        cin.get();//去掉右括号  
    }
    else{//是一个数字  
        while (isdigit(c))//求出数字的值  
        {
            result = 10 * result + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}