//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int index=0;
        int ans=0;
        for(int i=0; i<n; i++){
            int maxi=INT_MIN;
            int index=0;
            int val=arr[i];
            ans++;
            for(int j=i+1; j<i+val+1; j++){
                if(arr[j]>=maxi){
                    maxi=arr[j];
                    index=j;
                    // cout<<maxi<<" "<<j<<endl;
                }
            }
            if(maxi+index>=n-1){
                break;
            }
            i=index;
        }
        return ans+1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends