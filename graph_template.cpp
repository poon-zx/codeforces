void bfs(vector<vector<int>> adjList, int starting) {
  set<int> visited;
  queue<int> q;
  q.push(starting);
  visited.insert(starting);
  while (!q.empty()) {
    int first=q.front();
    q.pop();
    for (auto& num:adjList[first]) {
      if (visited.find(num)==visited.end()) {
        visited.insert(num);
        q.push(num);
      }
    }
  }
}

// dfs cycle finding
bool hasCycle(string s) {
  visited[s]=-1;
  for (auto& nei:mapp[s]) {
    if (visited[nei]==-1) {
      return true;
    } else if (visited[nei]==0&&hasCycle(nei)) {
      return true;
    }
  }
  visited[s]=1;
  return false;
}
