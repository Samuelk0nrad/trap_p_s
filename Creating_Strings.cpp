#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long

using namespace std;

void perm(string &s, vector<bool> &used, string &c) {
  if (s.length() == c.length()) {
    cout << c << "\n";
  }
  for (int i = 0; i < s.length(); ++i) {
    if (used[i])
      continue;
    if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
      continue;

    c.push_back(s[i]);
    used[i] = true;
    perm(s, used, c);
    c.pop_back();
    used[i] = false;
  }
}

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());

  int abc[27] = {0};
  for (int i = 0; i < s.length(); ++i) {
    abc[s[i] - 96]++;
  }

  ll factorial[10];
  factorial[0] = 1;
  for (ll i = 1; i < 10; ++i) {
    factorial[i] = factorial[i - 1] * i;
  }

  ll count = factorial[s.length()];

  for (int num : abc) {
    count /= factorial[num];
  }

  cout << count << "\n";

  string c;
  vector<bool> used(s.length());
  perm(s, used, c);

  //  do {
  //    cout << s << "\n";
  //  } while (next_permutation(s.begin(), s.end()));
}
