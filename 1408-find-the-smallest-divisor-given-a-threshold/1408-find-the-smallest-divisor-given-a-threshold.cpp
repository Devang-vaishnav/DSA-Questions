class Solution {
public:
    bool isPossible(vector<int>& nums, int n, int threshold, int m){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ((nums[i]/m) + (nums[i]%m ? 1:0));
            if(sum > threshold){
                return false;
            }
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(s <= e){
            int m = s +(e-s)/2;
            if(isPossible(nums,n,threshold,m)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};