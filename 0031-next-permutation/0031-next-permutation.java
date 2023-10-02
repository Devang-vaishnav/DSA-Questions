class Solution {
    public void reverse(int[] nums, int i, int j){
        while(i < j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }

    public void swap(int[] nums, int i, int ind){
        int temp = nums[i];
        nums[i] = nums[ind];
        nums[ind] = temp;
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int ind = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums,0,n-1);
            return;
        }

        for(int i = n-1; i >= 0; i--){
            if(nums[i] > nums[ind]){
                swap(nums,i,ind);
                break;
            }
        }

        reverse(nums,ind+1,n-1);
        return;
    }
}