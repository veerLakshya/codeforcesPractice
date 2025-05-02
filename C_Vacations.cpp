#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    // 0 - rest, 1 - contest, 2 - gym

    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == 0) {
            for (int j = 0; j < 3; j++)
                dp[i][j] = 1 + min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] });
        }
        else if (a[i - 1] == 1) {
            dp[i][0] = 1 + min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] });
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = 1 + min(dp[i - 1][1], dp[i - 1][0]);
        }
        else if (a[i - 1] == 2) {
            dp[i][0] = 1 + min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] });
            dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
        }
        else {
            dp[i][0] = 1 + min({ dp[i - 1][0],dp[i - 1][1],dp[i - 1][2] });
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
        }
    }
    int ans = n;
    for (int i = 0; i < 3; i++) ans = min(ans, dp[n][i]);
    cout << (ans);
}