class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int reqForMajority = n/2;
        if(n % 2 != 0){
            reqForMajority = n/2+1;
        }
        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                if(cnt >= reqForMajority){
                    return nums[i-1];
                }
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        if(cnt >= reqForMajority){
            return nums[n-1];
        }
        return -1;
    }
};