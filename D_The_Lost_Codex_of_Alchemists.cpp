#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        int remove = 1 + dp[i + 1];
        int take = INT_MAX;
        if (i + a[i] < n) {
            take = dp[i + a[i] + 1];
        }
        dp[i] = min(remove, take);
    }

    cout << dp[0] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
