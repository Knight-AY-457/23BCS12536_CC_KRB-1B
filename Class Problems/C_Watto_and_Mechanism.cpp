#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[3];
    bool end;
    Node() {
        next[0] = next[1] = next[2] = -1;
        end = false;
    }
};

vector<Node> trie(1);

void insert_string(const string &s) {
    int node = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[node].next[idx] == -1) {
            trie[node].next[idx] = trie.size();
            trie.emplace_back();
        }
        node = trie[node].next[idx];
    }
    trie[node].end = true;
}

bool dfs(const string &s, int pos, int node, bool changed) {
    if (pos == s.size())
        return changed && trie[node].end;

    int idx = s[pos] - 'a';

    if (trie[node].next[idx] != -1) {
        if (dfs(s, pos + 1, trie[node].next[idx], changed))
            return true;
    }

    if (!changed) {
        for (int i = 0; i < 3; i++) {
            if (i == idx) continue;
            if (trie[node].next[i] != -1) {
                if (dfs(s, pos + 1, trie[node].next[i], true))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert_string(s);
    }

    while (m--) {
        cin >> s;
        if (dfs(s, 0, 0, false))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}