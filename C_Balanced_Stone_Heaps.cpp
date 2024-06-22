#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<typename T>
void print(vector<T> v) {
    cout << "[ ";
    for (auto i : v) {
        cout << (i);
        cout << " ";
    }
    cout << "]";
}
template<typename T>
void print(set<T> v) {
    cout << "[ ";

    for (auto i : v) {
        cout << (i);
        cout << " ";
    }

    cout << "]";
}
template<typename T>
void print(multiset<T> v) {
    cout << "[ ";

    for (auto i : v) {
        cout << (i);
        cout << " ";
    }

    cout << "]";
}
template<typename T, typename V>
void print(map<T, V> v) {
    cout << "{ ";
    for (auto p : v) {
        cout << p;
        cout << " ";
    }

    cout << "}";
}
template<typename T, typename V>
void print(unordered_map<T, V> v) {
    cout << "{ ";
    for (auto p : v) {
        cout << (p);
        cout << " ";
    }

    cout << "}";
}
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
//--------------------------------------------------------------------------------------
int n;
bool valid(vi a, int x) {
    vi b = a;
    for (int i = n - 1; i >= 2; i--) {
        if (b[i] < x)return false;
        int d = min(a[i] / 3, (b[i] - x) / 3);
        b[i - 1] += d;
        b[i - 2] += 2 * d;
    }
    if (b[0] < x || b[1] < x)return false;
    return true;
}
void solve() {
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int l = 1; int r = *max_element(a.begin(), a.end());
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (valid(a, mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}