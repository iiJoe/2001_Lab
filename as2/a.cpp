/**
 * a.cpp
 *
 * Written on Tuesday, 4 October 2022.
 */

#include <bits/stdc++.h>
#include <climits>

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

  // v
  vector<bool> visited(n + 1, false);

  int head;
  int minCount = 0, edgeCount = 0;
  // Looping through every vertex: O(v)
  for (int i = 1; i <= n; i++) {
    head = -1;

    // finding next min element to process: O(v)
    for (int j = 1; j <= n; j++) {
      minCount++;
      if (!visited[j] && (head == -1 || distances[j] < distances[head]))
        head = j;
    }

    visited[head] = true;

    int newDist;

    // Relaxing shortest distances: O(v)
    for (int k = 1; k <= n; k++) {
      edgeCount++;
      newDist = adjacencyMatrix[head][k];
      if (!visited[k] && newDist != -1 && distances[head] != INT_MAX && distances[head] + newDist < distances[k]) {
        distances[k] = distances[head] + newDist;
      }
    }
  }

  for (int i = 0; i <= 200; i++) {
    cout << i << " - " << distances[i] << endl;
  }

  cout << "MinCount: " << minCount << endl;
  cout << "edgeCount: " << edgeCount << endl;
}

int main()
{
  dijkstra();
}
