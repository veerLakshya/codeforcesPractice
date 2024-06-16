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
//------------------------------------------------------------------------------------

void solve() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    if (n == 1 || n == 2) {
        cout << n << endl;
        return;
    }
    ll ans = 2;
    for (int i = 1; i < n - 1; i++) {
        if (v[i].ff - v[i].ss > v[i - 1].ff) {
            ans++;
        }
        else if (v[i].ff + v[i].ss < v[i + 1].ff) {
            ans++;
            v[i].ff += v[i].ss;
        }
    }
    cout << ans << endl;
}

int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}