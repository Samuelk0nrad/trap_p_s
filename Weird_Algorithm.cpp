// https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(ll n) {
  if (n == 1) {
    return;
  }
  if (n % 2 == 0)
    n /= 2;
  else
    n = n * 3 + 1;
  cout << n << " ";
  solve(n);
}

int main() {
  ll n;
  cin >> n;
  cout << n << " ";
  solve(n);
}
