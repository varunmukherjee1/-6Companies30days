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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 0)  return nums;

        vector<int> dp(n,1), hash(n);

        int maxi = 1;
        int lastIdx = 0;
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < n ; i++){
            hash[i] = i;

            for(int prev = 0 ; prev < i ; prev++){
                if(nums[i]%nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIdx]);

        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }

        return temp;

    }
};