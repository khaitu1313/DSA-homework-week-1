#include <iostream>
using namespace std;

int findGCD(int a, int b)
{
    if(a == 0){
        return b;
    }else if(b == 0){
        return a;
    }else if(a == b){
        return a;
    }else if(a>b){
        return findGCD(b, a-b);
    }
    return findGCD(a, b-a);
}

int main(){
    cout << findGCD(360, 70);
    return 0;
}