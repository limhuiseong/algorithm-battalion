#include <iostream>
#include <cstring>

using namespace std;

int C, N;
int arr[100][100];
int cache[100][100];

int jump(int y, int x)
{
    if (y >= N || x >= N)
        return 0;
    if (y == N - 1 && x == N - 1)
        return 1;

    int& ret = cache[y][x];
    if (ret != -1)
        return ret;
    
    int jumpSize = arr[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

void solve()
{
    cin >> N;

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> arr[y][x];

    memset(cache, -1, sizeof(cache));
    if (jump(0, 0) == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C;

    while (C--)
        solve();

    return 0;
}