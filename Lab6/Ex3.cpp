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
    cout << "Splitting string "<< pstfix << "  into tokens: "<<endl;
    pch = strtok (pstfix ," ");
    while (pch != NULL)
    {
        
        cout<<pch<<endl;

        pch = strtok (NULL, " ");
    }
    return 0;
}
