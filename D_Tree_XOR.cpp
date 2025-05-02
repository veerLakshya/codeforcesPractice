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


// DP on Trees with Rerooting of nodes

void ekbaar() {
    int n; cin >> n;

    vll c(n); cin >> c;
    vvll adj(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll subtree_size(n);
    vll dp(n), ans(n);

    auto dfs = [&](int cur, int par, auto self)->void {

        subtree_size[cur] = 1;
        dp[cur] = 0;

        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;

            self(nbr, cur, self);
            subtree_size[cur] += subtree_size[nbr];
            ll p = subtree_size[nbr] * (c[cur] ^ c[nbr]);
            dp[cur] += (dp[nbr] + p);
        }
        };


    auto changeRoot = [&](int oldRoot, int newRoot)-> void {
        ll m = c[oldRoot] ^ c[newRoot];

        //undo
        subtree_size[oldRoot] -= subtree_size[newRoot];
        dp[oldRoot] -= dp[newRoot] + (subtree_size[newRoot] * m);

        //redo
        subtree_size[newRoot] += subtree_size[oldRoot];
        dp[newRoot] += dp[oldRoot] + (subtree_size[oldRoot] * m);
        };

    // Rerooting each node as a root once
    auto reroot = [&](int cur, int par, auto self)->void {
        ans[cur] = dp[cur];

        for (auto nbr : adj[cur]) {
            if (nbr == par) continue;
            changeRoot(cur, nbr);
            self(nbr, cur, self);
            changeRoot(nbr, cur);
        }
        };

    dfs(0, -1, dfs);

    reroot(0, -1, reroot);

    cout << ans << "\n";
}

int main() {
    siuu();
    int t = 1;
    cin >> t;
    while (t--) {
        ekbaar();
    }
    return 0;
}
/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/