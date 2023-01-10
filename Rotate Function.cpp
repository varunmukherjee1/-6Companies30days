#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<queue>
#include<array>
#include<utility>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        int req = 0;

        for(int i = 0 ; i < n ; i++){
            sum += i*nums[i];
            req += nums[i];
        }

        ans = sum;

        for(int i = n-1 ; i >= 0 ; i--){
            sum = sum + req - (n*nums[i]);
            ans = max(ans,sum);
        }

        return ans;
    }
};