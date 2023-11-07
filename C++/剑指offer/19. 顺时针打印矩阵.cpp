#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) return res;
    int u = 0;
    int d = matrix.size() - 1;
    int l = 0;
    int r = matrix[0].size() - 1;
    while (true) {
        // 向右移动直到最右
        for (int i = l; i <= r; ++i) res.push_back(matrix[u][i]);
        // 向下移动直到最下
        if (++u > d) break;
        for (int i = u; i <= d; ++i) res.push_back(matrix[i][r]);
        // 向左移动直到最左
        if (--r < l) break;
        for (int i = r; i >= l; --i) res.push_back(matrix[d][i]);
        // 向上移动直到最上
        if (--d < u) break;
        for (int i = d; i >= u; --i) res.push_back(matrix[i][l]);
        if (++l > r) break;
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> result = spiralOrder(matrix);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
