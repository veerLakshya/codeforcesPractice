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
    ll num_usb_mouse, num_ps_mouse, num_any_mouse;
    cin >> num_usb_mouse >> num_ps_mouse >> num_any_mouse;
    ll num_mouse;
    cin >> num_mouse;
    vll price_usb, price_ps2;
    for (int i = 0; i < num_mouse; i++) {
        ll x;
        string s;
        cin >> x >> s;
        if (s == "USB") {
            price_usb.pb(x);
        }
        else {
            price_ps2.pb(x);
        }
    }
    ll ans = 0;
    ll cost = 0;

    if (price_ps2.size() == 0) {
        num_ps_mouse = 0;
    }
    else {
        sort(price_ps2.rbegin(), price_ps2.rend());
        for (int i = 1; i <= num_ps_mouse; i++) {
            if (price_ps2.size() == 0) {
                break;
            }
            ans++;
            cost += price_ps2.back();
            price_ps2.pop_back();
        }
    }
    if (price_usb.size() == 0) {
        num_usb_mouse = 0;
    }
    else {
        sort(price_usb.rbegin(), price_usb.rend());
        for (int i = 1; i <= num_usb_mouse; i++) {
            if (price_usb.size() == 0) {
                break;
            }
            ans++;
            cost += price_usb.back();
            price_usb.pop_back();
        }
    }
    if (price_ps2.size() != 0 || price_usb.size() != 0) {
        vll price_any;
        for (int i = 0; i < price_ps2.size(); i++) {
            price_any.pb(price_ps2[i]);
        }
        for (int i = 0; i < price_usb.size(); i++) {
            price_any.pb(price_usb[i]);
        }
        sort(price_any.rbegin(), price_any.rend());
        for (int i = 1; i <= num_any_mouse; i++) {
            if (price_any.size() == 0) {
                break;
            }
            ans++;
            cost += price_any.back();
            price_any.pop_back();
        }
    }
    cout << ans << " " << cost << endl;

}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}