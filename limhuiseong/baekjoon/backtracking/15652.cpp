#include <iostream>

using namespace std;

int N, M;
int arr[10];

void bt(int k)
{
    if (k == M) {
        for (int i = 0; i < M; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int i;
    if (k == 0)
        i = 1;
    else
        i = arr[k - 1];

    for (; i <= N; i++) {
        arr[k] = i;
        bt(k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    bt(0);

}