#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dis[N][N];
bool st[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct node
{
    int x, y;
    int d;
    bool operator<(const node &a) const
    {
        return d > a.d;
    }
};
void dijkstra(int sx, int sy)
{
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    priority_queue<node> q;
    q.push((node){sx, sy, g[sx][sy]});
    dis[sx][sy] = g[sx][sy];
    while (q.size())
    {
        node t = q.top();
        q.pop();
        int x = t.x, y = t.y;
        if (st[x][y])
            continue;
        st[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                if (dis[nx][ny] > dis[x][y] + g[nx][ny])
                {
                    dis[nx][ny] = dis[x][y] + g[nx][ny];
                    q.push((node){nx, ny, dis[nx][ny]});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    dijkstra(1, 1);
    cout << dis[n][m] << endl;
    return 0;
}
