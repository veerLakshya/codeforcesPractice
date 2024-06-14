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
    // 10000 4 -> 1
    // 1337 0 -> 1337
    // 987654321 6 -> 321
    // 66837494128 5 ->  
    // greedily remove the largest digit
    int x, k;
    cin >> x >> k;
    int n = x;
    if (x == 1) {
        cout << 1 << endl;
        return;
    }
    if (k == 0) {
        cout << x << endl;
        return;
    }
    vi digitArray;
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
        cout << digit << " ";
        digitArray.pb(digit);
    }



}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}