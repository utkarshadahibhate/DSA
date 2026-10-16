#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int sumofFirstAndLast(vector<int> &nums){
        if(nums.empty()){
            return 0;
        }

        int first = nums[0];
        int last = nums[nums.size() - 1];

        return first + last;
    }
};

int main() {
    vector<int> nums = {2, 5 , 8 , 2, 6};

    //Creating an instance of solution class
    Solution sol;

    int ans = sol.sumofFirstAndLast(nums);
    cout<<"Result is : "<<ans<<endl;
    return 0;
}