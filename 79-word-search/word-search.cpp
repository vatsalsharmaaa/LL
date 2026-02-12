// class Solution {
// public:
// int n,m,k;
// vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
//     bool solve(vector<vector<char>>& board,int i,int j,string word,int idx){
//         if(idx==k)
//         return true;
       
//         if(i<0||j<0||i>=n||j>=m||board[i][j]=='$'||board[i][j]!=word[idx]){
//             return false;
//         }

//         char temp=board[i][j];

//         if(board[i][j]==word[idx]){
//             board[i][j]='$';
//         }

//         for(auto it: directions){
//             int ni= i+it[0];
//             int nj=j+it[1];

//              if(solve(board,ni,nj,word,idx+1)){
//                 return true;
//              }
//         }
//         board[i][j]=temp;

//         return false;

//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         n=board.size();
//         m=board[0].size();
//         k=word.size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(board[i][j]==word[0]&&solve(board,i,j,word,0)){
                   
//                         return true;
                    
//                 }
//             }
//         }
//         return false;
//     }
// };




class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string &word) {

        // Boundary check FIRST
        if(i < 0 || j < 0 || i >= m || j >= n) return false;

        // Already visited
        if(board[i][j] == '$') return false;

        // Character mismatch
        if(board[i][j] != word[idx]) return false;

        // Found all characters
        if(idx == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '$';  // mark visited

        for(auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(find(board, ni, nj, idx + 1, word))
                return true;
        }

        board[i][j] = temp; // restore
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};