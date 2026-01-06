// https://cses.fi/problemset/task/1623/
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
#define ll long long

using namespace std;
int n;

vector<int> a;
ll sum = 0;

ll solve(int i, ll rsum) {
  if (i >= n) {
    return rsum;
  }
  ll with = solve(i + 1, rsum - a[i]);
  ll without = solve(i + 1, rsum);
  if (abs((sum - with) - with) < abs(sum - without - without)) {
    return with;
  }
  return without;
}

int main() {
  cin >> n;

  a.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll res = solve(0, sum);
  cout << abs((sum - res) - res);
}
