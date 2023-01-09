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
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;

        for(string s : tokens){

            if(s == "+"){

                int n1 = stk.top();
                stk.pop();
                int n2 = stk.top();
                stk.pop();

                int n = n2 + n1;
                stk.push(n);

            }
            else if(s == "-"){
                int n1 = stk.top();
                stk.pop();
                int n2 = stk.top();
                stk.pop();

                int n = n2 - n1;
                stk.push(n);
            }
            else if(s == "*"){
                int n1 = stk.top();
                stk.pop();
                int n2 = stk.top();
                stk.pop();

                int n = n2 * n1;
                stk.push(n);
            }
            else if(s == "/"){
                int n1 = stk.top();
                stk.pop();
                int n2 = stk.top();
                stk.pop();

                int n = n2 / n1;
                stk.push(n);
            }
            else{
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};