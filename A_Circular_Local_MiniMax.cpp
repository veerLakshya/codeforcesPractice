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

bool c(ll a, ll b, ll c) {
    if (b > a && b < c)return 0;
    if (b < a && b > c)return 0;
    if (a == b || b == c) return 0;
    return 1;
}

void ekbaar() {
    inll(n);
    vll a(n), b; cin >> a;

    mll mp;
    for (auto i : a)mp[i]++;
    for (auto i : mp) if (i.ss > (n / 2)) {
        if (i.ss > n / 2) {
            pno;
            return;
        }
    }
    sort(all(a));
    for (int i = 0, j = n / 2 + (n & 1); i < n / 2 && j < n; i++, j++) b.pb(a[i]), b.pb(a[j]);
    if (n & 1)b.pb(a[n / 2]);

    if (!c(b[n - 1], b[0], b[1]) || !c(b[n - 2], b[n - 1], b[0]) || n == 3) {
        pno;
        return;

    }

    for (int i = 1; i < n - 1; i++) {
        if (!c(b[i - 1], b[i], b[i + 1])) {
            pno;
            return;
        }
    }
    pyes;
    cout << b << endl;
}
// a b c
// b > a && b < c || b > a && b < c
// 0 1 2 3 4 5 6

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