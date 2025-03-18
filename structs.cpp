struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }
    
    bool union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

class FenwickTree {
 public:
  FenwickTree(int n) : n(n), tree(n + 1, 0) {}

  FenwickTree(std::vector<int>& data): FenwickTree(data.size()) {
    for (int i = 1; i <= n; ++i) {
        tree[i] = data[i-1];
        int parent = i + (i & -i);
        if (parent <= n) {
            tree[parent] += tree[i];
        }
    }
  }


  int query(int l, int r) const { return prefix(r) - prefix(l-1); }

  void update(int i, int diff) {
    for (; i <= n; i += i & -i) {
      tree[i] += diff;
    }
  }

  int prefix(int i) const {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

 private:
  const int n;
  std::vector<int> tree;
};

// Helper function to convert __int128 to string
string toString(__int128 n) {
    if (n == 0) return "0";
    bool neg = n < 0;
    if (neg) n = -n;
    string s;
    while (n > 0) {
        s.push_back('0' + (n % 10));
        n /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

// Helper function to convert string to __int128
__int128 toInt128(const string &s) {
    __int128 res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}