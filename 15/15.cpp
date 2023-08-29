#include <iostream>
#include <algorithm>

using namespace std;

int buyCar(int* nums, int length, int k){
    int max;
    int count = 0;
    int sum = 0;
    for(int i=0;i<length;i++){
        if(sum + nums[i] < k){
            sum += nums[i];
            count++;
        }else if(sum + nums[i] == k){
            count++;
            max = count;
            count = 0;
            sum = 0;
        }
    }

    return max;
}

int main(){
    int nums[] = {90,30,40,90,20};
    int length = sizeof(nums)/sizeof(nums[0]);
    cout << buyCar(nums, length, 90) << "\n";
}