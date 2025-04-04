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
// only to 10^38
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

class BigInt {
public:
    // s holds the digits (without any sign) in normal order (most-significant digit first)
    // negative is true if the number is negative.
    string s;
    bool negative;

    // Default constructor: zero.
    BigInt() : s("0"), negative(false) {}

    // Construct from string (which may begin with '-' for negative numbers)
    BigInt(const string &str) {
        int pos = 0;
        negative = false;
        if(str[0] == '-') { 
            negative = true;
            pos++;
        }
        // Skip any leading zeros.
        while(pos < str.size() && str[pos] == '0')
            pos++;
        if(pos == str.size()){
            s = "0";
            negative = false;
        } else {
            s = str.substr(pos);
        }
    }

    // Return the string representation (with a '-' if negative and not zero).
    string toString() const {
        return (negative && s != "0" ? "-" : "") + s;
    }

    // Compare absolute values.
    // Returns -1 if |this| < |other|, 0 if equal, and 1 if greater.
    int compare_abs(const BigInt &other) const {
        if(s.size() < other.s.size()) return -1;
        if(s.size() > other.s.size()) return 1;
        if(s == other.s) return 0;
        return (s < other.s) ? -1 : 1;
    }

    // Full comparison (taking sign into account).
    int compare(const BigInt &other) const {
        if(negative != other.negative)
            return negative ? -1 : 1;
        if(!negative)
            return compare_abs(other);
        else
            return -compare_abs(other); // if both negative, order is reversed.
    }

    bool operator<(const BigInt &other) const {
        return compare(other) < 0;
    }

    bool operator==(const BigInt &other) const {
        return negative == other.negative && s == other.s;
    }

    // Helper: add two non-negative numbers given as strings.
    static string add_str(const string &a, const string &b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string result;
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result.push_back('0' + (sum % 10));
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // Helper: subtract two non-negative numbers given as strings.
    // Assumes a >= b.
    static string sub_str(const string &a, const string &b) {
        int i = a.size()-1, j = b.size()-1, carry = 0;
        string result;
        while(i >= 0) {
            int diff = (a[i] - '0') - carry;
            if(j >= 0) diff -= (b[j] - '0');
            if(diff < 0) { diff += 10; carry = 1; } else { carry = 0; }
            result.push_back('0' + diff);
            i--; j--;
        }
        reverse(result.begin(), result.end());
        // Remove leading zeros.
        int pos = 0;
        while(pos < result.size()-1 && result[pos]=='0')
            pos++;
        return result.substr(pos);
    }

    // Addition operator.
    BigInt operator+(const BigInt &other) const {
        BigInt result;
        // If the signs are the same, add the absolute values.
        if(!negative && !other.negative) {
            result.s = add_str(s, other.s);
            result.negative = false;
        } else if(negative && other.negative) {
            result.s = add_str(s, other.s);
            result.negative = true;
        } else if(!negative && other.negative) {
            // a + (-b) = a - b.
            if(compare_abs(other) >= 0) {
                result.s = sub_str(s, other.s);
                result.negative = false;
            } else {
                result.s = sub_str(other.s, s);
                result.negative = true;
            }
        } else { // negative && !other.negative, i.e., (-a) + b = b - a.
            if(compare_abs(other) > 0) {
                result.s = sub_str(s, other.s);
                result.negative = true;
            } else {
                result.s = sub_str(other.s, s);
                result.negative = false;
            }
        }
        if(result.s == "0")
            result.negative = false;
        return result;
    }

    // Subtraction operator.
    BigInt operator-(const BigInt &other) const {
        BigInt negOther = other;
        negOther.negative = !other.negative;
        return *this + negOther;
    }

    // Multiply the BigInt by an integer factor (assumes factor >= 0).
    BigInt multiply_by_int(int factor) const {
        if(factor == 0 || s == "0")
            return BigInt("0");
        int carry = 0;
        string result;
        for (int i = s.size()-1; i >= 0; i--){
            int prod = (s[i] - '0') * factor + carry;
            carry = prod / 10;
            result.push_back('0' + (prod % 10));
        }
        while(carry) {
            result.push_back('0' + (carry % 10));
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        BigInt ret(result);
        ret.negative = negative; // factor is positive so sign stays the same.
        return ret;
    }

    // Multiply by 10.
    BigInt multiply_by_10() const {
        if(s == "0") return *this;
        BigInt ret;
        ret.s = s + "0";
        ret.negative = negative;
        return ret;
    }

    // Long-division algorithm (for non-negative BigInts).
    // Returns a pair {quotient, remainder}.
    // Assumes both *this and divisor are non-negative and divisor is not 0.
    pair<BigInt, BigInt> divmod(const BigInt &divisor) const {
        if(divisor.s == "0") { throw runtime_error("Division by zero"); }
        string q;
        BigInt remainder("0");
        for (char digit : s) {
            remainder = remainder.multiply_by_10();
            BigInt d(string(1, digit));
            remainder = remainder + d;
            int count = 0;
            // Subtract divisor until remainder is less than divisor.
            while(remainder.compare(divisor) >= 0) {
                remainder = remainder - divisor;
                count++;
            }
            q.push_back('0' + count);
        }
        // Remove any leading zeros from the quotient.
        int pos = 0;
        while(pos < q.size()-1 && q[pos]=='0')
            pos++;
        BigInt quotient(q.substr(pos));
        return {quotient, remainder};
    }

    // Division operator (assumes non-negative; full sign support could be added if needed).
    BigInt operator/(const BigInt &other) const {
        return divmod(other).first;
    }

    // Modulo operator.
    BigInt operator%(const BigInt &other) const {
        return divmod(other).second;
    }

    // Return the absolute value.
    BigInt abs() const {
        BigInt ret = *this;
        ret.negative = false;
        return ret;
    }

    // Helper: multiply two nonnegative number strings.
    static string multiply_str(const string &a, const string &b) {
        if (a == "0" || b == "0") return "0";
        int n = a.size(), m = b.size();
        vector<int> result(n + m, 0);
        // Multiply digit by digit.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int product = (a[i] - '0') * (b[j] - '0');
                int sum = product + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        // Convert the result vector to a string, skipping leading zeros.
        string str;
        for (int num : result) {
            if (!(str.empty() && num == 0))
                str.push_back('0' + num);
        }
        return str.empty() ? "0" : str;
    }

    // Overload the multiplication operator.
    BigInt operator*(const BigInt &other) const {
        BigInt result;
        result.s = multiply_str(this->s, other.s);
        // The sign of the result is negative if and only if the operands have opposite signs,
        // except if the result is zero.
        result.negative = (this->negative != other.negative) && (result.s != "0");
        return result;
    }
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool isPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

vector<bool> sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

// Extended Euclidean Algorithm to compute gcd and the coefficients x and y for Bézout's identity: ax + by = gcd(a, b)
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

// Function to compute modular inverse of a modulo m
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) {
        // In our problem, this should never happen since a and m are coprime
        return -1;
    }
    // Make sure the result is positive
    x = (x % m + m) % m;
    return x;
}