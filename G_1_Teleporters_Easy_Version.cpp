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
    ll n, coins;
    cin >> n >> coins;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    vll b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] + i + 1;
    }
    sort(all(b));
    for (int i = 0; i < n; i++) {
        if (coins - b[i] < 0) {
            break;
        }
        coins -= b[i];
        ans++;
    }
    cout << ans << endl;

}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}