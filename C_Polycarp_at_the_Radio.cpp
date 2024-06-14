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



void solve() {
    int n, m;
    cin >> n >> m;
    vll a(n), useless_indicess, freq(m + 1);
    ll bi_max = n / m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > m)useless_indicess.pb(i);
        else if (freq[a[i]] == bi_max)useless_indicess.pb(i);
        else freq[a[i]]++;
    }
    ll steps = 0;
    // print(freq);
    for (int i = 1; i <= m;i++) {
        // dbg(i, freq[i]);
        if (freq[i] < bi_max) {
            steps += bi_max - freq[i];
            while (freq[i] != bi_max) {
                a[useless_indicess.back()] = i;
                useless_indicess.pop_back();
                freq[i]++;
            }
        }
    }
    cout << bi_max << " " << steps << endl;
    for (auto i : a) {
        cout << i << " ";
    }

}

int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
