#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)cin >> a[i][j];

    vector<vector<ll>>  dp1 = a, dp2 = a, dp3 = a, dp4 = a;

    // dp1 - max from 0, 0 (top left) to i,j
    // calc dp1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll top = (i - 1 >= 0 ? dp1[i - 1][j] : 0);
            ll left = (j - 1 >= 0 ? dp1[i][j - 1] : 0);
            dp1[i][j] += max(top, left);
        }
    }

    // dp3 - max from 0, m-1(top right) to i,j
    // calc dp3
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            ll top = (i - 1 >= 0 ? dp3[i - 1][j] : 0);
            ll right = (j + 1 < m ? dp3[i][j + 1] : 0);
            dp3[i][j] += max(top, right);
        }
    }

    // dp2 - max from n-1, 0 (bottom left) to i,j
    // calc dp2
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            ll bottom = (i + 1 < n ? dp2[i + 1][j] : 0);
            ll left = (j - 1 >= 0 ? dp2[i][j - 1] : 0);
            dp2[i][j] += max(left, bottom);
        }
    }

    // dp4 - max from n-1, m-1(bottom right) to i,j
    // calc dp4
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            ll right = (j + 1 < m ? dp4[i][j + 1] : 0);
            ll bottom = (i + 1 < n ? dp4[i + 1][j] : 0);
            dp4[i][j] += max(right, bottom);
        }
    }
    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            // p1 from top and p2 from left
            ll p1w1 = 0, p2w1 = 0;
            p1w1 = dp1[i - 1][j] + dp4[i + 1][j];
            p2w1 = dp2[i][j - 1] + dp3[i][j + 1];

            // p1 from left and p2 from bottom
            ll p1w2 = 0, p2w2 = 0;
            p1w2 = dp1[i][j - 1] + dp4[i][j + 1];
            p2w2 = dp2[i + 1][j] + dp3[i - 1][j];

            ans = max({ ans, p1w1 + p2w1, p2w2 + p1w2 });
        }
    }
    cout << ans << "\n";
}