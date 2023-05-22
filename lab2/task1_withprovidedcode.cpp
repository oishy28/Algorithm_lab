#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define pii pair<int, int>

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int row, col;
int vis[100][100];
int d[100][100];

void bfs(int sx, int sy) {
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    queue<pii> q;
    q.push(pii(sx, sy));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int tx = x + fx[k];
            int ty = y + fy[k];

            if (tx >= 0 && tx < row && ty >= 0 && ty < col && vis[tx][ty] == 0) {
                vis[tx][ty] = 1;
                d[tx][ty] = d[x][y] + 1;
                q.push(pii(tx, ty));
            }
        }
    }
}

int main() {
    cin >> row >> col;
    // Input the grid
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }

    int sourceX, sourceY;
    cin >> sourceX >> sourceY;

    bfs(sourceX, sourceY);


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


