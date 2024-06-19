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
    ll q;
    cin >> q;
    bool notA_s = false, notA_T = false;
    ll countofA_S = 0, countofA_T = 0;
    while (q--) {
        ll d, k;
        string s;
        cin >> d >> k >> s;
        for (auto i : s) {
            if (i != 'a') {
                if (d == 2)
                    notA_T = true;
                else
                    notA_s = true;
            }
            else {
                if (d == 2)
                    countofA_T += k;
                else
                    countofA_S += k;
            }
        }
        if (notA_T) cout << "YES" << endl;
        else if (notA_s) cout << "NO" << endl;
        else if (countofA_S < countofA_T) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}