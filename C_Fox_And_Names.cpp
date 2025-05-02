// Author - Lakshya Veer Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(v) ((int)v.size())

vector<int> adj[26];
int used[26];
vector<int> ans;

void dfs(int x) {
    used[x] = 1; // instack, vis
    for (auto nbr : adj[x]) {
        if (used[nbr] == 1) {
            cout << "Impossible";
            exit(0);
        }
        else if (used[nbr] == 0) dfs(nbr);
    }
    used[x] = 2; // just visited
    ans.push_back(x);
}

void solve(int t) {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (j < min(sz(s[i]), sz(s[j])) && s[i][j] == s[i - 1][j]) j++;
        // if j == sz(s[i-1]) then s[i] already greater than s[i-1] and continue;
        // else either j == sz(s[i]) or broke somewhere in middle
        if (j == sz(s[i])) {
            // s[i-1]   - TEXTT
            // s[i]     - TEXT
            cout << "Impossible";
            return;
        }
        if (j < min(sz(s[i]), sz(s[i - 1]))) {
            int a = s[i - 1][j] - 'a';
            int b = s[i][j] - 'a';
            adj[a].push_back(b);
        }
    }

    // cout << " 1";

    for (int i = 0; i < 26; i++) {
        if (!used[i]) dfs(i);
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < sz(ans); i++) {
        // cout << ans[i];
        cout << char(ans[i] + 'a');
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}