#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>
using namespace std;

int functional(int* arr, int size){
    int count = 0;
    int keep;
    int arrNum;
    int maxL;
    for(int i=0;i<size;i++){
        if(i == 0){
            keep = arr[i];
            arrNum = 1;
            count++;
        }else{
            if(arr[i] == keep){
                count++;
            }else{
                if(arrNum == 1){
                    maxL = count;
                }else{
                    if(count >= maxL){
                        maxL = count;
                    }
                }
                keep = arr[i];
                count = 1;
                arrNum++;
            }
        }
    }

    return maxL + 1;
}

int steadySpeed(vector<int>& positions){
    int size = positions.size();
    int left;
    int right;
    int velocity;
    int maxLength;
    int* arr = new int[size - 1];
    for(int i=0;i<size-1;i++){
        left = i;
        right = i+1;
        int leftData = positions[left];
        int rightData = positions[right];
        velocity = abs(rightData - leftData);
        arr[i] = velocity;
    }
    int x = functional(arr, size);
    delete[] arr;
    return x;
}

int main(){
    // vector<int>positions{5,4,3,5,4,5,1,3,5,3};
    vector<int>positions{0, 3, 6, 3, 0};
    cout << steadySpeed(positions);
    return 0;
}