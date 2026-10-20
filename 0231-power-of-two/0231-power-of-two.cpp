class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of two has strictly 1 bit set and must be positive
        return n > 0 && (n & (n - 1)) == 0;
    }
};