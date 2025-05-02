#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> tree[n + 1], dp(n + 1), subsz(n + 1, 1);

    for (ll i = 1; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    function<ll(ll, ll, ll)> dfs = [&](ll cur, ll par, ll dis)->ll {
        ll val = dis;
        for (auto nbr : tree[cur]) {
            if (nbr == par) continue;
            val += dfs(nbr, cur, dis + 1);
            subsz[cur] += subsz[nbr];
        }
        return val;
        };

    function<void(ll, ll, ll)> reroot = [&](ll cur, ll par, ll ans)->void {
        dp[cur] = ans;
        for (ll nbr : tree[cur]) {
            if (nbr == par) continue;
            reroot(nbr, cur, ans + n - 2 * subsz[nbr]);
        }
        };

    reroot(1, 1, dfs(1, -1, 0));

    for (ll i = 1; i <= n; i++) cout << dp[i] << " ";
}