//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool static comparator(vector<int> a, vector<int> b){
        if(a[0] < b[0]) return true;
        else if(a[0] > b[0]) return false;
        else{
            if(a[1] < b[1]) return true;
            else return false;
        }
    }
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>>ans;
         int n = intervals.size();
         sort(intervals.begin(),intervals.end(),comparator);
         vector<int> temp(intervals[0].begin(),intervals[0].end());
         for(int i = 1; i < n; i++){
             if(temp[1] >= intervals[i][0]){
                 temp[0] = min(temp[0],intervals[i][0]);
                 temp[1] = max(temp[1],intervals[i][1]);
             }else{
                 ans.push_back(temp);
                 temp[0] = intervals[i][0];
                 temp[1] = intervals[i][1];
             }
         }
         ans.push_back(temp);
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends