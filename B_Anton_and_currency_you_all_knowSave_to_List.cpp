#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ar(n), a(n);
    int f = 0;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
        if ((a[i] & 1) == 0) f = 1;
    }

    if (f == 0) {
        cout << -1;
        return 0;
    }
    int pos = -1;
    for (int i = n - 2; i >= 0; i--) {
        if ((a[i] & 1) == 1) continue;
        if (pos == -1 || a[i] < a[n - 1]) pos = i;
    }
    swap(a[pos], a[n - 1]);
    for (int i : a) cout << i;
}