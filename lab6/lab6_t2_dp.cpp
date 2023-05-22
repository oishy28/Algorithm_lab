#include<bits/stdc++.h>
#include<cstring>
#include<cmath>

using namespace std;

const int MAXN= 16;

int n;
int mat[MAXN][MAXN];
int dp[1<< MAXN][MAXN];

bool isOn(int N, int pos)
{
    return(bool)(N & (1<< pos));
}

int turnOn(int N, int pos)
{
    return(N | (1<<pos));
}

int f(int mask, int k)
{
    if (mask == (1<<n)-1) return 0;
    if (dp[mask][k] != -1) return dp[mask][k];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if (isOn(mask,i)) continue;
        ans = max(ans, mat[k][i] + f(turnOn(mask, i), k + 1));
    }
    return dp[mask][k]=ans;
}

int solve() {
    memset(dp, -1, sizeof(dp)); // initialize memoization table
    return f(0, 0);
}

int main() {
    int t = 1;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        cout  << solve() << endl;
        t++;
    }
    return 0;
}
