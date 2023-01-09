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
    void helper(unordered_set<int> st,vector<vector<int>>& vec,int curr , int d,int j,int k, int target){

        if(curr == target){
        
            if(st.size() == k){
                vector<int> temp;
                for(auto it : st){
                    temp.push_back(it);
                }

                vec.push_back(temp);
            }
            return;
        }

        if(d > k || j > 9 || curr > target)   return;


        for(int i = j ; i <= 9 ; i++){
            
            if(st.find(i) == st.end()){
                st.insert(i);
                helper(st,vec,curr + i,d+1,i+1,k,target);
                st.erase(i);
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        unordered_set<int> st;
        vector<vector<int>> ans;

        helper(st,ans,0,1,1,k,n);

        return ans;
    }
};