#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
 
using namespace std;
 
int main(){
    string sBracketSeq;
    stack<char> stkBrackets;
 
    getline(cin, sBracketSeq);
 
    for (int i = 0; i < sBracketSeq.length(); ++i){
        switch (sBracketSeq[i]){
        case '(':
            stkBrackets.push('(');
            break;
        case '[':
            stkBrackets.push('[');
            break;
        case '{':
            stkBrackets.push('{');
            break;
        case ')':
            if (stkBrackets.empty() || stkBrackets.top() != '('){
                cout << "NO" << endl;
                goto endapp;
            }
            else{
                stkBrackets.pop();
            }
            break;
        case ']':
            if (stkBrackets.empty() || stkBrackets.top() != '['){
                cout << "NO" << endl;
                goto endapp;
            }
            else{
                stkBrackets.pop();
            }
            break;
        case '}':
            if (stkBrackets.empty() || stkBrackets.top() != '{'){
                cout << "NO" << endl;
                goto endapp;
            }
            else{
                stkBrackets.pop();
            }
            break;
        default:
            break;
        }
    }
 
    cout << "YES" << endl;
 
endapp:
#ifdef _WIN32
    system("pause > nul");
#endif
 
    return 0;
}