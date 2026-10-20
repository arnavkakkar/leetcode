class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        // Arrays to store the last seen positions (1-indexed) of characters
        int mapS[256] = {0};
        int mapT[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            // If the characters were not seen at the exact same previous index, return false
            if (mapS[c1] != mapT[c2]) {
                return false;
            }

            // Record the current position (+1 to distinguish from initial 0)
            mapS[c1] = i + 1;
            mapT[c2] = i + 1;
        }

        return true;
    }
};