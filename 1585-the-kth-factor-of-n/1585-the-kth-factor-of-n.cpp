class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> ans;
        ans.push_back(1);
        for(int i = 2; i <= n/2; i++){
            if(n%i == 0){
                ans.push_back(i);
            }
        }
        ans.push_back(n);

        if(k <= ans.size()){
            return ans[k-1];
        }
        return -1;
    }
};