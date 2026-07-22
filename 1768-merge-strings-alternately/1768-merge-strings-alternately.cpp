class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ch; // merged string

        for(int i = 0; i < n+m; i++){
            if(i < n){
                ch += word1[i];
            }
            if( i < m){
                ch += word2[i];
            }
        }
        return ch;
    }
};