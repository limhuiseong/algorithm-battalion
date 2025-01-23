#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_K = 100000;

int N, K;
int weights[MAX_N + 1];
int values[MAX_N + 1];
int dp[MAX_N + 1][MAX_K + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> weights[i] >> values[i];

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= K; w++) {
            if (w >= weights[i])
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i]] + values[i]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}