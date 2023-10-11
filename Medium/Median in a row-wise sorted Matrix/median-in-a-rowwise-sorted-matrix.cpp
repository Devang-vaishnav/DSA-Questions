//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int smallerEqualsCalculator(vector<vector<int>> &matrix, int n, int m, int mid){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int s = 0;
        int e = m-1;
        while(s <= e){
            int mm = (s+e) >> 1;
            if(matrix[i][mm] <= mid){
                s = mm+1;
            }else{
                e = mm-1;
            }
        }
        cnt+= s;
    }
    return cnt;
}
    int median(vector<vector<int>> &matrix, int n, int m){
        // code here          
    int s = INT_MAX;
    int e = INT_MIN;
    int req = (n*m)/2;
    for(int i = 0; i < n; i++){
        s = min(s,matrix[i][0]);
        e = max(e,matrix[i][m-1]);
    }
    
    while(s <= e){
        int mid = (s+e) >> 1;
        int smallerEquals = smallerEqualsCalculator(matrix,n,m,mid);
        if(smallerEquals <= req){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }

    return s;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends