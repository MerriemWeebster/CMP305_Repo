#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
bool isInteger(char * s)
{
    if((s[0] -'0')  >= 0 && (s[0] -'0') <= 9)
        return true;
    else
        return false;
}

int main() {
 
    int op1, op2, result;
    stack<int> stack;

    char  pstfix[80];
    cout << "Enter post fic notation : ";
    cin.getline(pstfix,80);

    char * pch;
    cout << "Splitting string "<< pstfix << "  into tokens and computing your answer... "<<endl;
    pch = strtok (pstfix ," ");
    while (pch != NULL)
    {
        if (isInteger(pch)) {
            stack.push((int)*pch - 48);
        }
        else {
            int a, b;
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();

            switch (*pch) {
                case '+':
                    stack.push(b + a);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(b * a);
                    break;
                case '/':
                    stack.push(b / a);
                    break;
            }
            
        }

        pch = strtok (NULL, " ");
    }
    cout << "The expression evaluates to: "<< stack.top();
    return 0;
}