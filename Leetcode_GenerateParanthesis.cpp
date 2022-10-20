/*
Problem No:- 22
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8

*/


class Solution {
public:
    
    vector<string> v;
    
    
    void rec(int o,int c,int n,string s){
        if(o==n && c==n){
            v.push_back(s);
            return;
        }
        else if(o==n && c<n){
            rec(o,c+1,n,s+')');
        }
        else if(c>o){
            return;
        }
        else if(o==c){
            rec(o+1,c,n,s+'(');
        }
        else if(o>c){
            rec(o+1,c,n,s+'(');
            rec(o,c+1,n,s+')');
        }
        else
        return;
    }
    vector<string> generateParenthesis(int n) {
        rec(0,0,n,"");
        
        return v;
    }
};