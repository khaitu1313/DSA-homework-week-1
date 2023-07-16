#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestSublist(vector<string>& words){
    int nvect = words.size();
    int minN = words[0].length();
    for(int i=1;i<nvect;i++){
        int len = words[i].length();
        if(len <= minN){
            minN = len;
        }
    }
    return minN;
}

int main(){
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
    return 0;
}