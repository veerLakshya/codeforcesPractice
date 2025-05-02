#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll right = 0, cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (cur < m && right < n) {
            cur += a[right];
            right++;
        }
        if (cur == m) ans++;
        cur -= a[i];
    }
    cout << ans;
}