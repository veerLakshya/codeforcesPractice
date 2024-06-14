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
    ll n, cost_remove, cost_add;
    cin >> n >> cost_remove >> cost_add;
    vll a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(all(a));
    ll ans = 0;
    set<ll> s;
    int duplicates = 0; // duplicates till ith index in array
    long long minCost = n * cost_remove + (a[0] == 1 ? -cost_remove : cost_add);

    // check cost to make permutation of every element and update minCost
    for (int i = 0;i < n;i++) {

        if (s.find(a[i]) == s.end()) {
            s.insert(a[i]);
        }
        else {
            duplicates++;
        }
        ll cost = 0;
        cost += duplicates * cost_remove; // remove duplicates
        cost += (n - i - 1) * cost_remove; // remove remaining elements
        cost += (a[i] - i - 1 + duplicates) * cost_add; // add elements to make permutation
        minCost = min(minCost, cost);
    }
    cout << minCost << endl;
}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}