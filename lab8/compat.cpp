#include <bits/stdc++.h>
using namespace std;

bool isOn(int N, int pos) {
    return (bool)(N & (1 << pos));
}

int turnOn(int N, int pos) {
    return (N | (1 << pos));
}

int max_comp(int n, vector<vector<int>>& compatibility, int mask, vector<int>& dp) {
    if (mask == (1 << n) - 1) {
        return 0;
    }
    if (dp[mask] != -1) {
        return dp[mask];
    }

    int max_value = 0;
    for (int i = 0; i < n; i++) {
        if (!isOn(mask, i)) {
            int current_value = compatibility[__builtin_popcount(mask)][i] + max_comp(n, compatibility, turnOn(mask, i), dp);
            max_value = max(max_value, current_value);
        }
    }

    dp[mask] = max_value;
    return max_value;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> compatibility(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> compatibility[i][j];
        }
    }

    vector<int> dp(1 << n, -1);
    int result = max_comp(n, compatibility, 0, dp);
    cout << result << endl;

    return 0;
}

