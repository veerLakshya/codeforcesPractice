#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    int f = 0, prev = -1e9;
    for (int i = 0; i < n; i++) {
        int beg = 0, end = m - 1;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (b[mid] - a[i] >= prev)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        int x = a[i], y = a[i];
        if (beg != m)
            y = b[beg] - a[i];
        int mn = min(x, y), mx = max(x, y);
        if (mn >= prev)
            a[i] = mn;
        else if (mx >= prev)
            a[i] = mx;
        else
            f = 1;
        prev = a[i];
    }
    cout << (f == 0 ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}