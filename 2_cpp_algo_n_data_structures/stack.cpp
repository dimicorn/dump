#include<iostream>
#include<stack>

//using std::cin;
//using std::cout;
//using std::endl;
//using std::stack;

using namespace std;

int main() {
    stack <int> A;
    int j = 0;
    int a = 0;
    int x;
    while (j != 1){
       cin >> x;
       if(x == 0){
           break;
       }
       if(x > 0){
           A.push(x);
           a++;
       }
       if(x < 0){
           if(a == 0){
               continue;
           }
           int y = A.top();
           if(y * y > x * x){
               A.pop();
               A.push(y + x);
           }
           else{
               A.pop();
               a--;
           }
       }
    }
    if(a == 0){
        cout << a << " " << -1;
    }
    else{
        cout << a << " " << A.top();
    }
    return 0;
}