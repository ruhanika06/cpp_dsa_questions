#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> grid;
vector<vector<int>> visited;

void dfs(int x, int y) {
    // mark visited
    visited[x][y] = 1;

    // 4 possible movement directions
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        // check boundaries + land + not visited
        if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
            grid[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> M >> N;

    grid.assign(M, vector<int>(N));
    visited.assign(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    int islands = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            // if we find an unvisited land → new island
            if (grid[i][j] == 1 && !visited[i][j]) {
                islands++;
                dfs(i, j);
            }
        }
    }

    cout << islands;
}
