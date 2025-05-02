#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);
    ll i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (b[j])
    }
}