#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
        string s; cin >> s;
        vector <bool> vis(n, false);
        vector <int> ans(n);
        for (int i = 0; i < n; i++) {
            vector <int> pos;
            int count = 0;
            int x = i;
            while (!vis[x]) {
                vis[x] = true;
                pos.push_back(x);
                if (s[x] == '0') {
                    count++;
                }
                x = p[x];
            }
            for (auto x : pos) {
                ans[x] = count;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}