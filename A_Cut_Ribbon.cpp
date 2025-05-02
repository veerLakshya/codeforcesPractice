#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1);
    function<int(int)> h = [&](int i)->int {
        if (i == 0) return dp[i] = 0;
        if (i < 0) return INT_MIN;
        if (dp[i] != -1) return dp[i];
        dp[i] = 1 + max({ h(i - a),h(i - b),h(i - c) });
        return dp[i];
        };
    // for (int i = 0; i < n; i++) cout << dp[i] << " ";
    cout << h(n);
}