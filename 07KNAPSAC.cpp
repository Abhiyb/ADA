#include <iostream>
#include <vector>
using namespace std;

int knapsackDP(vector<int>& weight, vector<int>& value, int capacity) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            int nottake = dp[i - 1][j];
            int take = 0;  

            if (weight[i - 1] <= j) {
                take = dp[i - 1][j - weight[i - 1]] + value[i - 1];
            }

            dp[i][j] = max(take, nottake);  
        }
    }

    return dp[n][capacity];
}


int main() {
    vector<int> values = {25,20,15,40,50};
    vector<int> weights = {3,2,1,4,5};
    int capacity = 6;

    int maxValue = knapsackDP(weights, values, capacity);
    cout << "Maximum value that can be achieved: " << maxValue << endl;

    return 0;
}

