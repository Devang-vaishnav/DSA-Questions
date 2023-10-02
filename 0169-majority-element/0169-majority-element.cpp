class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore Voting Algo

        int n = nums.size();
        int req = n/2;
        if(n%2 != 0){
            req = n/2+1;
        }

        int cnt = 0;
        int ele;

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }else if(ele == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }

        return ele;
    }
};