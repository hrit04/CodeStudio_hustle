#include<bits/stdc++.h>
int solve(int idx1,int idx2,string pattern, string text,vector<vector<int>>&dp) {
    
    //base case
    if(idx1<0 && idx2<0) return 1;
    if(idx1<0 && idx2>=0) return 0;
    if(idx1>=0 && idx2<0) {
        for(int i=0;i<=idx1;i++) {
            if(pattern[i]!='*') return 0;
        }
        return 1;
    }
    if(dp[idx1][idx2]!=-1) {
        return dp[idx1][idx2];
    }
    
    
    if(pattern[idx1]=='?' or pattern[idx1]==text[idx2]) return dp[idx1][idx2]= (solve(idx1-1,idx2-1,pattern,text,dp))?1:0;
    else if(pattern[idx1]=='*') return dp[idx1][idx2] = (solve(idx1,idx2-1,pattern,text,dp) or solve(idx1-1,idx2,pattern,text,dp)) ?1:0;
    else return dp[idx1][idx2]=0;
}


bool wildcardMatching(string pattern, string text) {
   // Write your code here.
    int pl=pattern.size();
    int tl=text.size();
    vector<vector<int>>dp(pl+1,vector<int>(tl+1,-1));
    
    int ans=solve(pl-1,tl-1,pattern,text,dp);
    return (ans)? true :false; 
}
