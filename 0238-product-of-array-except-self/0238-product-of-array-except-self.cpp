class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long long prod = 1;
        for(int i = 0; i < n; i++){
            prod *= nums[i];
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                long long prod0 = 1;
                for(int j = 0; j < n; j++){
                    if(j==i) continue;
                    prod0 *= nums[j];
                }
                ans.push_back((int)prod0);
            }else{
                ans.push_back((int)prod/nums[i]);
            }
        }

        return ans;
    }
};