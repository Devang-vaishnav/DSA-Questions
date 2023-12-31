class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] < nums[n-1]) return nums[0];

        int s = 0, e = n-1;
        while(s < e){
            int m = (s+e)/2;
            if(nums[m] >= nums[0]) s = m+1;
            else e = m;
        }
        return nums[e];
    }
};