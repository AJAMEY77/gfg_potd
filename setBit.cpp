//
//Given an integer N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
//Note: If there is no set bit in the integer N, then return 0 from the function.  
//
//Example 1:
//
//Input: 
//N = 18
//Output: 
//2
//Explanation: 
//Binary representation of 18 is 010010,the first set bit from the right side is at position 2.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

unsigned int getfirstsetBit(int n)
{
	int b = -n;
	int c = n&b;
	
	if(c==0)
	{
		return 0;
	}
	cout<<log2(c)+1;
	
}

int main()
{
	getfirstsetBit(18);
}