#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[502][502];
bool visited[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int num = 0;
int max_area = 0;

void bfs(int x, int y)
{
    if (visited[x][y] || board[x][y] == 0)
        return;
    visited[x][y] = true;
    num++;

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int area = 0;

    while (!q.empty()) {
        area++;
        pair<int, int> current = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (visited[nx][ny] || board[nx][ny] == 0)
                continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    }

    if (area > max_area)
        max_area = area;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            bfs(i, j);

    cout << num << '\n' << max_area << '\n';
}