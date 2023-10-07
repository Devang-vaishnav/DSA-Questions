class Solution {
public:
    int findMinimum(vector<int>& nums, int n){
        int s = 0;
        int e = n-1;
        int m = s + (e-s)/2;
        while(s<e){
            if(nums[m] >= nums[0]){
                s = m+1;
            }else{
                e = m;
            }
            m = s + (e-s)/2;
        }
        return s;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] <= nums[n-1]){
            return nums[0];
        }
        int pivot = findMinimum(nums,n);
        return nums[pivot];
    }
};