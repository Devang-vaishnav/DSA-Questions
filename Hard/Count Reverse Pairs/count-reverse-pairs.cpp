//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void merge(vector<int>& arr, int s, int m, int e){
        int l1 = m-s+1;
        int l2 = e-m;
        int *arr1 = new int[l1];
        int *arr2 = new int[l2];
        int k = s;
        
        for(int i = 0; i < l1; i++){
            arr1[i] = arr[k++];
        }
        for(int i = 0; i < l2; i++){
            arr2[i] = arr[k++];
        }
        
        k = s;
        int ind1 = 0;
        int ind2 = 0;
        
        while(ind1 < l1 && ind2 < l2){
            if(arr1[ind1] <= arr2[ind2]){
                arr[k++] = arr1[ind1++];
            }else{
                arr[k++] = arr2[ind2++];
            }
        }
        while(ind1 < l1){
            arr[k++] = arr1[ind1++];
        }
        while(ind2 < l2){
            arr[k++] = arr2[ind2++];
        }
    }
    
    int reversePairCalculator(vector<int>& arr, int s, int m , int e){
        int cnt = 0;
        int right = m+1;
        for(int i = s; i <= m; i++){
            while(right <= e && (arr[i] > (2*arr[right]))) right++;
            cnt += (right - (m + 1));
        }
        return cnt;
    }
    int reversePairsUsingMergeSort(vector<int>& arr, int s, int e){
        int reversePairs = 0;
        if(s < e){
            int m = s + (e-s)/2;
            reversePairs += reversePairsUsingMergeSort(arr, s, m);
            reversePairs += reversePairsUsingMergeSort(arr, m+1, e);
            reversePairs += reversePairCalculator(arr,s,m,e);
            merge(arr,s,m,e);
            
        }
        return reversePairs;
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        
        return reversePairsUsingMergeSort(arr,0,n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends