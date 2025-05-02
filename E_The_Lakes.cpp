#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0)), vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> dx = { 0, 0, 1, -1 }, dy = { 1, -1, 0, 0 };
    auto dfs = [&](int i, int j, auto& self)-> int {
        vis[i][j] = 1;
        int val = a[i][j];
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && y >= 0 && x < n && y < m && a[x][y] && !vis[x][y]) val += self(x, y, self);
        }
        return val;
        };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && a[i][j] != 0) {
                int cur = dfs(i, j, dfs);
                // cout << i << " " << j << ": " << cur << endl;
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << " \n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}