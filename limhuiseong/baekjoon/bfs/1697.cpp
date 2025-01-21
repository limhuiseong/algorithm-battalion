#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;
int dist[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    fill(dist, dist + 100001, -1);
    dist[N] = 0;
    q.push(N);

    while (dist[K] == -1) {
        auto current = q.front();
        q.pop();

        for (int i : {current - 1, current + 1, current * 2}) {
            if (i < 0 || i > 100000)
                continue;
            if (dist[i] != -1)
                continue;
            dist[i] = dist[current] + 1;
            q.push(i);
        }
    }
    cout << dist[K] << '\n';
}