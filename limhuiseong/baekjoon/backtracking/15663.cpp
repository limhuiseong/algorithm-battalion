#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int in[10];
int arr[10];
bool used[10];

void bt(int k)
{
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int last = -1;
    for (int i = 0; i < N; i++) {
        if (!used[i] && in[i] != last) {
            arr[k] = in[i];
            used[i] = true;
            bt(k + 1);
            used[i] = false;
            last = in[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }

    sort(in, in + N);

    bt(0);

    return 0;
}