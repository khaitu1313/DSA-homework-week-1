#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findS(vector<int> nums){
    int n = nums.size();
    int max = nums[0];
    int min = nums[0];
    for(int i=0;i<n;i++){
        if(nums[i] >= max){
            max = nums[i];
        }else if(nums[i] <= min){
            min = nums[i];
        }
    }

    int s = max - min;
    return s;
}

int minimumAmplitude(vector<int>& nums, int k){
    vector<int> sub {};
    int n = nums.size();
    int left = 0;
    int right = k - 1;
    int times = 0;
    int minS;
    while(right < n){
        for(int i=0;i<n;i++){
            if(i < left || i > right){
                sub.push_back(nums[i]);
            }
        }

        if(times == 0){
            minS = findS(sub);
        }else{
            if(findS(sub) <= minS){
                minS = findS(sub);
            }
        }

        times++;
        left++;
        right++;
        sub.clear();
    }

    return minS;
}

int main(){
    vector<int> nums {9, 6, 2, 1, 10, 7};
    int k = 2;
    cout << minimumAmplitude(nums, k);
    return 0;
}