#include <iostream>
#include <queue>

using namespace std;

int M, N;
int tomato[1002][1002];
bool visited[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs() {
    queue<pair<int, int>> q;
    int days = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
    
    while (!q.empty()) {
        int size = q.size();
        bool ripened = false;

        for (int i = 0; i < size; i++) {
            auto current = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                int nx = current.first + dx[j];
                int ny = current.second + dy[j];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (visited[nx][ny] || tomato[nx][ny] != 0)
                    continue;

                tomato[nx][ny] = 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                ripened = true;
            }
        }

        if (ripened)
            days++;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tomato[i][j] == 0)
                return -1;

    return days;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> tomato[i][j];
    
    cout << bfs() << '\n';
}