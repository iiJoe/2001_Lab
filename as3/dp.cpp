/**
 * dp.cpp
 *
 * Written on Friday,28 October 2022.
 */

#include <bits/stdc++.h>

using namespace std;

void solve()
{
  int n, C;

  cin >> n >> C;
  vector<int> w(n), p(n);

  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> p[i];

  vector<pair<int, vector<int>>> dp(C + 1, make_pair(INT_MIN, vector<int>()));
  dp[0].first = 0;

  // looping capacities from 1 to C
  for (int i = 1; i <= C; i++) {
    // checking all the objects
    dp[i] = dp[i - 1];
    for (int j = 0; j < n; j++) {
      if (w[j] <= i) {
        if (dp[i - w[j]].first + p[j] > dp[i].first) {
          dp[i] = dp[i - w[j]];
          dp[i].first += p[j];
          dp[i].second.push_back(j);
        }
      }
    }
  }

  cout << dp[C].first << endl << "Set of Items: {";

  for (int i : dp[C].second) {
    cout << i << ",";
  }
  cout << "}" <<  endl;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
}
