//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, long long n) {
        // code here
        
        
        long long sn = (n*(n+1))/2;
        long long s2n = (n*(n+1)*(2*n+1))/6;
        long long s1 = 0;
        long long s2 = 0;
        for(int i = 0; i < n; i++){
            s1 += (long long) arr[i];
            s2 += ((long long) (arr[i]) * (long long) arr[i]);
        }
        
        long long val1 = s1 - sn; //x-y
        long long val2 = s2 - s2n; //x^2 - y^2 or (x+y)(x-y)
        val2 = val2/val1; //x+y
        
        long long x = (val1 + val2)/2;
        long long y = val2 - x;
        
        return {(int)x,(int)y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends