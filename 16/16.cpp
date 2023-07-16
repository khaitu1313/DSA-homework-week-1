#include <iostream>
#include <vector>
using namespace std;

bool consecutiveOnes(vector<int>& nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] == 1 && nums[i+1] == 1){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> nums {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums);
    return 0;
}