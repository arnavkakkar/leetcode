class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;

        int num = 0;
        string curr = "";

        for(char ch : s){
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            else if(ch == '['){
                st.push({num,curr});
                num = 0;
                curr = "";
            }
            else if(ch == ']'){
                auto [count, previous] = st.top();
                st.pop();

                string temp = "";

                while(count--){
                    temp += curr;
                } 
                curr = previous + temp;
            }
            else{
                curr += ch;
            }
        }
        return curr;
    }
};