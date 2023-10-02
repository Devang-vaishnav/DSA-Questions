class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //One Line Solution
        //next_permutation(nums.begin(),nums.end());

        // Implementation of next_permutation STL Method
        int n = nums.size();
        int ind = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i = n-1; i >= 0; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        reverse(nums.begin()+ind+1,nums.end());
        return;
    }
};