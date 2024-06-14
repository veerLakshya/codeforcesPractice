#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
int n, m;
int a[100][100];

int helper(int i, int j) {
    if (i == n - 1 && j == m - 1) {
        return a[i][j];
    }
    int right = INT_MIN, down = INT_MIN;
    if (i < n - 1)
        right = helper(i + 1, j);
    if (j < m - 1)
        down = helper(i, j + 1);
    return a[i][j] + max(right, down);
}

void solve() {
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }
    cout << helper(0, 0);
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}