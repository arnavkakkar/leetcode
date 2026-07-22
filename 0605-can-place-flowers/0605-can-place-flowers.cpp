class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = 0; // number of flowers which can be planted
        for (int i = 0; i < flowerbed.size(); i++){
            
            // checks starting index
            int left = (i == 0) ? 0 : flowerbed[i-1]; 
            // checks last index
            int right = (i == flowerbed.size()-1) ? 0 : flowerbed[i + 1];

            if(flowerbed[i] == 0 && left == 0 && right == 0){
                m++;
                flowerbed[i] = 1;
            }
            
            if(m >= n){
                return true;
            }
        }
        return false;
    }
};