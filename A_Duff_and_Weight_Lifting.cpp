#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define INF 1e9
#define NINF -1e9
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

//Approach 1: We can use a multiset to store the weights. We can insert all the weights in the multiset. Then we can iterate over the multiset and for each weight, we can check if the next weight is equal to the current weight. If it is equal, we can erase the next weight and insert the sum of the two weights. If it is not equal, we can increment the answer. We can continue this process until the multiset is empty. The answer will be the number of times we increment the answer.

//* this implementaion gives TLE
// void solve() {
//     ll n;
//     cin >> n;
//     multiset<ll> s;
//     for (int i = 0; i < n; i++) {
//         ll x;
//         cin >> x;
//         s.insert(x);
//     }
//     vi a(n);
//     int ind = 0;
//     for (auto i : s) {
//         a[ind] = i;
//     }
//     ll ans = 0;
//     while (a.size() > 0) {
//         ll x = a.back();
//         a.pop_back();
//         if (a.size() > 0 && a.back() == x) {
//             a.pop_back();
//             a.pb(x + 1);
//         }
//         else {
//             ans++;
//         }
//     }
//     cout << ans << endl;
// }

// void solve() {
//     ll n;
//     cin >> n;
//     priority_queue<ll, vll, greater<ll>> s;
//     for (int i = 0; i < n; i++) {
//         ll x;
//         cin >> x;
//         s.push(x);
//     }
//     ll ans = 0;
//     while (s.size()) {
//         ll x = s.top();
//         s.pop();
//         if (s.size() && x == s.top()) {
//             s.pop();
//             s.push(x + 1);
//         }
//         else {
//             ans++;
//         }
//     }
//     cout << ans << endl;
// }

// Approach 2: we calculate the total sum of the array elements and check set bits in the sum. The number of set bits in the sum will be the answer.
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), freq(2e6 + 1, 0);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int ans = 0;
    for (int i = 0;i < 2e6 + 1;i++) {
        ans += freq[i] % 2;
        freq[i + 1] += freq[i] / 2;
    }
    cout << ans << '\n';
}


int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
