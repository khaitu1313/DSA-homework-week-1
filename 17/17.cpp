#include <iostream>
#include <vector>
using namespace std;

int equalSumIndex(vector<int>& nums){
    int n = nums.size();
    int sumLeft = 0;
    int sumRight = 0;
    for(int i=0;i<n;i++){
        if(i>0 && i<(n-1)){
            for(int j=0;j<i;j++){
                sumLeft += nums[j];
            }

            for(int k=i+1;k<n;k++){
                sumRight += nums[k];
            }

            if(sumLeft == sumRight){
                return i;
            }
            sumLeft = 0;
            sumRight = 0;
        }
    }
    return -1;
}

int main(){
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums);
    return 0;
}