#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool used[10];

void bt(int k, int start)
{
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = start; i <= N; i++) {
        if (!used[i]) {
            arr[k] = i;
            used[i] = true;
            bt(k + 1, i + 1);
            used[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    bt(0, 1);
}