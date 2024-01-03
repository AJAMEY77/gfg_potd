//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int a=-1;
        int b=-1;
        int c=-1;
        int ans=INT_MAX;
        for(int i=0;i<S.length();i++){
            if(S[i]=='0') a=i;
            if(S[i]=='1') b=i;
            if(S[i]=='2') c=i;
            if(a!=-1 and b!=-1 and c!=-1){
                //cout<<a<<" "<<b<<" "<<c;
            int k=max(a,max(b,c))+1-min(a,min(b,c));
            ans=min(ans,k);}
        }
        return (ans==INT_MAX)?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends