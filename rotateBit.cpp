//Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and return the results in their decimal representation after each of the rotation.
//Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000000000001100.
//
//Example 1:
//
//Input:
//N = 28, D = 2
//Output:
//112
//7
//Explanation: 
//28 in Binary is: 0000000000011100
//Rotating left by 2 positions, it becomes 0000000001110000 = 112 (in decimal).
//Rotating right by 2 positions, it becomes 0000000000000111 = 7 (in decimal).

;//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            vector <int> ans;
            
            d = d%16;
            
            ans.push_back(((n<<d)|(n>>(16-d)))&((1<<16)-1));
            ans.push_back(((n>>d)|(n<<(16-d)))&((1<<16)-1));
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends