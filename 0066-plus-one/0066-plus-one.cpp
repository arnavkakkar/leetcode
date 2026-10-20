class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No further carry needed
            }
            digits[i] = 0; // 9 becomes 0 and carry continues
        }

        // If all digits were 9 (e.g., [9, 9] -> [0, 0]), result must be [1, 0, 0]
        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};