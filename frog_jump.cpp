#include<bits/stdc++.h>
int solve(int n,vector<int> &heights,vector<int> &dp) {
 
    //top down
    //base case
//     if(n==0) return 0;
    
    
//     //memoization
//     if(dp[n]!=-1) {
//         return dp[n];
//     }
//     int left=solve(n-1,heights,dp)+ abs(heights[n]-heights[n-1]);
//     int right=INT_MAX;
//     if(n>1) {
//      right=solve(n-2,heights,dp)+ abs(heights[n]-heights[n-2]);
//     }
//     dp[n]=min(left,right);
//     return dp[n];
    
    
    //bottom up
    //base case;
    
    int prev=0,prev2=0;
   // dp[1]=heights[1]-heights[0];
    int curr=0;
    for(int i=1;i<n;i++) {
        int left=prev+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
       if(i>1) right=prev2+abs(heights[i]-heights[i-2]);
        curr=min(left,right);
        prev2=prev;
        prev=curr;
    }
    return prev;
}



int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    
   vector<int>dp(n+1,0);
   return solve(n,heights,dp);
}