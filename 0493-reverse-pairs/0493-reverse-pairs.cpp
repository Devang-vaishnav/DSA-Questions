class Solution {
public:

    int countRevPairs(vector<int>&a, int s, int m , int e){
        int right = m + 1;
        int cnt = 0;
        for(int i = s; i <= m; i++){
            while(right <= e && (a[i] > (2*(long long)a[right]))) right++;
            cnt += (right - (m+1));
        }
        return cnt;
    }

    void merge(vector<int>&a, int s, int e){

        int m = s + (e-s)/2;
        int l1 = m-s+1;
        int l2 = e-m;
        int *arr1 = new int[l1];
        int *arr2 = new int[l2];

        int k = s;
        for(int i = 0; i < l1; i++){
            arr1[i] = a[k++];
        }

        for(int i = 0; i < l2; i++){
            arr2[i] = a[k++];
        }

        int ind1 = 0;
        int ind2 = 0;
        k = s;

        while(ind1 < l1 && ind2 < l2){
            if(arr1[ind1] <= arr2[ind2]){
                a[k++] = arr1[ind1++];
            }else{
                a[k++] = arr2[ind2++];
            }
        }

        while(ind1 < l1){
            a[k++] = arr1[ind1++];
        }

        while(ind2 < l2){
            a[k++] = arr2[ind2++];
        }
        delete []arr1;
        delete []arr2;
    }

    int countReversePairsUsingMergeSort(vector<int>&a, int s, int e){
        int revPairs = 0;
        if(s < e){
            int m = s + (e-s)/2;
            revPairs += countReversePairsUsingMergeSort(a,s,m);
            revPairs += countReversePairsUsingMergeSort(a,m+1,e);
            revPairs += countRevPairs(a,s,m,e);
            merge(a,s,e);
        }
        return revPairs;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return countReversePairsUsingMergeSort(nums,0,n-1);
    }
};