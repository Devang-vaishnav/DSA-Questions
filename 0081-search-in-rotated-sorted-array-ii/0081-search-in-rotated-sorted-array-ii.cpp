class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(arr[m] == k){
                return true;
            }

            if(arr[s] == arr[m] && arr[m] == arr[e]){
                s++;
                e--;
                continue;
            }

            if(arr[m] >= arr[s]){
                if(k >= arr[s] && k <= arr[m]){
                    e = m-1;
                }else{
                    s = m+1;
                }
            }else{
                if(k >= arr[m+1] && k <= arr[e]){
                    s = m+1;
                }else{
                    e = m-1;
                }
            }
        }
        return false;
    }
};