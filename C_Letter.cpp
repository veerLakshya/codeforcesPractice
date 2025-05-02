#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    int n = s.size(), ans = INT_MAX;

    int a[n + 1]{ 0 }, b[n + 1]{ 0 };

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i - 1] >= 'a' && s[i - 1] <= 'z');
    }
    for (int i = n - 1; i >= 0; i--) {
        b[i] = b[i + 1] + (s[i] >= 'A' && s[i] <= 'Z');
    }

    for (int i = 0; i <= n; i++) {
        ans = min(ans, a[i] + b[i]);
    }

    cout << ans;
}