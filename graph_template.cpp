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

// Template 1: Count the number of strongly-connected components
int kosaraju_count_scc(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<int> order;
    order.reserve(n);

    // 1) DFS to build finish order
    function<void(int)> dfs1 = [&](int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i);
    }

    // 2) Build the reversed graph
    vector<vector<int>> radj(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            radj[v].push_back(u);
        }
    }

    // 3) DFS in reverse finish order on the reversed graph
    fill(vis.begin(), vis.end(), false);
    int scc_count = 0;
    function<void(int)> dfs2 = [&](int u) {
        vis[u] = true;
        for (int v : radj[u]) {
            if (!vis[v]) dfs2(v);
        }
    };
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (!vis[u]) {
            dfs2(u);
            scc_count++;
        }
    }

    return scc_count;
}

// Template 2: Find the size of the largest strongly-connected component
int kosaraju_max_scc_size(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    vector<int> order;
    order.reserve(n);

    // 1) DFS to build finish order
    function<void(int)> dfs1 = [&](int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i);
    }

    // 2) Build the reversed graph
    vector<vector<int>> radj(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            radj[v].push_back(u);
        }
    }

    // 3) DFS in reverse finish order on the reversed graph, tracking component sizes
    fill(vis.begin(), vis.end(), false);
    int max_size = 0;
    function<int(int)> dfs2_count = [&](int u) {
        vis[u] = true;
        int cnt = 1;
        for (int v : radj[u]) {
            if (!vis[v]) cnt += dfs2_count(v);
        }
        return cnt;
    };
    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        if (!vis[u]) {
            int sz = dfs2_count(u);
            max_size = max(max_size, sz);
        }
    }

    return max_size;
}

// bellmann ford for negative cycle graph
vector<int> dist(n,numeric_limits<int>::max());
vector<tuple<int,int,int>> edges;
dist[s]=0;
for(int i=0;i<n-1;i++) {
  bool modified=false;
  for (auto& [u,v,w] : edges) {
    if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
      dist[v] = dist[u] + w;
      modified = true;
    }
  }
  if (!modified) break;
}

// find all nodes part of negative cycle
vector<bool> neg(n,false);
for(auto &[x,y,z]:edges){
  if(dist[x]!=numeric_limits<int>::max()&&dist[x]+z<dist[y]) {
    neg[y]=true;
  }
}

const ll INF = (ll)1e15;

// Returns an n×n distance matrix where d[i][j] is the shortest path from i to j.
// dist should be initialized so that dist[i][i]=0, dist[u][v]=w for each edge (u,v,w),
// and INF elsewhere.
vector<vector<long long>> floydWarshall(int n, vector<vector<long long>> dist) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}
// propagate negative cycle
vector<vector<bool>> neg(n, vector<bool>(n, false));
    for (int k = 0; k < n; k++) {
        if (dist[k][k] < 0) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INF) continue;
                    neg[i][j] = true;
                }
            }
        }
    }

// APSP with path reconstruction
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (dist[i][k] == INF) continue;
      for (int j = 0; j < n; ++j) {
        if (dist[k][j] == INF) continue;
        ll alt=dist[i][k] + dist[k][j];
        if(alt<dist[i][j]) {
          dist[i][j]=alt;
          nxt[i][j]=nxt[i][k];
        }
      }
    }
  }

// APSP finding shortest cycle
ll best=INF;
  int bu=-1,bv=-1;
  for(int u=0;u<n;u++) {
    for(int v=0;v<n;v++) {
      if(!adj[u][v]) continue;
      if(dist[v][u]==INF) continue; // no way back
      ll cycleLen=1+dist[v][u];
      if(cycleLen<best) {
        best=cycleLen;
        bu=u;
        bv=v;
      }
    }
  }