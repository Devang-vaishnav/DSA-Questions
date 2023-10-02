class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;

        while(j < nums.size() && i < nums.size()){
            if(nums[i] != 0){
                i++;
            }else if(nums[j] == 0){
                j++;
            }else{
                if(i < j){
                    swap(nums[i], nums[j]);
                    i++;
                }
                j++;
            }
        }
    }
};