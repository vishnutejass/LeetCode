class Solution {
public:
    
    
    
    int uniquePaths(int m, int n) {
        if(m==0 && n==0) return 1;
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
      
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
       
        
        return dp[m-1][n-1];
    }
};


//using recursion

// class Solution {
// public:
    
//     int paths(int m,int n,int i,int j){
//         if(i==m-1 && j==n-1) return 1;   
       
//         int r=(i<m-1) ? paths(m,n,i+1,j) :0;
           
//         int d=(j<n-1) ? paths(m,n,i,j+1): 0;
        
//         return r+d;   
//     }
    
//     int uniquePaths(int m, int n) {
//         if(m==0 && n==0) return 1;
        
//       int c=  paths(m,n,0,0);
       
//         return c;
//     }
// };
