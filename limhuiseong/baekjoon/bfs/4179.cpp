#include <iostream>
#include <queue>

using namespace std;

int R, C;
char maze[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int Fdist[1002][1002];
int Jdist[1002][1002];
queue<pair<int, int>> Fq, Jq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        fill(Fdist[i], Fdist[i] + C, -1);
        fill(Jdist[i], Jdist[i] + C, -1);
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'J') {
                Jdist[i][j] = 0;
                Jq.push({i, j});
            }
            else if (maze[i][j] == 'F') {
                Fdist[i][j] = 0;
                Fq.push({i, j});
            }
        }

    while (!Fq.empty()) {
        auto current = Fq.front();
        Fq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (Fdist[nx][ny] >= 0 || maze[nx][ny] == '#')
                continue;
            Fdist[nx][ny] = Fdist[current.first][current.second] + 1;
            Fq.push({nx, ny});
        }
    }

    while (!Jq.empty()) {
        auto current = Jq.front();
        Jq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                cout << Jdist[current.first][current.second] + 1 << '\n';
                return 0;
            }
            if (Jdist[nx][ny] >= 0 || maze[nx][ny] == '#')
                continue;
            if (Fdist[nx][ny] != -1 && Fdist[nx][ny] <= Jdist[current.first][current.second] + 1)
                continue;
            Jdist[nx][ny] = Jdist[current.first][current.second] + 1;
            Jq.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n";
}