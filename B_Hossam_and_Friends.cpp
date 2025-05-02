// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    int n, m;
    cin >> n >> m;

    map<int, set<int>> mp;
    multiset<int> st;

    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        mp[x].insert(y);
    }

    int l = 1, ans = 0;
    for (int r = 1; r <= n; r++) {
        while (st.find(r) != st.end()) {
            if (mp.find(l) != mp.end())
                st.erase(st.find(*mp[l].begin()));
            l++;
        }
        ans += (r - l + 1);
        if (mp.find(r) != mp.end()) {
            st.insert(*mp[r].begin());
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}