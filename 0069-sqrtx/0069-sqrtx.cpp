class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long m = (long long)mid;
            long long X = (long long)x;

            if(m * m == x){
                return mid;
            }
            else if(m * m > x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high;
    }
};