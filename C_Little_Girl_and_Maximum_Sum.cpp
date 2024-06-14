#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define INF 1e9
#define NINF -1e9
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    vll pre(n, 0);   // store freq of indexes in queries
    vector<pair<ll, ll>> queries;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        pre[l]++;
        if (r + 1 < n) pre[r + 1]--;
        queries.pb({ l, r });
    }

    for (ll i = 1; i < n; i++) pre[i] += pre[i - 1]; // prefix sum of freq of indexes in queries
    vector<pair<ll, ll>> freq(n, { 0, 0 }); // store freq of freq of indexes in queries 
    for (ll i = 0; i < n; i++) freq[i] = { i, pre[i] };
    sort(freq.rbegin(), freq.rend(), [](pii a, pii b) {
        return (a.second < b.second);
        });
    for (ll i = 0; i < n; i++) b[freq[i].first] = a[i];
    ll ans = 0;
    pre.assign(n, 0);
    for (ll i = 0; i < n; i++) {
        pre[i] = b[i];
        if (i > 0) pre[i] += pre[i - 1];
    }
    for (auto q : queries) {
        ll l = q.first, r = q.second;
        ll sum = pre[r];
        if (l > 0) sum -= pre[l - 1];
        ans += sum;
    }
    cout << ans << endl;
}


int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}