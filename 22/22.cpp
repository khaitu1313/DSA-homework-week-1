#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sumLessThanTarget(vector<int>& nums, int target) {
    int n = nums.size();
    int sum, max;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum = nums[i] + nums[j];
            if(i == 0 && j == 1){
                max = sum;
            }else{
                if(sum >= max && sum < target){
                    max = sum;
                }
            }
        }
    }

    return max;
}

int main(){
    vector<int> nums {1, 3, 5, 7, 11};
    int target = 7;
    cout << sumLessThanTarget(nums, target);
    return 0;
}