class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++){
            if(temp[1] >= intervals[i][0]){
                temp[1] = intervals[i][1] > temp[1] ? intervals[i][1] : temp[1]; 
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