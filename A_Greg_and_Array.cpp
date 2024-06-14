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


// Problem for difference prefix array technique

void solve() {
    ll n, m, k; //n - size of array, k - number of queries, m - number of operations
    cin >> n >> m >> k;

    vector<ll> a(n + 2, 0);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    vector<pair<pair<ll, ll>, ll>> operations(m + 2); // ith operation will add d to all elements from l to r
    for (int i = 1;i <= m;i++) {
        cin >> operations[i].ff.ff >> operations[i].ff.ss >> operations[i].ss;
    }

    vector<int>freq(m + 2, 0);
    while (k--) {
        ll l, r;
        cin >> l >> r;
        freq[l]++;
        freq[r + 1]--;
    }
    for (int i = 1;i <= m;i++) {
        freq[i] += freq[i - 1];
    }
    vector<ll> prefix(n + 2, 0);
    for (int i = 1;i <= m;i++) {
        if (freq[i] > 0) {
            ll l = operations[i].ff.ff;
            ll r = operations[i].ff.ss;
            ll d = operations[i].ss;
            prefix[l] += freq[i] * d;
            prefix[r + 1] -= freq[i] * d;
        }
    }
    for (int i = 1;i <= n;i++) {
        prefix[i] += prefix[i - 1];
        // cout << prefix[i] << " ";
        a[i] += prefix[i];
    }
    cout << endl;
    for (int i = 1;i <= n;i++) {
        cout << a[i] << " ";

    }
}

int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}