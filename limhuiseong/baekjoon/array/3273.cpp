#include <iostream>

using namespace std;

int N, X;
int a[100001];
bool occur[2000001];
int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0 ; i < N; i++)
        cin >> a[i];
    cin >> X;

    for (int i = 0; i < N; i++) {
        int target = a[i];

        if (X - target > 0 && occur[X - target])
            cnt++;

        occur[target] = true;
    }

    cout << cnt << '\n';
}