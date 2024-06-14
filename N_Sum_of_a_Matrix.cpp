#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
int r, c;
int a[1000][1000];
int b[1000][1000];

void helper(int i, int j) {
    if (i == r && j == c) {
        return;
    }
    a[i][j] += b[i][j];
    if (j == c)
        helper(i + 1, 0);
    else helper(i, j + 1);
}

void solve() {
    cin >> r >> c;
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cin >> b[i][j];
        }
    }
    helper(0, 0);
    for (int i = 0;i < r;i++) {
        for (int j = 0;j < c;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}