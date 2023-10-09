//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


bool isPossible(int boards[], int n, long long time, int k){
    long long painter = 1;
    long long totalTime = 0;
    for(int i = 0; i < n; i++){
        if(totalTime + boards[i] <= time){
            totalTime += boards[i];
        }else{
            painter++;
            if(painter > k || boards[i] > time){
                return false;
            }
            totalTime = boards[i];
        }
    }
    return true;
}


class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
    long long s = 0;
    long long e = 0;
    for(int i = 0; i < n; i++){
        e += arr[i];
    }
    long long ans = -1;

    while(s <= e){
        long long m = s+(e-s)/2;
        if(isPossible(arr,n,m,k)){
            ans = m;
            e = m-1;
        }else{
            s = m+1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends