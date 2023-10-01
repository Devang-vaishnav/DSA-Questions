//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int r)
    {
         // Your code here
         int m = l + ((r-l)/2);
        int s1 = m-l + 1;
        int s2 = r-m;
        
        int *arr1 = new int[s1];
        int *arr2 = new int[s2];
        
        int s = l;
        int ind = 0;
        for(int i = s; i <= m; i++){
            arr1[ind++] = arr[i];
        }
    
        s = m+1;
        ind = 0;
        for(int i = s; i <= r; i++){
            arr2[ind++] = arr[i];
        }
        
        int ind1 = 0;
        int ind2 = 0;
        ind = l;
        
        while(ind1 < s1 && ind2 < s2){
            if(arr1[ind1] <= arr2[ind2]){
                arr[ind++] = arr1[ind1++];
            }else{
                arr[ind++] = arr2[ind2++];
            }
        }
    
        while(ind1 < s1){
            arr[ind++] = arr1[ind1++];
        }
        while(ind2 < s2){
            arr[ind++] = arr2[ind2++];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if( l >= r ){
            return;
        }
        
        int m = l + ((r-l)/2);
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr,l,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends