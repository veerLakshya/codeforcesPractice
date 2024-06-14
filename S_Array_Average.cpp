#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
int n;
int arr[101];

double average(int i, double sum) {
    if (i == n)return sum / (n * 1.0);
    return average(i + 1, sum + arr[i]);
}

void solve() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cout << setprecision(7) << fixed << average(0, 0.0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}