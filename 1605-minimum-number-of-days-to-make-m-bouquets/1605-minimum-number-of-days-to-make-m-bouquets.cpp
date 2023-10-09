class Solution {
public:
    
    bool isPossible(vector<int>& bloomDay, int n, int m, int k, int mid){
        int flowers = 0;
        int bouquets = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                flowers++;
            }else{
                bouquets += (flowers/k);
                flowers = 0;
            }
        }
        if(flowers > 0){
            bouquets += (flowers/k);
        }
        if(bouquets >= m){
            return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n/k < m){
            return -1;
        }

        int s = 1;
        int e = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(s <= e){
            int mid = s+(e-s)/2;
            if(isPossible(bloomDay,n,m,k,mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};