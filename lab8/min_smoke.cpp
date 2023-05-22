#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9+7;
int minimum_smoke(int n,int colors[])
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            int j=i+l-1;
            dp[i][j]=MOD;
            for(int k=i;k<j;k++)
            {
                int generated_smoke=dp[i][k] + dp[k+1][j] + ((accumulate(colors+i, colors+k+1, 0) % 100) * (accumulate(colors+k+1, colors+j+1, 0) % 100));
                dp[i][j]=min(dp[i][j],generated_smoke);
            }
        }
    }
    return dp[0][n-1];

}

int main()
{
    int n;

    while (cin>>n)
    {
        int colors[n];
        for(int i=0;i<n;i++)
        {
            cin>> colors[i];
        }
        cout << minimum_smoke(n,colors)<<endl;
    }
    return 0;
}
