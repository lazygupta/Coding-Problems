//Simple implementation problem

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> row(rows, INT_MAX);
        vector<int> col(cols, INT_MIN);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int el = matrix[i][j];
                row[i] = min(row[i], el);
                col[j] = max(col[j], el);
            }
        }
        vector<int> v;
        for (int i = 0; i < row.size(); i++) {
            if (find(col.begin(), col.end(), row[i]) != col.end()) {
                v.push_back(row[i]);
            }
        }
        return v;
    }
};