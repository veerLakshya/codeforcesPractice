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
    ll n, target;
    cin >> n >> target;
    vll a(n + 1);
    ll index = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        if (a[i] == target) {
            index = i;
        }
    }
    ll l = 1, r = n + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (a[mid] <= target) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << 1 << endl;
    cout << min(l, index) << " " << max(l, index) << endl;
}
//6 3
//array  4 3 1 5 2 6 
//index  1 2 3 4 5 6 ... l = 1, r = 6, mid = 3

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}