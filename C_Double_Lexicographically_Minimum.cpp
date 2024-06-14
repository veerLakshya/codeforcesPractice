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
    string s;
    cin >> s;
    sort(all(s));

    string ans = s;

    int n = s.size();
    int left = 0, right = n - 1;

    for (int i = 0; i < n; i += 2)
    {
        if (i == n - 1) {
            ans[left] = s[i];
        }
        else if (s[i] == s[i + 1]) {
            ans[left] = s[i];
            ans[right] = s[i];
            left++;
            right--;
        }
        else {
            if (s[i + 1] == s[n - 1]) {
                int len = n - i - 1;
                int lhalf = ceil(len / 2.0);
                int rhalf = len - lhalf;
                while (lhalf--) {
                    ans[left] = s[i + 1];
                    left++;
                }
                ans[left] = s[i];
                while (rhalf--) {
                    ans[right] = s[i + 1];
                    right--;
                }
                break;
            }
            else {
                for (int j = i + 1; j < n; j++) {
                    ans[left] = s[j];
                    left++;
                }
                ans[right] = s[i];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;

}

int main() {
    fastio();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}