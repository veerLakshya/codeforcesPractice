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

bool helper(ll steps, vector<pair<ll, ll>>& location, pair<ll, ll> start, pair<ll, ll> target, ll n) {
    pair <ll, ll> free = { (steps / n) * location[n - 1].ff + start.ff, (steps / n) * location[n - 1].ss + start.ss };

    if (steps % n) {
        free.ff += location[(steps % n) - 1].ff;
        free.ss += location[(steps % n) - 1].ss;
    }
    ll dist = abs(free.ff - target.ff) + abs(free.ss - target.ss);
    if (dist <= steps) return true;
    return false;
}

void solve() {
    pair<ll, ll> start, target;
    cin >> start.ff >> start.ss >> target.ff >> target.ss;
    ll n;cin >> n;
    string s;cin >> s;

    vector<pair<ll, ll>> location(n);

    pair<ll, ll> curr = { 0, 0 };
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') curr.ss++;
        else if (s[i] == 'D') curr.ss--;
        else if (s[i] == 'L') curr.ff--;
        else curr.ff++;
        location[i] = curr;
    }

    ll low = 0, high = 1e15;
    ll ans = -1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (helper(mid, location, start, target, n)) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
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