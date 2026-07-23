class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        int major = 0;
        int ans;

        for(int i = 0; i < nums.size(); i++){
            if(freq[nums[i]] > major){
                major = freq[nums[i]];
                ans = nums[i];
            }
        }
        return ans;
    }
};