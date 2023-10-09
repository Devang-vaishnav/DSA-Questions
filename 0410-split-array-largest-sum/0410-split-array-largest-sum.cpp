class Solution {
public:
    bool isPossible(vector<int>& nums, int n, int m, int k){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= m){
                sum += nums[i];
            }else{
                cnt++;
                if(cnt > k || nums[i] > m){
                    return false;
                }
                sum = nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 1;
        int e = accumulate(nums.begin(),nums.end(),0);
        if(e == 0){
            return 0;
        }
        int ans = -1;

        while(s <= e){
            int m = s + (e-s)/2;
            if(isPossible(nums,n,m,k)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};