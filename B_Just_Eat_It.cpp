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
    // Yasser will buy exactly one cupcake of each type
    // Yasser's tastiness is the sum of tastiness of all cupcakes he bought
    // Adel will choose some segment [l,r] and buy one of each type of cupcake in this segment

    ll n;
    cin >> n;
    vll a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum <= 0) {
            cout << "NO" << endl;
            return;
        }
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if (sum <= 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}