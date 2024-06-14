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
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < n / 2; i++) {
        sum1 += pow(2, i);
    }
    for (int i = n / 2; i < n; i++) {
        sum2 += pow(2, i);
    }
    sum1 += pow(2, n);
    cout << abs(sum1 - sum2) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}


// 2 4 8 16 32 64 128 256 512 1024 
// 2 4 8 16 1024        - 1054
// 512 256 128 64 32    - 1012

// 2 4 8 16
// 16 2 - 18
// 8 4 - 12