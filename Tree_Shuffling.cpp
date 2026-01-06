// !!!  https://codeforces.com/contest/1363/problem/E
#include <bits/stdc++.h>
#include <vector>

using namespace std;
int n;
vector<vector<int>> edges;
vector<int> a;
vector<int> b;
vector<int> c;

void dfs() {}

set<int> checkST(int node, int p) {
  set<int> res;
  set<int> o;
  for (int e : edges[node]) {
    if (p != e) {
      o = checkST(e, node);
      for (int i : o) {
        if (res.count(i)) {
          res.erase(i);
        } else {
          res.insert(i);
        }
      }
    }
  }
  if (b[node] != a[node]) {
    o.insert(b[node]);
  }
  return res;
}

int main() {
  cin >> n;

  a.assign(n + 1, 0);
  b.assign(n + 1, 0);
  c.assign(n + 1, 0);
  edges.assign(n + 1, {});

  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }

  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
}
