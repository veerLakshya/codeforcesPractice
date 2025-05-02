// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

int a[2069], mat[1069][1069];

void solve(int t) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (i == 0 || j == n - 1) sum += mat[i][j];
        }
    }
    int x = (2 * n) * (2 * n + 1) / 2 - sum;
    cout << x << " ";
    for (int i = 0; i < n; i++) cout << mat[0][i] << " ";
    for (int i = 1; i < n; i++) cout << mat[n - 1][i] << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}