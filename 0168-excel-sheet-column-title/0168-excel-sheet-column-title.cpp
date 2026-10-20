class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            // Decrement by 1 to adjust for 1-based indexing (1 = 'A', 26 = 'Z')
            columnNumber--;
            result += (char)('A' + (columnNumber % 26));
            columnNumber /= 26;
        }

        // Reverse since characters were extracted from least significant to most
        reverse(result.begin(), result.end());

        return result;
    }
};