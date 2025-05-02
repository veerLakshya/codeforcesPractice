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
typedef set<int> si;
typedef set<ll> sll;

//Macros
#define M 1000000007
#define INF 1e9 + 5
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
#define br "\n"
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repd(i,a,n) for(long long int i = (a); i >= (n); --i)

//Debug Options-
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { os << '('; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
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

void ekbaar(ll testcase) {
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m); cin >> a >> b;

    sort(all(a)); sort(all(b));

    ll k = min({ n,m, (n + m) / 3 });
    prn(k);

    vll c, d;
    for (int i = 0; 2 * i < n; i++) {
        c.pb((a[n - i - 1] - a[i]));
    }
    for (int i = 0; 2 * i < m; i++) {
        d.pb((b[m - i - 1] - b[i]));
    }

    vll s(2); // used in c and d
    vll p(2); // ind of c and d
    ll ans = 0;
    rep(i, 0, k - 1) {
        // take one point from each, then see from where we can take the otehr point 
        s[0]++;
        s[1]++;
        if (s[1] >= m) {
            ans += c[p[0]];
            p[0]++;
            s[0]++;
        }
        else if (s[0] >= n) {
            ans += d[p[1]];
            p[1]++;
            s[1]++;
        }
        else {
            if (c[p[0]] > d[p[1]]) {
                ans += c[p[0]++];
                s[0]++;
            }
            else {
                ans += d[p[1]++];
                s[1]++;
            }
        }

        if (s[0] > n) {
            ans -= c[--p[0]];
            s[0] -= 2, s[1] -= 1;
            --i;  continue;
        }
        if (s[1] > m) {
            ans -= d[--p[1]];
            s[0] -= 1, s[1] -= 2;
            --i;  continue;
        }
        prs(ans);
    }

    prn("");

    // ll mini = min(n, m), maxi = max(n, m);

    // ll k = min(maxi / 2, mini) + (mini > maxi / 2 ? (mini - (maxi / 2)) / 2 : 0);

    // ll fromsmaller = (mini > (maxi / 2) ? (mini - (maxi / 2)) / 2 : 0);

    // vll larger, smaller;
    // if (maxi == n) {
    //     ll l = 0, r = n - 1;
    //     while (l < r) {
    //         larger.pb(abs(a[r] - a[l]));
    //         l++, r--;
    //     }
    //     l = 0, r = m - 1;
    //     while (l < r) {
    //         smaller.pb(abs(a[r] - a[l]));
    //         l++, r--;
    //     }
    // }
    // else {
    //     ll l = 0, r = n - 1;
    //     while (l < r) {
    //         smaller.pb(abs(a[r] - a[l]));
    //         l++, r--;
    //     }
    //     l = 0, r = m - 1;
    //     while (l < r) {
    //         larger.pb(abs(a[r] - a[l]));
    //         l++, r--;
    //     }
    // }
    // vll options;
    // for (auto i : smaller) options.pb(i);
    // for (auto i : larger) options.pb(i);
    // sort(rall(options));
    // prn(k);
    // for (int i = 1; i <= k; i++) {
    //     ll ans = 0;
    //     if (i <= mini / 2) {
    //         for (int j = 0; j < i; j++) ans += options[j];
    //     }
    //     else {
    //         ll fromboth = fromsmaller;
    //         ll j;
    //         for (j = 0; j < i - fromboth; j++) {
    //             ans += larger[j];
    //         }
    //         ll k = 0;
    //         while (fromboth) {
    //             if (smaller[k] > larger[j]) {
    //                 ans += smaller[k];
    //                 k++;
    //             }
    //             else {
    //                 ans += larger[j];
    //                 j++;
    //             }
    //             fromboth--;
    //         }
    //     }
    //     cout << ans << " ";
    // }
    // prn("");
}

int main() {
    siuu();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) ekbaar(i);
    return 0;
}
/*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-*/