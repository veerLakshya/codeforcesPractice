#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
int n, x;
bool flag = false;
void helper(int i, int sum, vector<int>& arr) {
    if (i == n) {
        if (sum == x) {
            flag = true;
        }
        return;
    }
    helper(i + 1, sum - arr[i], arr);
    helper(i + 1, sum + arr[i], arr);
}

void solve() {
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0;i < n;i++)cin >> arr[i];
    helper(1, arr[0], arr);
    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}