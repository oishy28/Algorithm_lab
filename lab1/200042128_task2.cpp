#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,count =0,flag=0;
cin>>n;
vector<vector<int>> adj(n,vector<int>(n));

for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
    {
        cin>>adj[i][j];
    }


}

    for(int i=1;i<n;i++)
    {
        if(adj[count][i]==1)
        {
            count=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(count!=i && (adj[count][i]==1) || adj[i][count]==0)
        {
            flag= -1;
        }

    }

    if(flag==-1)
    {
        cout<<"There is no celebrity"<<endl;
    }
    else
    {
        cout<<"Person "<<count <<" is the celebrity";
    }
}
