class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //Brute Force
        // int mxSum = 0;
        // int sum = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i; j < nums.size(); j++){
        //         sum = 0;
        //         for(int k = i; k <= j; k++){
        //             sum += nums[k];
        //         }
        //         mxSum = max(mxSum,sum);
        //     }
        // }
        // return mxSum;


        //Kdane Algo

        int mxSum = INT_MIN;;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > mxSum){
                mxSum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return mxSum;
    }
};