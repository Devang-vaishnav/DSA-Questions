class Solution {
public:
    bool isPossible(vector<int>& piles, int n, int m, int h){
        int totalHours = 0;
        for(int i = 0; i < n; i++){
            totalHours += (piles[i]/m + (piles[i]%m != 0 ? 1 : 0));
            if(totalHours > h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // if(n == 1){
        //     return piles[0];
        // }

        int s = 1;
        int e = *max_element(piles.begin(),piles.end());
        int ans = -1;

        while(s <= e){
            int m = s+(e-s)/2;
            if(isPossible(piles,n,m,h)){
                ans = m;
                e = m-1;
            }else{
                s = m+1;
            }
        }
        return ans;
    }
};