
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    s--;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (a[0]) {
        if (a[s]) {
            cout << "YES" << '\n';
            return 0;
        }
        if (b[s]) {
            for (int i = s + 1; i < n; i++) {
                if (a[i] + b[i] == 2) {
                    cout << "YES" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}
