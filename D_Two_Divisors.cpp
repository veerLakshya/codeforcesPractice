// Lakshya Veer Singh
/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/
#include <bits/stdc++.h>
using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define ff first
#define ss second
#define pushb push_back
#define popb pop_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define endl "\n"
#define trav(a, b) for (auto&(a) : (b))
#define rep0n(i, e) for (int i = 0; i < (e); ++i) 
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define repll(a, b, c) for (ll(a) = (b); (a) < (c); ++(a))
#define repn(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define repnll(a, b, c) for (ll(a) = (b); (a) <= (c); ++(a))
#define repr(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define reprll(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define repsq(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define repsqll(a, b, c) for (ll(a) = (b); (a) * (a) <= (c); ++(a))
#define pr(a) cout<<a
#define prs(a) cout<<a<<" "
#define prn(a) cout<<a<<"\n"
#define pyes cout<<"YES"<<"\n"
#define pno cout<<"NO"<<"\n"
#define pyn(ans) printf("%s\n", (ans)?"Yes":"No");
#define br cout<<"\n"
#define ps(x,y) fixed<<setprecision(y)<<x
#define printv(a) {for(auto u:a) {cout<<u<<" ";} cout<<endl;}
// #define printv(a) {for(auto u:a) {cout<<u.ff<<" "<<u.ss<<" ";} cout<<endl;}
#define kitniBaar(t) while (t--)

//Debug Options-
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

//Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream& istream, vector<T>& v) { for (auto& it : v)cin >> it;return istream; }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream& ostream, const vector<T>& c) { for (auto& it : c) cout << it << " "; return ostream; }

//Sorting
bool sorta(const pair<int, int>& a, const pair<int, int>& b) { return (a.second < b.second); }
bool sortd(const pair<int, int>& a, const pair<int, int>& b) { return (a.second > b.second); }

//Bits
string decToBinary(int n) { string s = "";int i = 0;while (n > 0) { s = to_string(n % 2) + s;n = n / 2;i++; }return s; }
ll binaryToDecimal(string n) { string num = n;ll dec_value = 0;int base = 1;int len = num.length();for (int i = len - 1; i >= 0; i--) { if (num[i] == '1')dec_value += base;base = base * 2; }return dec_value; }

//Check
bool isPrime(ll n) { if (n <= 1)return false;if (n <= 3)return true;if (n % 2 == 0 || n % 3 == 0)return false;for (int i = 5;i * i <= n;i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false;return true; }
bool isPowerOfTwo(int n) { if (n == 0)return false;return (ceil(log2(n)) == floor(log2(n))); }
bool isPerfectSquare(ll x) { if (x >= 0) { ll sr = sqrt(x);return (sr * sr == x); }return false; }

//Constants
vector <ll> primes;
vector <bool> is_prime;

// Mathematical functions
void Sieve(int n) { is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for (ll i = 2; i * i <= n; i++) if (is_prime[i]) for (ll j = i * i; j <= n; j += i) is_prime[j] = false; }
void get_primes(int n) { for (int i = 2; i <= n; i++)  if (is_prime[i])  primes.push_back(i); }
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll gcd(ll a, ll b) { if (b == 0)return a;return gcd(b, a % b); } //__gcd 
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod) { ll res = 0;a %= mod;while (b) { if (b & 1)res = (res + a) % mod;b >>= 1; }return res; }
ll powermod(ll x, ll y, ll p) { ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0) { if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p; }return res; }
//To find modulo inverse, call powermod(A,M-2,M)

/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-CODE~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/
vll d1, d2;
void ekbaar() {
    inll(n);

    vll a(n);
    cin >> a;
    ll mx = 0;
    mx = *max_element(all(a));
    Sieve(mx);
    get_primes(mx);
    for (auto x : a) {
        ll num = x;
        bool flag = false;
        ll div1 = -1, div2 = -1;
        for (auto i : primes) {
            if (i * i > num) break;
            if (num % i == 0 && num / i != i) {
                while (num % i == 0) num /= i;
                if (num != 1) {
                    flag = true;
                    div1 = i;
                    div2 = num;
                    break;
                }
            }
        }
        if (flag) {
            d1.pb(div1);
            d2.pb(div2);
        }
        else {
            d1.pb(-1);
            d2.pb(-1);
        }
    }
}

int main() {
    fastio();
    auto start = chrono::high_resolution_clock::now();
    int t = 1;
    // cin >> t;
    kitniBaar(t) {
        ekbaar();
    }
    printv(d1);
    printv(d2);
    auto end = chrono::high_resolution_clock::now();

    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(9);
    cout << " sec" << endl;
}
/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/
/* stuff you should look for-

    1) DATA TYPE OVERFLOW
    2) SPECAIL CASES (n=1/n=0 ?)
    3) WRITE STUFF DOWN
    4) DO SOMTHING INSTED OF NOTHING AND STAY ORGANIZED
    5) DON'T GET STUCK ON ONE APPROACH

    *Lakshya Veer Singh
*/