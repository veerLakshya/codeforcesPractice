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
bool check(int mid, vll v) {
    int i = v.size() - 1;
    int cnt = 1;
    for (int j = mid - 1;j >= 0;j--, i--) {

    }

}
void solve() {
    int n;
    cin >> n;
    vll v(n);
    rep(i, 0, n)cin >> v[i];
    int low = 0;
    int high = n - 1;
    int ans;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, v)) {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    c
}

int main() {
    // int t;
    // cin>>t;
    // kitniBaar(t){
    solve();
    // }
}


/* stuff you should look for
    1) data type overflows, array bounds
    2) special cases (n=1/n=0 ?)
    3) do smth instead of nothing and stay organized
    4) WRITE STUFF DOWN
    5) DON'T GET STUCK ON ONE APPROACH
*/