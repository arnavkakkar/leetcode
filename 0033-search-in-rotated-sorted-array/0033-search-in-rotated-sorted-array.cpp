class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                return mid;
            }

            //Checking if the left halft of array is sorted
            if(nums[low] <= nums[mid]){
                // Checking for the element in left half
                if(target < nums[mid] && nums[low] <= target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{ // Element lies in the right half.
                //Check for element in right half
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};