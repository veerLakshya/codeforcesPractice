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
    ll x, a;
    cin >> x >> a;
    if (x == a) {
        cout << "infinity" << endl;
        return;
    }
    ll count = 0;
    x = x - a;
    for (ll i = 1;i * i <= x;i++) {
        if (x % i == 0) {
            if (i > a) {
                count++;
            }
            if (x / i != i && x / i > a) {
                count++;
            }
        }
    }
    cout << count << endl;
}
// x mod y = a
// we have to find possible values of y
// x mod y = a
// x = y * q + a
// x - a = y * q
// y = (x - a) / q

int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}