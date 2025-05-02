#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;

    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        ll val; cin >> val;
        if (mp.count(x - val)) {
            cout << mp[x - val] << " " << i;
            return 0;
        }
        mp[val] = i;
    }
    cout << "IMPOSSIBLE";
    return 0;
}