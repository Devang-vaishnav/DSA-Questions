//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            vector<int>arr(26,0); 
            int mx=0,mn=0;
            for(int j = i; j < n; j++){
                int ind = s[j]-'a';
                mx=max(mx,++arr[ind]);
                if(mn >= arr[ind]-1){
                    mn = arr[ind];
                    for(int k = 0; k< 26; k++){
                        mn = min(mn,arr[k]==0?INT_MAX:arr[k]);
                    }
                }
                
                int temp = mx - mn;
                if(temp > 0) sum += temp;
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends