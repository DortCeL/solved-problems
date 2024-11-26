#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int N = 4; // Number of cities
const int source = 0;

int cost[N][N] = {
    {0, 10, 15, 20},
    {5, 0, 9, 10},
    {6, 13, 0, 12},
    {8, 8, 9, 0}
};

int dp[1 << N][N];

int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) {
        return cost[pos][source];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    int result = tsp(1, source);

    cout << "The minimum cost is: " << result << endl;

    return 0;
}
