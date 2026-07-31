class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse(n);
        vector<int> nse(n);

        stack<int> st;

        // PSE - Previous Smaller Element
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // NSE - Next Smaller Element
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }

        // Max Area
        int maxa = 0;
        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;

            maxa = max(area, maxa);
        }

        return maxa;
    }
};