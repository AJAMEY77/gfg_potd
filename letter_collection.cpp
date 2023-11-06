//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isSafe(int row, int col, int n, int m) {
        return (row<n && col<m && row>=0 && col>=0);
    }
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int> ans;
        
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        int d_x[] = {-2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2};
        int d_y[] = {-2, -1, 0, 1, 2, -2, 2, -2, 2, -2, 2, -2, -1, 0, 1, 2};
        
        
        for(int i=0; i<q; ++i) {
            int sum = 0;
            
            int hop = queries[i][0];
            int row = queries[i][1];
            int col = queries[i][2];
            
            if(hop == 1) {
                for(int k=0; k<8; ++k) {
                    int nRow = row + dx[k];
                    int nCol = col + dy[k];
                    if(isSafe(nRow, nCol, n, m)) sum += mat[nRow][nCol];
                }
            }else {
                for(int k=0; k<16; ++k) {
                    int nRow = row + d_x[k];
                    int nCol = col + d_y[k];
                    if(isSafe(nRow, nCol, n, m)) sum += mat[nRow][nCol];
                }
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends