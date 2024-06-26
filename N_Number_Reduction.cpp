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
    string s, ans;
    cin >> s;
    int k; cin >> k;

    deque<int> nums[10];

    for (int i = 0; i < s.size(); i++) {
        nums[s[i] - '0'].pb(i);
    }

    for (int i = 0; i < s.size(); i++) {
        int curind = s.size(), newind = s.size();
        for (int j = 0; j < 10; j++) {
            if (nums[j].size() > 0) curind = min(curind, nums[j].front());
        }
        for (int j = (i == 0); j < 10; j++) {
            if (nums[j].size() && nums[j].front() - curind <= k) {
                ans += ('0' + j);
                newind = nums[j].front();
                break;
            }
        }
        k -= newind - curind;
        for (int j = 0; j < 10; j++) {
            while (nums[j].size() && nums[j].front() <= newind) nums[j].pop_front();
        }
    }
    cout << string(ans.begin(), ans.end() - k) << endl;
}

int main() {
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        // cout << "#test case- " << t << endl;
        solve();
    }
}