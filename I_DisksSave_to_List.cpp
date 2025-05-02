#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<array<ll, 3>> a(n);
    for (ll i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        a[i] = { x,y,z };
    }

    auto sqr = [&](ll a)->ll {
        return a * a;
        };

    string color(n, '\0');

    for (ll i = 0; i < n; i++) {
        if (color[i] != '\0') continue;
        color[i] = 'P';
        ll cntp = 0, cntq = 0, isBipartite = 1;
        queue<ll> q;
        q.push(i);
        while (q.size()) {
            ll cur = q.front();
            q.pop();
            if (color[cur] == 'P')cntp++;
            else cntq++;
            for (ll nxt = 0; nxt < n; nxt++) {
                if (nxt == cur) continue;
                if ((sqr(a[cur][0] - a[nxt][0]) + sqr(a[cur][1] - a[nxt][1])) == sqr(a[cur][2] + a[nxt][2])) {
                    if (color[nxt] == '\0') {
                        color[nxt] = (color[cur] ^ 'P' ^ 'Q');
                        q.push(nxt);
                    }
                    else if (color[nxt] == color[cur]) isBipartite = 0;
                }
            }
        }
        if (isBipartite && cntp != cntq) {
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";
    return 0;
}