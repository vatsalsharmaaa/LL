class Solution {
public:

    int dp[2501][2501];
    int n;

    int solve(int idx,int p,vector<int>&nums)
    {
        if(idx>=n){
            return 0;
        }
        if(p!=-1 && dp[idx][p]!=-1){    //p!=-1 code fat jayega vrna
            return dp[idx][p];
        }
        //take
        int take=0;
        if(p==-1||nums[idx]>nums[p]){
         take = 1+ solve(idx+1,idx,nums); //current idx will become p
                                             //yaad kr fir usse compare krenge furtherr
        }                                     
        int skip = solve(idx+1,p,nums);      //no change in p

        if(p!=-1)  //again p should not be -1 vrna fat jayega code
         dp[idx][p]= max(take,skip);

         return max(take,skip);
    }


    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
         n=nums.size();
        return solve(0,-1,nums);
    }
};