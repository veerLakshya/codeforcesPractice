// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

bool h(int a, int m) {
    if (a == m) return true;
    else if (a % 3 != 0) return false;
    else return h(a / 3, m) || h(2 * a / 3, m);
}

void solve(int t) {
    int n, m;
    cin >> n >> m;

    if (h(n, m)) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}