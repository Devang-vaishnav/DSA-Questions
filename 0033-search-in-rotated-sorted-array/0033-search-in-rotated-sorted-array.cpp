class Solution {
public:
    int searchPivot(vector<int>& nums,int n){
        int s = 0; int e = n-1;
        int m = s + (e-s)/2;
        while(s <= e){
            if(nums[m] >= nums[0]){
                s = m+1;
            }else{
                e = m-1;
            }
            m = s+(e-s)/2;
        }
        return m;
    }

    int binarySearch(vector<int>& nums, int target, int s, int e){
        int m = s+(e-s)/2;
        while(s <= e){
            if(nums[m] == target){
                return m;
            }else if(nums[m] < target){
                s = m+1;
            }else{
                e = m-1;
            }
            m = s+(e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n =  nums.size();
        int pivot = searchPivot(nums,n);
        cout<<pivot<<" ";
        if(target >= nums[0]) return binarySearch(nums,target,0,pivot-1);
        return binarySearch(nums,target,pivot,n-1);
    }
};