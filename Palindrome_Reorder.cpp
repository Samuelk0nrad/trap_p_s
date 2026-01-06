#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;

  int a[27] = {0};

  for (char c : s) {
    a[c - 64]++;
  }

  string res = "";

  int middle = 0;
  bool no = false;
  for (int i = 1; i <= 26; ++i) {
    if (a[i] % 2 == 1) {
      if (middle != 0) {
        no = true;
        break;
      } else {
        middle = i;
        a[i]--;
      }
    }
  }

  if (no) {
    cout << "NO SOLUTION";
    return 0;
  }

  for (int i = 1; i <= 26; ++i) {
    for (int j = 0; j < a[i] / 2; ++j) {
      res += char(i + 64);
    }
  }

  if (middle != 0) {
    res += char(middle + 64);
  }

  for (int i = 26; i >= 1; --i) {
    for (int j = 0; j < a[i] / 2; ++j) {
      res += char(i + 64);
    }
  }

  cout << res;
}
