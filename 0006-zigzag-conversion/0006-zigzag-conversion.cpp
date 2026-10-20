class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Base case: if 1 row or string length is less than numRows, zigzag pattern is identical to original string
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        std::vector<std::string> rows(std::min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            // Reverse direction when hitting the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into one final string
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};