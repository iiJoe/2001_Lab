/**
 * b.cpp
 *
 * Written on Tuesday, 4 October 2022.
 */

#include <bits/stdc++.h>
#include <queue>

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

  int n;
  cin >> n;

  // if there is no edge, distance is -1
  // vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1, -1));
  // tail -> (head, dist)
  map<int, map<int, int>> adjacencyList;


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
      adjacencyList[tail][head] = dist;
    }
  }

  int source = 1;
  vector<int> distances(n + 1, INT_MAX);
  distances[source] = 0;

  // length, id
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority_queue;
  vector<int> predecessor;

  priority_queue.push(make_pair(0, source));
  int head, dist;

  int minCount = 0, edgeCount = 0;
  // Iterate until priority queue is empty: O(e)
  while (!priority_queue.empty()) {

    // Finding next min element to process: O(1)
    dist = priority_queue.top().first;
    head = priority_queue.top().second;

    minCount++;

    // Removing min element: log (e)
    priority_queue.pop();
    if (dist != distances[head]) continue;

    // Considering every incident edge: O(v)
    for (auto edge : adjacencyList[head]) {
      edgeCount++;
      if (distances[head] + edge.second < distances[edge.first]) {
        distances[edge.first] = distances[head] + edge.second;
        // Adding into priority queue: O(log e)
        priority_queue.push(make_pair(distances[edge.first], edge.first));
      }
    }
  }
  // O(e * (log e + v * log e)) = O(v * e * log e);

  for (int i = 1; i <= n; i++) {
    cout << i << " - " << distances[i] << endl;
  }
  cout << "MinCount: " << minCount << endl;
  cout << "edgeCount: " << edgeCount << endl;
}

int main()
{
  dijkstra();
}
