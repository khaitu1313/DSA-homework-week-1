#include <iostream>
using namespace std;

int help(int x, int c){
    if(x % c != 0){
        return -1;
    }

    x/=c;
    if(x == 1){
        return c;
    }

    return help(x, c+1);
}

int reverseFactorial(int n){
    int k = 1;
    int result = help(n,k);
    return result;
}

int main(){
    cout << reverseFactorial(1111);
    return 0;
}