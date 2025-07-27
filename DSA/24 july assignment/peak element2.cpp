class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int i = m/2, j = n/2;
        while (i >= 0 && i <= m && j >= 0 && j <= n)
        {
            if (i > 0 && matrix[i - 1][j] > matrix[i][j]) i--;
            else if (i < m && matrix[i + 1][j] > matrix[i][j]) i++;
            else if (j > 0 && matrix[i][j - 1] > matrix[i][j]) j--;
            else if (j < n && matrix[i][j + 1] > matrix[i][j]) j++;
            else break;
        }
        return {i, j};
    }
};