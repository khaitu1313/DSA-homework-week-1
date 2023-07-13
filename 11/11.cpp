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

int findLCM(int a, int b){
    return (a*b)/findGCD(a,b);
}

int main(){
    cout << findLCM(2,4);
    return 0;
}