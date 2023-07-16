#include <iostream>
#include <math.h>
using namespace std;

int count(int x, int desNum){
    if(x < 0)
        return 0;
    if(x == 0)
        return 1;
    if(desNum * desNum > x)
        return 0;

    return count(x, desNum + 1) + count(x - desNum * desNum, desNum + 1);
}

int countWaySumOfSquare(int x){
    return count(x, 1);
}

int main(){
    cout << countWaySumOfSquare(100);
    return 0;
}