#include <bits/stdc++.h>
using namespace std;

vector<int> naiveSearch(const string& text, const string& pat) {
    vector<int> result;
    int n = text.size(), m = pat.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j]) j++;
        if (j == m) result.push_back(i);
    }
    return result;
}

vector<int> computeLPS(const string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> kmpSearch(const string& text, const string& pat) {
    vector<int> result;
    int n = text.size(), m = pat.size();
    vector<int> lps = computeLPS(pat);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) { i++; j++; }
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pat[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return result;
}

vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

vector<int> zSearch(const string& text, const string& pat) {
    vector<int> result;
    string concat = pat + "$" + text;
    vector<int> z = zFunction(concat);
    int m = pat.size();
    for (int i = m + 1; i < (int)concat.size(); i++) {
        if (z[i] == m) result.push_back(i - m - 1);
    }
    return result;
}

vector<int> rabinKarp(const string& text, const string& pat) {
    vector<int> result;
    int n = text.size(), m = pat.size();
    const long long BASE = 31, MOD = 1e9 + 9;

    long long patHash = 0, textHash = 0, power = 1;

    for (int i = 0; i < m; i++) {
        patHash = (patHash * BASE + (pat[i] - 'a' + 1)) % MOD;
        textHash = (textHash * BASE + (text[i] - 'a' + 1)) % MOD;
        if (i > 0) power = (power * BASE) % MOD;
    }

    if (patHash == textHash && text.substr(0, m) == pat)
        result.push_back(0);

    for (int i = 1; i <= n - m; i++) {
        textHash = (textHash - (text[i - 1] - 'a' + 1) * power % MOD + MOD) % MOD;
        textHash = (textHash * BASE + (text[i + m - 1] - 'a' + 1)) % MOD;
        if (textHash == patHash && text.substr(i, m) == pat)
            result.push_back(i);
    }
    return result;
}

void printMatches(const string& name, const vector<int>& matches) {
    cout << name << " matches at: ";
    for (int idx : matches) cout << idx << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string text, pat;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pat;
    cout << "\n--- Pattern Matching Results ---\n";
    printMatches("Naive        ", naiveSearch(text, pat));
    printMatches("KMP          ", kmpSearch(text, pat));
    printMatches("Z-Algorithm  ", zSearch(text, pat));
    printMatches("Rabin-Karp   ", rabinKarp(text, pat));

    cout << "\nLPS array for pattern \"" << pat << "\": ";
    for (int v : computeLPS(pat)) cout << v << " ";
    cout << "\n";
    cout << "Z-array for pattern \"" << pat << "\": ";
    for (int v : zFunction(pat)) cout << v << " ";
    cout << "\n";
    return 0;
}
