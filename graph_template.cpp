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

// dfs to count cc
void dfs(int u, unordered_set<int> &visited) {                                                            
  visited.insert(u);
  for (auto &v : adjList[u])                     
    if (visited.find(v)==visited.end()) dfs(v);                                    
}

for(int i=0;i<n;i++) {
    if(visited.find(i)==visited.end()) {
      cc++;
      dfs(i,visited,adj);
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

// toposort DFS
void toposort(int u) {
  dfs_num[u] = VISITED;
  for (auto &[v, w] : AL[u])
    if (dfs_num[v] == UNVISITED)
      toposort(v);
  ts.push_back(u);                               
}

for (int u = 0; u < V; ++u)                    
    if (dfs_num[u] == UNVISITED)
      toposort(u);
  reverse(ts.begin(), ts.end());

// Returns true if the graph is bipartite, false otherwise.
// V: number of vertices (0…V-1), adj: adjacency list.
bool isBipartite(int V, const vector<vector<int>>& adj) {
    vector<int> color(V, -1);
    queue<int> q;

    for (int src = 0; src < V; ++src) {
        if (color[src] != -1) continue;

        color[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    // Assign opposite color to neighbour
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    // Found same‐color neighbor → not bipartite
                    return false;
                }
            }
        }
    }
    return true;
}
typedef vector<int> vi;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
vector<pair<int,int>> bridges;

dfs_num.assign(p, -1); dfs_low.assign(p, 0);
dfs_parent.assign(p, -1); articulation_vertex.assign(p, 0);
bridges.clear();
dfsNumberCounter = 0;

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;  // dfs_low[u]<=dfs_num[u]
  for (auto &[v, w] : AL[u]) {
    if (dfs_num[v] == UNVISITED) {               // a tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) ++rootChildren;          // special case, root

      articulationPointAndBridge(v);

      if (dfs_low[v] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = 1;              // store this info first
      if (dfs_low[v] > dfs_num[u]) {
        bridges.emplace_back(u, v);
      }               // for bridge
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // subtree, always update
    }
    else if (v != dfs_parent[u])                 // if a non-trivial cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);  // then can update
  }
}