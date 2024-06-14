#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
int n;
void helper(int i, int lmax, vector<int>& arr) {
    if (i == n)return;
    lmax = max(lmax, arr[i]);
    cout << lmax << " ";
    helper(i + 1, lmax, arr);
}

void solve() {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < n;i++)cin >> arr[i];
    helper(0, INT_MIN, arr);
}
int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
}