//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int mxLen= 0;
	    long long int sum = 0;
	    unordered_map<int,int>mp;
	    int rem = 0;
	    for(int i = 0; i < n; i++){
	        sum += arr[i];
	        rem = sum%k;
	        if(rem == 0) mxLen=max(mxLen,i+1);
	        if(rem < 0) rem += k;
	        if(mp.find(rem) == mp.end()) mp[rem] = i;
	        else mxLen= max(mxLen,(i-mp[rem]));
	    }
	    return mxLen;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends