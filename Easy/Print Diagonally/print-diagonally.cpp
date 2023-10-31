//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int> ans;
		for(int j = 0; j < N; j++){
		    int col = j;
		    int row = 0;
		    while(row < N && col >= 0){
		        ans.push_back(A[row][col]);
		        row++;
		        col--;
		    }
		}
		
		for(int i = 1; i < N; i++){
		    int row = i;
		    int col = N-1;
		    while(col >= 0 && row < N){
		        ans.push_back(A[row][col]);
		        row++;
		        col--;
		    }
		}
		
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends