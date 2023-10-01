class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(cnt == nums[i]){
                nums[i] = 101;
            }else{
                cnt = nums[i];
            }
        }

        sort(nums.begin(),nums.end());
        int ans = 0;
        for(auto i : nums){
            if(i == 101){
                return ans;
            }else{
                ans++;
            }
        }
        return ans;
    }
};