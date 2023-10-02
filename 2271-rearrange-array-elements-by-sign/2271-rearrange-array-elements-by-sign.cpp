class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> a;
        vector<int> b;

        for(auto i : nums){
            if(i < 0){
                a.push_back(i);
            }else{
                b.push_back(i);
            }
        }

        vector<int>ans;
        int i = 0;
        while( i < nums.size()/2){
            ans.push_back(b[i]);
            ans.push_back(a[i++]);
        }
        return ans;
    }
};