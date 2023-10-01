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
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low < high){
		int p = partition(arr, low, high);
		quickSort(arr, low, p-1);
		quickSort(arr, p+1, high);
	}
    }
    
    public:
    int partition (int input[], int start, int end)
    {
       // Your code here
        int partitionElement = input[start];
    	int count = 0;
    	
    	for(int i = start; i <= end; i++){
    		if(input[i] < partitionElement){
    			count++;
    		}
    	}
    	
    	int partitionIndex = start + count;
    	int temp = input[partitionIndex];
    	input[partitionIndex] = input[start];
    	input[start] = temp;
    
    	int ind1 = start;
    	int ind2 = end;
    	
    	while(ind1 < partitionIndex && ind2 > partitionIndex){
    		if(input[ind1] < partitionElement){
    			ind1++;
    		}else if(input[ind2] >= partitionElement){
    			ind2--;
    		}else{
    			int temp = input[ind1];
    			input[ind1] = input[ind2];
    			input[ind2] = temp;
    			ind1++;
    			ind2--;
    		}
    	}
    
    	return partitionIndex;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends