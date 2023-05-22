#include<bits/stdc++.h>
using namespace std;

int n;
int coin_array[100];

int dp[100][100];

int coin_change(int i,int w)
{
    if(w==0) return 1;
    else if(i==n or w<0) return 0;
    else return coin_change(i+1,w)+ coin_change(i,w-coin_array[i]);
}

int main()
{

    int w;
    cin >> w >> n;
    for(int i = 0; i < n; i++)
        cin >> coin_array[i];

    cout << coin_change(0,w);
}
