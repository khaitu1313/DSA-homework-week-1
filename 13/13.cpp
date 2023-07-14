#include <iostream>
#include <string>
using namespace std;

    int n = 0;
int shortestString(string s){
    if(s.length() <= 1){
        return n;
    }

    if(s[0] != s[1]){
        return shortestString(s.substr(2));
    }else{
        n++;
        return shortestString(s.substr(1));
    }
}

int main(){
    cout << shortestString("111110");
    return 0;
}