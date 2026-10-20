class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            // Check for positive overflow before multiplying by 10: INT_MAX is 2,147,483,647
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) {
                return 0;
            }

            // Check for negative overflow before multiplying by 10: INT_MIN is -2,147,483,648
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) {
                return 0;
            }

            reversed = reversed * 10 + pop;
        }

        return reversed;
    }
};