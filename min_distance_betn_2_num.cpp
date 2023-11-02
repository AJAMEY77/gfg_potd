//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int idx = -1 , flag = -1 , ans = INT_MAX ;
        for(int i = 0 ; i < n ; i++ ){
            if( a[i] == x || a[i] == y ){
                if( flag == - 1 ){
                    flag = a[i] ;
                    idx = i ;
                }
                else if( flag == x ){
                    if( a[i] == x )     idx = i ;
                    else{
                        ans = min(ans, i-idx ) ;
                        flag = y ;
                        idx = i ;
                    }
                }
                else{
                    if( a[i] == y )     idx = i ;
                    else{
                        ans = min(ans, i-idx ) ;
                        flag = x ;
                        idx = i ;
                    }
                }
            }
        }
        if( ans == INT_MAX )    return -1 ;
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends