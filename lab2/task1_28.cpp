#include <bits/stdc++.h>
using namespace std;


struct Square {
    int row, col;
};

bool isValid(int row, int col) {
    return (row >= 0 && row < 8 && col >= 0 && col < 8);
}

int bfs(Square start, Square end) {
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    bool visited[8][8];
    memset(visited, false, sizeof(visited));

    queue<pair<Square, int>> q;
    q.push({start, 0});
    visited[start.row][start.col] = true;

    while (!q.empty()) {
        Square currSquare = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (currSquare.row == end.row && currSquare.col == end.col) {
            return dist;
        }

        for (int i = 0; i < 8; i++) {
            int newRow = currSquare.row + dx[i];
            int newCol = currSquare.col + dy[i];

            if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push({{newRow, newCol}, dist + 1});
            }
        }
    }

    return -1;  // If no path is found
}

int main() {
    string startSquare, endSquare;

    while (cin >> startSquare >> endSquare) {
        Square start, end;
        start.row = startSquare[1] - '1';
        start.col = startSquare[0] - 'a';
        end.row = endSquare[1] - '1';
        end.col = endSquare[0] - 'a';

        int moves = bfs(start, end);

        cout << "To get from " << startSquare << " to " << endSquare << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}

