#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int in[10];
int arr[10];
bool used[100000];

void bt(int k)
{
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[in[i]]) {
            arr[k] = in[i];
            used[in[i]] = true;
            bt(k + 1);
            used[in[i]] = false;
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
}