// TLE

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int min_operations(int x, int y, int k) {
    if (x == y) return 0;
    if (k == 1) return -1;

    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({y, 0});
    visited.insert(y);

    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();

        for (int a = 2; a <= k; ++a) {
            if (curr % a == 0) {
                int next = curr / a;
                if (next == x) return steps + 1;
                if (next >= 1 && !visited.count(next)) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }

        for (int a = 2; a <= k; ++a) {
            long long next = 1LL * curr * a;
            if (next > 1e6) break;
            if (next == x) return steps + 1;
            if (!visited.count(next)) {
                q.push({(int)next, steps + 1});
                visited.insert(next);
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    vector<int> res(t);

    for (int i = 0; i < t; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        res[i] = min_operations(x, y, k);
    }

    for (int ans : res) {
        cout << ans << endl;
    }
    return 0;
}