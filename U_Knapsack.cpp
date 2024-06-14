#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
int n;

int helper(int i, int w, vector < pair<int, int>>& arr) {
    if (i == n) {
        if (w >= 0)return 0;
        return INT_MIN;
    }
    int not_taken = helper(i + 1, w, arr);
    int taken = helper(i + 1, w - arr[i].first, arr) + arr[i].second;
    return max(not_taken, taken);
}

void solve() {
    int w;
    cin >> n >> w;
    vector<pair<int, int>> arr(n);
    for (int i = 0;i < n;i++)cin >> arr[i].first >> arr[i].second;
    cout << helper(0, w, arr);

}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}