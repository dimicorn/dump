#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main() {
    string exp;
    stack <int> A;
    int a, b, x;
    while (cin >> exp){
        if (exp == "+") {
            a = A.top();
            A.pop();
            b = A.top();
            A.pop();
            A.push(b + a);
        }
        else if (exp == "-"){
            a = A.top();
            A.pop();
            b = A.top();
            A.pop();
            A.push(b - a);
        }
        else if (exp == "*"){
            a = A.top();
            A.pop();
            b = A.top();
            A.pop();
            A.push(b * a);
        }
        else if (exp == "/"){
            a = A.top();
            A.pop();
            b = A.top();
            A.pop();
            A.push(b / a);
        }
        else {
            x = stoi(exp);
            A.push(x);
        }

    }
    cout << A.top();
    return 0;
}
