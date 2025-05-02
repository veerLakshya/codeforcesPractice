// Lakshya Veer Singh
/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/
#include <bits/stdc++.h>
using namespace std;

//Speed
#define siuu() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef set<int> sti;
typedef set<ll> stll;

//Macros
#define M 1000000007
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define pr(a) cout<<a
#define prs(a) cout<<a<<" "
#define prn(a) cout<<a<<"\n"
#define pyes cout<<"YES"<<"\n"
#define pno cout<<"NO"<<"\n"
#define br cout<<"\n"
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)

//Debug Options-
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

//Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream& istream, vector<T>& v) { for (auto& it : v)cin >> it;return istream; }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream& ostream, const vector<T>& c) { for (auto& it : c) cout << it << " "; return ostream; }

//Check
bool isPrime(ll n) { if (n <= 1)return false;if (n <= 3)return true;if (n % 2 == 0 || n % 3 == 0)return false;for (int i = 5;i * i <= n;i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;return true; }
bool isPowerOfTwo(int n) { if (n == 0)return false;return (ceil(log2(n)) == floor(log2(n))); }
bool isPerfectSquare(ll x) { if (x >= 0) { ll sr = sqrt(x);return (sr * sr == x); }return false; }

ll gcd(ll a, ll b) { if (b == 0)return a;return gcd(b, a % b); } //__gcd 

/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-CODE~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/

void ekbaar() {
    inll(n);

    vvll adj(n + 1);
    vpll edges;
    rep(i, 1, n - 1) {
        ll x, y;
        cin >> x >> y;
        edges.pb({ x,y });
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll color(n + 1);
    stll st;
    rep(i, 1, n) cin >> color[i], st.insert(color[i]);
    if (sz(st) == 1) {
        pyes;
        prn(1);
        return;
    }

    function<pair<bool, int>(int, int)> dfs = [&](int node, int p)-> pair<bool, int> {
        pair<bool, int> a = { true, color[node] };
        for (auto nbr : adj[node]) {
            if (nbr == p) continue;
            pair<bool, int> temp = dfs(nbr, node);
            if (!temp.first || temp.second != a.second) {
                a.first = false;
                return a;
            }
        }
        return a;
        };

    function <bool(int, int)> h = [&](int cur, int par)->bool {
        bool f = 1;
        for (auto i : adj[cur]) {
            if (i == par)continue;
            pair<bool, int> temp = dfs(i, cur);
            f &= temp.first;
            if (!f) return 0;
        }
        if (f)return true;
        return false;
        };

    for (auto i : edges) {
        if (color[i.ff] != color[i.ss]) {
            if (h(i.ff, 0)) {
                pyes;
                prn(i.ff);
                return;
            }
            if (h(i.ss, 0)) {
                pyes;
                prn(i.ss);
                return;
            }
            pno;
            return;
        }
    }
    pno;
}

int main() {
    siuu();
    int t = 1;
    // cin >> t;
    while (t--) {
        ekbaar();
    }
    return 0;
}
/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/