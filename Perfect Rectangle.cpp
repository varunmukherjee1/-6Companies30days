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
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        map<pair<int,int>,int> mp;

        for(auto it : rectangles){

            mp[{it[0],it[1]}]++;
            mp[{it[2],it[3]}]++;
            mp[{it[2],it[1]}]--;
            mp[{it[0],it[3]}]--;
        }

        int ans = 0;

        for(auto it : mp){
            if(abs(it.second) == 1){
                ans++;
            }
            else if(abs(it.second) != 1 && it.second != 0){
                return false;
            }
        }

        return ans == 4;
    }
};