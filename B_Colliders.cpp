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
const int N = 100001;
int spf[N], occupied[N], isActive[N];

void sieve() {
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
}
vi primeFactorise(int n) {
    vi factors;
    while (n != 1) {
        int x = spf[n];
        while (n % x == 0) n /= x;
        factors.pb(x);
    }
    return factors;
}

void solve() {
    sieve();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char c; int x;
        cin >> c >> x;
        vi primefactors = primeFactorise(x);
        if (c == '+') {
            if (isActive[x] == 1) {
                cout << "Already on\n";
            }
            else {
                int collision = 0;
                for (auto& i : primefactors) {
                    if (occupied[i]) {
                        collision = occupied[i];
                    }
                }
                if (collision) {
                    cout << "Conflict with " << collision << "\n";
                }
                else {
                    cout << "Success\n";
                    for (auto& i : primefactors) {
                        occupied[i] = x;
                    }
                    isActive[x] = 1;
                }
            }
        }
        else {
            if (!isActive[x]) {
                cout << "Already off\n";
            }
            else {
                cout << "Success\n";
                isActive[x] = 0;
                for (auto& i : primefactors) {
                    occupied[i] = 0;
                }
            }
        }
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