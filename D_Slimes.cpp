//Lakshya Veer Singh
/*--------------------------------Template------------------------------*/

#include <bits/stdc++.h>
using namespace std;

//Print Options-
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

//Data types and Data structures-
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<double> vd;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef unordered_map<int, int> umi;
typedef unordered_map<ll, ll> umll;
typedef map<int, int> mi;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef set<ll> setll;
typedef set<char> sc;


//Macros-
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define maxe max_element
#define mine min_element

#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define kitniBaar(t) while (t--)

#define yes cout<<"yes"<<"\n"
#define no cout<<"no"<<"\n"
#define br cout<<"\n"
#define yn(ans) printf("%s\n", (ans)?"Yes":"No");


#define trav(a, b) for (auto&(a) : (b))
#define rep0to(i, e) for (int i = 0; i < (e); ++i) 
#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define repll(a, b, c) for (ll(a) = (b); (a) < (c); ++(a))
#define repn(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define repnll(a, b, c) for (ll(a) = (b); (a) <= (c); ++(a))
#define repd(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define repdll(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define repsq(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define repsqll(a, b, c) for (ll(a) = (b); (a) * (a) <= (c); ++(a))
#define SORT(v) sort(all(v))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define alla(arr, sz) arr, arr + sz
#define REVERSE(v) reverse(all(v))
#define SORTA(arr, sz) sort(alla(arr, sz))
#define pr(a) cout<<a
#define prs(a) cout<<a<<" "
#define prn(a) cout<<a<<"\n"
#define printv(a) {for(auto u:a) {cout<<u<<" ";} cout<<endl;}
#define setbits(x) __builtin_popcountll(x)

/*---Sum of array elements---*/
template<typename T>
T arrSum(vector<T>& vec)
{
    T sum = 0;
    for (ll i = 0; i < vec.size(); i++)
        sum += vec[i];
    return sum;
}
/*---GCD of two Numbers---*/
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
/*---LCM of two Numbers---*/
ll lcm(ll a, ll b) {
    if (a == b)
        return a;
    else
        return (a * b) / gcd(a, b);
}
/*---To check if num = 2^x---*/
bool isPowerOfTwo(ll x)
{
    if (x == 0)
        return false;
    else
    {
        while (x % 2 == 0) x /= 2;
        return (x == 1);
    }
}


/*-----------------------------------Actual Code---------------------------------*/

//  a[i]   = 2 2 3 1  4
//  pre[i] = 2 4 7 8 12
//  num[i] = 1 1 2 3  4

//  numleft[i]  = 1 1 2 3  4
//  numright[i] = 4 3 2 1  1

//  ansl = 0, ansr = 0
//  i = 0
//  low = 0, high = -1
//  ansl = INT_MAX, ansr = INT_MAX
//  i = 1
//  low = 0, high = 0
//  ansl = INT_MAX, ansr = INT_MAX
//  i = 2
//  low = 0, high = 1
//  ansl = INT_MAX, ansr = INT_MAX
//  i = 3
//  low = 0, high = 2
//  ansl = INT_MAX, ansr = INT_MAX


void solve() {
    int n;
    cin >> n;
    vll a(n), ans;
    for (auto& i : a)cin >> i;

    vll pre(n + 1);
    pre[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    vll numleft(n);
    vll numright(n);
    set<ll> s;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
        numleft[i] = s.size();
    }
    for (int i = n - 1; i >= 0; i--) {
        s.insert(a[i]);
        numright[i] = s.size();
    }
    s.clear();

    for (ll i = 0;i < n; i++)
    {
        ll low = 0, high = i;
        ll ansl = INT_MAX, ansr = INT_MAX;

        if (i > 0 && numleft[i] > 1 && pre[high] > a[i]) {
            while (low <= high) {   //Binary Search on index on left side such that sum is greater than a[i]
                ll mid = low + (high - low) / 2;
                ll calc = pre[i] - pre[mid];
                if (calc > a[i]) {
                    ansl = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }

            }
            low = i + 1, high = n - 1;
            if (i < n - 1 && numright[i] > 1 && pre[n] - pre[i] > a[i]) {
                while (low <= high) {   //Binary Search on index on right side such that sum is greater than a[i]
                    ll mid = low + (high - low) / 2;
                    ll calc = pre[mid + 1] - pre[i];
                    if (calc > a[i]) {
                        ansr = mid;
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
            }
            ans.pb(min(ansl, ansr) + 1);
        }
    }
    printv(ans);
}

int main() {
    int t;
    cin >> t;
    kitniBaar(t) {
        solve();
    }
}


/* stuff you should look for
    1) data type overflows, array bounds
    2) special cases (n=1/n=0 ?)
    3) do smth instead of nothing and stay organized
    4) WRITE STUFF DOWN
    5) DON'T GET STUCK ON ONE APPROACH
*/