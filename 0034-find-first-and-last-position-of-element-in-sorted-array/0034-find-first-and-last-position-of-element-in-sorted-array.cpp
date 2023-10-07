class Solution {
public:
    int startingIndex(vector<int>& nums, int target){
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int ans = -1;
        int m = s + (e-s)/2;
        while(s <= e){
            if(nums[m] == target){
                ans = m;
                e = m-1;
            }else if(nums[m] < target){
                s = m+1;
            }else{
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }

    int endingIndex(vector<int>& nums, int target){
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int m = s + (e-s)/2;
        int ans = -1;
        while(s <= e){
            if(nums[m] == target){
                ans = m;
                s = m+1;
            }else if(nums[m] < target){
                s = m+1;
            }else{
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {startingIndex(nums,target),endingIndex(nums,target)};
    }
};