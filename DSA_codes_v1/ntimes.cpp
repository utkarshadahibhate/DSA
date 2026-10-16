#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void printX(int X, int N){
        for (int i = 0; i < N; i++){
            cout<<" "<<X;
        }
    }
};
int main(){
    Solution s;
    s.printX(7,5);
    return 0;
}