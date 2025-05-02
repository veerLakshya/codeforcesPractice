#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> homes(k);
    for (int i = 0; i < k; i++) cin >> homes[i], homes[i]--;

    set<int> home(homes.begin(), homes.end());

    vector<vector<int>> edj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edj[x].push_back(y);
        edj[y].push_back(x);
    }

    vector<int> a1, a2, vis(n, 0);
    // a1 - array for sizes of components having home
    // a2 - array for sizes of components not having homes

    bool flag = false;
    auto dfs = [&](int i, auto self)->int {
        vis[i] = 1;
        flag |= home.count(i);

        int temp = 1;
        for (auto nbr : edj[i]) {
            if (vis[nbr])continue;
            temp += self(nbr, self);
        }

        return temp;
        };

    for (int i = 0; i < n; i++) {
        if (vis[i])continue;
        flag = false;
        int ans = dfs(i, dfs);
        if (flag)a1.push_back(ans);
        else a2.push_back(ans);
    }

    int ans = 0, maxi = *max_element(a1.begin(), a1.end()), suma2 = accumulate(a2.begin(), a2.end(), 0);
    for (auto& cur : a1) {
        if (cur == maxi) {
            cur += suma2;
            suma2 = 0;
        }
        ans += (cur) * (cur - 1) / 2;
    }
    cout << ans - m;
}