// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

void solve(int testcase) {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    auto sr = s;
    reverse(sr.begin(), sr.end());

    if (k == 0) {
        if (s < sr) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        return;
    }

    if (count(s.begin(), s.end(), s[0]) == n) {
        cout << "NO\n";
    }
    else {
        std::cout << "YES\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}