#include<bits/stdc++.h>
using namespace std;
vector<int> arr[110];
bool check[110];
// here i cant implement the self loop

void dfs(int x){
    check[x]=true;
    for(int i=0;i<arr[x].size();i++){
        int y=arr[x][i];
        if(check[y]==false) dfs(y);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
    }
    int t;
    cin>>t;
    while(t--){
        memset(check,false,sizeof(check));
        int s;
        cin>>s;
        dfs(s);
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(check[i]==false) cnt++;
        cout<<cnt;
        for(int i=1;i<=n;i++)
            if(check[i]==false) cout<<" "<<i;
        cout<<endl;
    }
    return 0;
}
