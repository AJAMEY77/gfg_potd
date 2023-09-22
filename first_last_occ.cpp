// Given a sorted array arr containing n elements with possibly duplicate is to find indexes of first elements, the task is to find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.


// Example 1:

// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  
// 2 5
// Explanation: 
// First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
    
        int first=-1;
        int last=-1;
        vector<int>v;
        
        for(int i=0;i<n;i++){
            
            if(arr[i]==x){
                if(i==0){
                    if(first==-1){ 
                    first=i;
                    }
                }
                if(arr[i-1]!=x){
                    if(first==-1){
                    first=i;
                    }
                }
                if(i==n-1){
                    if(last==-1){
                    last=i;
                    }
                }
                if(arr[i+1]!=x){
                    if(last==-1){
                    last=i;
                    }
                }
            }
        }
        v.push_back(first);
        v.push_back(last);
      return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
