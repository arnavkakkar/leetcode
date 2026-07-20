class Solution {
public:
    bool isAnagram(int freq[]) {

        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0)
            return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans; 
        int freq[26] = {0};
        
        //Count characters in p
        for(char ch : p){
            freq[ch - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            // Char enters the window
            freq[s[i] - 'a']--;

            // Char leaves the window
            if(i >= p.size()) {
                freq[s[i - p.size()] - 'a']++;
            }

            if(i >= p.size() - 1){
                if(isAnagram(freq)){
                    ans.push_back(i - p.size() + 1);
                }
            }
        }
        return ans;
    }
};