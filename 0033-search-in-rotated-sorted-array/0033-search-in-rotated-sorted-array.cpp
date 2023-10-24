class Solution {
public:
    int pivotIndex(vector<int>& nums){
        int s = 0;
        int e = nums.size()-1;
        while(s < e){
            int m = s+(e-s)/2;
            if(nums[m] >= nums[0]) s = m+1;
            else e = m;
        }
        return e;
    }

    int isExist(vector<int>& nums, int target, int s, int e){
        while(s <= e){
            int m = s+(e-s)/2;
            if(nums[m] == target) return m;
            else if(nums[m] < target) s = m+1;
            else e = m-1;
        }
        return -1;;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        int pvInd = pivotIndex(nums);
        if(target >= nums[0] && target <= nums[pvInd-1]) return isExist(nums,target,0,pvInd-1);
        return isExist(nums,target,pvInd,n-1);
    }
};