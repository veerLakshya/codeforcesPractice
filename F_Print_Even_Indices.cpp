#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

int arr[100000];

void solve(int i, int n) {
    if (i == n)return;
    solve(i + 1, n);
    if (i % 2 == 0)cout << arr[i] << " ";
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(0, n);
    }
}