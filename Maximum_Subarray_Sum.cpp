#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + arr[i] >= 0) {
            cur += arr[i];
            ans = max(ans, cur);
        }
        else cur = 0;
    }
    if (ans == 0) ans = *max_element(arr, arr + n);
    cout << ans;
    return 0;
}