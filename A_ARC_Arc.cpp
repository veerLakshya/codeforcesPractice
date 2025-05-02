#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, ones = 0;
    cin >> n;
    vector<int> a(n);
    bool odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) {
            ones++;
            if (i % 2)odd = 1;
            else even = 1;
        }
    }
    if (n % 4 == 0) cout << "Yes";
    else if (n % 2) {
        if (ones) cout << "Yes";
        else cout << "No";
    }
    else {
        if (even && odd) cout << "Yes";
        else cout << "No";
    }
}