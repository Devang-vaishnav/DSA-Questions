class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int k = n-1;
            while(k > i){
                int j = i+1;
                int m = k-1;
                while(j < m){
                    long long sum = nums[i] + nums[j];
                    sum += nums[m];
                    sum += nums[k];
                    if(sum < target){
                        j++;
                    }else if(sum > target){
                        m--;
                    }else{
                        ans.push_back({nums[i],nums[j],nums[m],nums[k]});
                        j++;
                        m--;
                        while(j < m && nums[j] == nums[j-1]) j++;
                        while(j < m && nums[m] == nums[m+1]) m--;
                    }
                }
                k--;
                while(i < k && nums[k] == nums[k+1]) k--;
            }
        }
        return ans;
    }
};