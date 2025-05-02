#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> a(4);
        for (int i = 0; i < 4; i++) cin >> a[i];
        int x = max(a[0], a[1]), y = max(a[2], a[3]);
        sort(a.begin(), a.end());
        if ((a[3] == x || a[3] == y) && (a[2] == x || a[2] == y)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}