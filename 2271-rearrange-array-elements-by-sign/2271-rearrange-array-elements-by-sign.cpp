class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        //Brute Force

        // vector<int> a;
        // vector<int> b;

        // for(auto i : nums){
        //     if(i < 0){
        //         a.push_back(i);
        //     }else{
        //         b.push_back(i);
        //     }
        // }

        // vector<int>ans;
        // int i = 0;
        // while( i < nums.size()/2){
        //     ans.push_back(b[i]);
        //     ans.push_back(a[i++]);
        // }
        // return ans;


        //Optimised Approach
        
        int n = nums.size();
        vector<int>ans(n,0);
        int posInd = 0;
        int negInd = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[posInd] = nums[i];
                posInd+=2;
            }else{
                ans[negInd] = nums[i];
                negInd+=2;
            }
        }
        return ans;  
    }
};