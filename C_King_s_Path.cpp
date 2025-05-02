#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int x0, y0, x1, y1, m;
    cin >> x0 >> y0 >> x1 >> y1 >> m;

    unordered_map<int, vector<pair<int, int>>> check;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        check[x].push_back({ y,z });
    }

    int dx[] = { 1,0,-1,0,1,-1,1,-1 };
    int dy[] = { 0,1,0,-1,1,-1,-1,1 };

    auto isAllowed = [&](int x, int y)->bool {
        if (check.count(x)) {
            for (auto cur : check[x]) {
                if (y >= cur.first && y <= cur.second)return true;
            }
        }
        return false;
        };

    map <pair<int, int>, int> dis;
    queue <pair<int, int>> q;

    dis[{x0, y0}] = 0;
    q.push({ x0, y0 });

    while (q.size()) {
        //     cout << "..";
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == x1 && cur.second == y1) {
            cout << dis[cur];
            return 0;
        }
        for (int i = 0; i < 8; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x > 1e9 || x < 1 || y > 1e9 || y < 1)continue;
            if (!isAllowed(x, y) || dis.count({ x,y }))continue;
            dis[{x, y}] = dis[cur] + 1;
            q.push({ x,y });
        }
    }
    cout << -1;
}