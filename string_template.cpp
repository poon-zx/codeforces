#include <vector>
#include <string>

// Returns a vector of all positions in 'text' where 'pattern' begins.
std::vector<int> kmp_search(const std::string &text, const std::string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0) return {};                   // no pattern → no matches
    // build “failure” table
    std::vector<int> b(m+1);
    b[0] = -1;
    int i = 0, j = -1;
    while (i < m) {
        while (j >= 0 && pattern[i] != pattern[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
    // search
    std::vector<int> matches;
    i = 0; j = 0;
    while (i < n) {
        while (j >= 0 && text[i] != pattern[j]) j = b[j];
        ++i; ++j;
        if (j == m) {
            matches.push_back(i - j);
            j = b[j];
        }
    }
    return matches;
}