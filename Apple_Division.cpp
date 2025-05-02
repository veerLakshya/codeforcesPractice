#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// int main() {
//     ll n;
//     cin >> n;
//     vector<ll> a(n);
//     ll sum = 0;
//     for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
//     ll ans = 1e18;

//     function<void(ll, ll)> helper = [&](ll ind, ll g1)->void {
//         if (ind == n) {
//             ll g2 = sum - g1;
//             ans = min(ans, abs(g1 - g2));
//             return;
//         }
//         helper(ind + 1, g1 + a[ind]);
//         helper(ind + 1, g1);
//         };

//     helper(0, 0);

//     cout << ans;

//     return 0;
// }


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = LLONG_MAX;
    // 1 << n same as 2^n
    for (ll mask = 0; mask < (1 << n); mask++) {
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum1 += a[i];
            else sum2 += a[i];
        }
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans;
}