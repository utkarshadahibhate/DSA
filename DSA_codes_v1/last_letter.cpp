#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    char lastchar(string &s){
        return s.back();
    }
    /*
    char lastchar(string &s){
        return s[s.size() - 1]; }*/
};
int main(){
    string str = "Hello";
    Solution s;
    cout<<s.lastchar(str)<<endl;
}

