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
    ll n, m;
    cin >> n >> m;
    ll  ans = 0;
    for (ll i = 1; i <= n; i++) {

    }
    cout << ans << endl;
}
// (a + b) % (b * y) == 0 : y = gcd(a , b);
// (a + b) should be a multiple of b
// (a + b) % b == 0
// a % b == 0 -> a should be a multiple of b
// (a + b) % b*b == 0
// (a/b + 1) / b == 0


int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}