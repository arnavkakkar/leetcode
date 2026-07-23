class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        for(int i = 1; i <= nums.size(); i++){
            if(freq.find(i) == freq.end()){
                return i;
            }
        }
        return 0;
    }
};