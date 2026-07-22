class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxc = 0; 
        int sum = 0;
        vector<bool> gr8;

        for(int i = 0; i < candies.size(); i++){
            maxc = max(candies[i], maxc);
        }

        for(int i = 0; i < candies.size(); i++){
            sum = candies[i] + extraCandies;
            if(maxc <= sum){
                gr8.push_back(true);
            }
            else{
                gr8.push_back(false);
            }
        }
        return gr8;
    }
};