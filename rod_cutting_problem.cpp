long solve(int idx , vector<int> &price , int target , vector<vector<long>> &dp) {
       
      //base case
    if(idx==0) {
         return ((target / (idx+1)) * price[idx]) ;    
    }
    if(target<=0) {
        return 0;
    }
//     if(target<0) return 0;
      
    if(dp[idx][target]!=-1) {
        return dp[idx][target];
    }

        long ntk = 0+ solve(idx-1,price,target,dp);
    
        long tk=-1e9;
        if((idx+1)<=target) {
            tk= price[idx] + solve(idx, price, target-(idx+1),dp);
        }
    
    return  dp[idx][target]=max(ntk , tk);
    
}




int cutRod(vector<int> &price, int n) {
	// Write your code here.
    //top down
     vector<vector<long>>dp(n,vector<long>(n+1,-1));
    return solve(n-1,price,n,dp);
    
}
