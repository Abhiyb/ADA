#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();
    const int INF = 1e9; // Use a very large value for unreachable paths

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main() {
    int V = 4;
    const int INF = 1e9; // Define infinity here
    vector<vector<int>> matrix = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF,0, 1},
        {2, INF, INF, 0}
    };

    shortest_distance(matrix);

    for (auto row : matrix) {
        for (auto cell : row) {
            if (cell == INF)
                cout << "INF ";
            else
                cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
