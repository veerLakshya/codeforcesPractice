#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n);
        for (int i = 1; i < n; i++) {
            int x; cin >> x;
            x--;
            a[x].push_back(i);
            a[i].push_back(x);
        }
        string s; cin >> s;
        int ans = 0;
        auto dfs = [&](int cur, int par, auto self)->pair<int, int> {
            // cout << cur << " ";
            int w = (s[cur] == 'W');
            int b = (s[cur] == 'B');
            for (auto nbr : a[cur]) {
                if (nbr != par) {
                    pair<int, int> subtree = self(nbr, cur, self);
                    w += subtree.first;
                    b += subtree.second;
                }
            }
            if (w == b) ans++;
            return { w,b };
            };
        pair<int, int> r = dfs(0, -1, dfs);
        cout << ans << endl;
    }
}