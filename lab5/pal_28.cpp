#include<bits/stdc++.h>
using namespace std;

int find_palindrom(string s) {
    int n = s.length();
    int dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (s[i] == s[j] && k == 2) {
                return 2;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
}



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << s.length() - find_palindrom(s) << endl;
    return 0;
}
