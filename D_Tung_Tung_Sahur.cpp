// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int t) {
    string s, p;
    cin >> s >> p;

    int n = s.size(), m = p.size();

    vector<pair<char, int>> a, b;

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            a.push_back({ s[i - 1], cnt });
            cnt = 1;
        }
    }
    a.push_back({ s[n - 1], cnt });

    cnt = 1;
    for (int i = 1; i < m; i++) {
        if (p[i] == p[i - 1]) cnt++;
        else {
            b.push_back({ p[i - 1], cnt });
            cnt = 1;
        }
    }
    b.push_back({ p[m - 1], cnt });

    if (a.size() != b.size()) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i].first != b[i].first) {
            cout << "NO\n";
            return;
        }
        int x = a[i].second, y = b[i].second;
        if (x > y || y > 2 * x) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}