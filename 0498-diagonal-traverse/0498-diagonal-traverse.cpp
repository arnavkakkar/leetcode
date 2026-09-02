class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;

        for(int d = 0; d < n + m - 1; d++){
            if(d % 2 == 0){
                int i = min(d, n - 1);
                int j = d - i;

                while(i >= 0 && j < m){
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            else{
                int j = min(d, m - 1);
                int i = d - j;

                while(j >=0 && i < n){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};