#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edg(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    set<array<int, 3>> skip;
    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--, z--;
        skip.insert({ x,y,z });
    }

    queue<array<int, 3>> q; // {cur , prev , distance}
    q.push({ 0, -1, 0 });

    map<pair<int, int>, pair<int, int>> mp; // {cur, prev} -> {prev, mp of prev}
    mp[{0, -1}] = { -1, -1 };

    while (!q.empty()) {
        array<int, 3> x = q.front();
        // cout << x[0] << " ";
        q.pop();
        if (x[0] == n - 1) {
            cout << x[2] << endl;
            vector<int> a;
            pair<int, int> node = { x[0], x[1] };
            while (node.first != -1) {
                a.push_back(node.first + 1);
                node = mp[node];
            }
            reverse(a.begin(), a.end());
            for (int p : a) {
                cout << p << " ";
            }
            return 0;
        }

        for (int nbr : edg[x[0]]) {
            if (skip.count({ x[1], x[0], nbr }) || mp.count({ nbr, x[0] })) continue;
            mp[{ nbr, x[0] }] = { x[0], x[1] };
            q.push({ nbr, x[0], x[2] + 1 });
        }
    }

    cout << -1;
    return 0;
}
