class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int m = s + (e-s)/2;
        while(s <= e){
            if(nums[m] == target){
                return m;
            }else if(nums[m] < target){
                s = m+1;
            }else{
                e = m-1;
            }
            m = s + (e-s)/2;
        }
        return m;
    }
};