#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    string s, t = "chokudai";
    cin >> s;
    int n = s.size(), mod = 1e9 + 7;

    int dp[n + 1][9];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 8; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            }
            else dp[i][j] = (dp[i - 1][j]) % mod;
        }
    }
    cout << dp[n][8];
    return 0;
}