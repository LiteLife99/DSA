#include <iostream>
#include <stack>
using namespace std;

bool checkExpression(string str){
    stack<char> s;
    for(int i =0 ; i < str.length(); i++){
        char curChar = str[i];
        if (curChar == '('){
            s.push(curChar);
        }
        else if(curChar == ')'){
            if(s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty(); //true if empty.
}

int main(){
    string expr;
    cin >> expr;

    bool isValid = checkExpression(expr);
    cout << isValid << endl;
    return 0;
}