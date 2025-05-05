// returns #inversions in A[l..r), and sorts A[l..r) in-place
long long merge_count(vector<int>& A, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2;
    long long inv = merge_count(A, l, m)
                  + merge_count(A, m, r);

    vector<int> tmp;
    tmp.reserve(r-l);
    int i = l, j = m;
    while (i < m || j < r) {
        if (j == r || (i < m && A[i] <= A[j])) {
            tmp.push_back(A[i++]);
        } else {
            tmp.push_back(A[j++]);
            inv += (m - i);  // every A[i..m-1] > A[j-1]
        }
    }
    for (int k = 0; k < (int)tmp.size(); ++k)
        A[l + k] = tmp[k];

    return inv;
}

// helper to call it:
long long count_inversions(vector<int> A) {
    return merge_count(A, 0, A.size());
}


// Stable counting sort used by radixSort, sorting by digit at exp (1,10,100,…)
void countingSort(vector<long long>& a, long long exp) {
    int n = a.size();
    vector<long long> output(n);
    int cnt[10] = {0};

    // count occurrences of each digit
    for (auto x : a)
        cnt[(x / exp) % 10]++;

    // prefix sums
    for (int i = 1; i < 10; i++)
        cnt[i] += cnt[i - 1];

    // build output (in reverse for stability)
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] / exp) % 10;
        output[--cnt[d]] = a[i];
    }

    // copy back
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// Main radix-sort routine
void radixSort(vector<long long>& a) {
    if (a.empty()) return;
    long long mx = *max_element(a.begin(), a.end());
    for (long long exp = 1; mx / exp > 0; exp *= 10)
        countingSort(a, exp);
}

// Radix sorting by 16-bit chunks
void countingSort(vector<long long>& a, int shift) {
    int n = a.size();
    const int B=1<<16; // 16-bit base
    vector<long long> output(n);
    vector<int> cnt(B, 0);

    // count occurrences of each digit
    for (auto x : a) {
        int d = (x >> shift) & 0xFFFF;
        cnt[d]++;
    }
    // prefix sums
    for (int i = 1; i < B; i++)
        cnt[i] += cnt[i - 1];

    // build output (in reverse for stability)
    for (int i = n - 1; i >= 0; i--) {
        int d = (a[i] >> shift) & 0xFFFF;
        output[--cnt[d]] = a[i];
    }

    // copy back
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// Main radix-sort routine
void radixSort(vector<long long>& a) {
    if (a.empty()) return;
    countingSort(a,0);
    countingSort(a,16);
}