/**
 * a.cpp
 *
 * Written on Tuesday, 4 October 2022.
 */

#include <bits/stdc++.h>

using namespace std;

int parseInt(string s) {
  int res = 0;

  for (int i = 0; i < (int) s.size(); i++) {
    res *= 10;
    res += s[i] - '0';
  }
  return res;
}

void dijkstra() {

  // TODO read input and declare values later
  int n = 200;

  // if there is no edge, distance is -1
  vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, -1));


  string s, t;
  for (int i = 0; i < n; i++) {

    getline(cin, s, '\n');
    stringstream stream(s);
    int tail;
    stream >> tail;

    while (stream >> t) {
      int head, dist, idx = 0;

      while (t[idx] != ',') {
        idx++;
      }

      head = parseInt(t.substr(0, idx));
      dist = parseInt(t.substr(idx + 1, t.size() - idx - 1));
      adjacencyMatrix[tail][head] = dist;
    }
  }

  int source = 1;
  // v
  vector<int> distances(n + 1, INT_MAX);
  distances[source] = 0;

  // length, id, explored
  vector<tuple<int, int, bool>> priority_queue;

  // v
  vector<int> predecessor;

  priority_queue.push_back(make_tuple(0, source, false));
  int head, dist, idx;

  bool check = false;

  // o(v* (v + e));
  // o (v^2 + ve)

  int cnt1 = 0, cnt2 = 0;
  // e
  while (!check) {
    check = true;
    dist = INT_MAX;

    cnt1++;
    // biggest pq can be is size of edges (e)
    for (int i = 0; i < (int) priority_queue.size(); i++) {
      tuple<int, int, bool> x = priority_queue[i];
      check &= get<2>(x);
      cnt2++;
      if (get<0>(x) < dist && !get<2>(x)) {
        dist = get<0>(x);
        head = get<1>(x);
        idx = i;
      }
    }

    priority_queue[idx] = make_tuple(dist, head, true);
    distances[head] = min(dist, distances[head]);

    int newDist;

    // vertices (v)
    for (int i = 0; i < (int) adjacencyMatrix[head].size(); i++) {
      newDist = adjacencyMatrix[head][i];
      if (newDist != -1) {
        if (distances[head] + newDist < distances[i])
          priority_queue.push_back(make_tuple(distances[head] + newDist, i, false));
      }
    }
  }

  for (int i = 0; i <= 200; i++) {
    cout << i << " - " << distances[i] << endl;
  }
  cout << cnt1 << " " << cnt2 << endl;
}

int main()
{
  dijkstra();
}
