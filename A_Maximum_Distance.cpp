#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double sqrtNewton(double n, double precision = 1e-6) {
    if (n < 0) return -1; // Return -1 for negative numbers (invalid input)
    if (n == 0 || n == 1) return n; // Base cases

    double x = n; // Initial guess
    double root;

    while (true) {
        root = 0.5 * (x + (n / x)); // Newton's formula
        if (abs(root - x) < precision) break; // Stop when precision is met
        x = root;
    }
    return root;
}

int main() {
    ll n, ans = 0;
    cin >> n;

    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].first;
    for (int i = 0; i < n; i++) cin >> points[i].second;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll dx = points[i].first - points[j].first;
            ll dy = points[i].second - points[j].second;
            ll pos = dx * dx + dy * dy;
            ans = max(ans, pos);
        }
    }
    cout << ans;
    return 0;
}