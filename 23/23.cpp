#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vec){
    int n = vec.size();
    cout << "[";
    for(int i = 0; i < n; i++){
        if(i != n - 1){
            cout << vec[i] << ", ";
        }else{
            cout << vec[i] << "]";
        }
    }
}

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations){
    int n = nums.size();
    int L, R, X;
    vector<int> output {};
    int keep;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
    }

    for(int i=0;i<operations[0].size();i++){
        L = operations[i][0];
        R = operations[i][1];
        X = operations[i][2];
        
        if(L >= 0 && R < n){
            if(L == R){
                arr[L] += X;
            }else if(L < R){
                for(int j=L;j<=R;j++){
                    arr[j] += X;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        keep = nums[i] + arr[i];
        output.push_back(keep);
    }
    
    return output;
}

int main(){
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations));
    return 0;
}