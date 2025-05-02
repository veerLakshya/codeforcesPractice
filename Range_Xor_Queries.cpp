#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ a[i - 1];

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (pre[r] ^ pre[l - 1]) << endl;
    }

    return 0;
}