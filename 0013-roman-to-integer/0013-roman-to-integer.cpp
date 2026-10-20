class Solution {
private:
    int value(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }

public:
    int romanToInt(string s) {
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentVal = value(s[i]);

            // If the next symbol has a larger value, subtract current (e.g., IV = 4, IX = 9)
            if (i + 1 < n && currentVal < value(s[i + 1])) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }

        return total;
    }
};