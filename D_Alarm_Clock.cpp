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
//  m sized window from 0 to last alarm
//  whenever count of alarms in window becomes k, remove the rightmost alarm and increase the cnt by 1
//
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    // n: alarm clocks
    // m: consecutive mins 
    // k: alarms within mins to wake up
    vi a(n);
    for (auto& i : a) cin >> i;
    // a[i] = time of ith alarm
    sort(all(a));
    int ans = 0;

    //* implementation 1
    // int alarms_within_window = 0;
    // vi arr(a[n - 1] + 1, 0);
    // for (int i = 0; i < n; i++) {
    //     arr[a[i]] = 1;
    // }
    // for (int i = 0; i < arr.size(); i++) {
    //     alarms_within_window += arr[i];
    //     if (i >= m) {
    //         alarms_within_window -= arr[i - m];
    //     }
    //     if (alarms_within_window == k) {
    //         arr[i] = 0;
    //         alarms_within_window--;
    //         ans++;
    //     }
    // }

    //* implementation 2
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(a[i]);
        while (a[i] - dq.front() >= m) {
            dq.pop_front();
        }
        while (dq.size() >= k) {
            dq.pop_back();
            ans++;
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