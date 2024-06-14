#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0)cout << n / 2 << " " << n / 2 << endl;
    else {
        int a = 1;
        for (int i = 2;i * i <= n;i++) {
            if (n % i == 0) {
                a = i;
                break;
            }
        }
        if (a == 1)cout << 1 << " " << n - 1 << endl;
        else {
            cout << n / a << " " << n - (n / a) << endl;
        }
    }

}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}