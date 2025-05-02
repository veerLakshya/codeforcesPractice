#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int arr[26]{ 0 };
    int m = 0, n = s.size();
    for (int i = 0; i < n; i++) {
        int ind = s[i] - 'a';
        if (arr[ind]) {
            m += 2;
            memset(arr, 0, sizeof(arr));
        }
        else arr[ind] = 1;
    }
    cout << n - m << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}