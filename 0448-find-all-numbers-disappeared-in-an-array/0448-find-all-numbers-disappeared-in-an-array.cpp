class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        vector <int> ans;

        for(int i = 1; i <= nums.size(); i++){
            if(freq.find(i) == freq.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};