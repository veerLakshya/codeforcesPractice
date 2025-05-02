#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    ll dp[n + 1]{ 0 };
    dp[1] = ((s[0] - '0') % 4 == 0);
    for (int i = 2; i <= n;i++) {
        dp[i] += dp[i - 1];
        int cur = s[i - 1] - '0';
        if (cur % 4 == 0) {
            dp[i] += 1;
        }
        int last = s[i - 2] - '0';
        if ((last * 10 + cur) % 4 == 0) dp[i] += (i - 1);
        // cout << i - 1 << " " << dp[i - 1] << endl;;
    }
    // for (int i = 0; i <= n; i++) cout << dp[i] << " ";
    cout << endl;
    cout << dp[n];
    return 0;
}