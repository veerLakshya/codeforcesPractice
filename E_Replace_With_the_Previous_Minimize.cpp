#include <bits/stdc++.h>
using namespace std;

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char maxPossibleChar = 'a';
    char notPossibleChar = 'a';
    for (int i = 0;i < n;i++) {
        if (s[i] - 'a' > k) {
            notPossibleChar = s[i];
            break;
        }
        if (s[i] > maxPossibleChar) {
            maxPossibleChar = s[i];
        }
    }
    int stepCountforMaxPossibleChar = maxPossibleChar - 'a';
    int leftCount = k - stepCountforMaxPossibleChar;
    char to = notPossibleChar - leftCount;
    for (char c = notPossibleChar;c > to;c--) {
        for (char& e : s) {
            if (e == c) {
                e--;
            }
        }
    }
    for (char& e : s) {
        if (e <= maxPossibleChar) {
            e = 'a';
        }
    }
    cout << s << endl;
}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}