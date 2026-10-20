class Solution {
public:
    string intToRoman(int num) {
        // Pairs of Roman symbols and their corresponding values in descending order
        const pair<int, string> valToSymbol[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string result = "";

        for (const auto& [val, sym] : valToSymbol) {
            if (num == 0) break;

            while (num >= val) {
                result += sym;
                num -= val;
            }
        }

        return result;
    }
};