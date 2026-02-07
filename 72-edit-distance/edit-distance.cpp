// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();

//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         // Base cases
//         // If word2 is empty => delete all from word1
//         for (int i = 0; i <= m; i++)
//             dp[i][0] = i;

//         // If word1 is empty => insert all chars of word2
//         for (int j = 0; j <= n; j++)
//             dp[0][j] = j;

    
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {

//                 if (word1[i - 1] == word2[j - 1]) {
//                     // characters match → no operation
//                     dp[i][j] = dp[i - 1][j - 1];
//                 } 
//                 else {
                
//                     dp[i][j] = 1 + min({
//                         dp[i][j - 1],     // insert
//                         dp[i - 1][j],     // delete
//                         dp[i - 1][j - 1]  // replace
//                     });
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };

class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(string &s1,string &s2,int i,int j){
        if(i==m){
            return n-j; //insert in s1
        } 
        else if(j==n){
            return m-i; //delete in s1
        }
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = solve(s1,s2,i+1,j+1);
        }
        else{
            int insertC=1+solve(s1,s2,i,j+1);
            int deleteC=1+solve(s1,s2,i+1,j);
            int replaceC=1 +solve(s1,s2,i+1,j+1);

            return dp[i][j]=min({insertC,deleteC,replaceC});
        }
        return -1;

    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        m=word1.size();
        n=word2.size();
        

        return solve(word1,word2,0,0);

    }
};