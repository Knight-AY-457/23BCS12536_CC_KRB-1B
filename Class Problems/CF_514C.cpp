#include <bits/stdc++.h>
using namespace std;

const long long MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const long long BASE1 = 131, BASE2 = 137;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<pair<long long,long long>> dict;
    auto getHash = [](const string& s) -> pair<long long, long long> {
        long long h1 = 0, h2 = 0;
        for (char c : s) {
            h1 = (h1 * BASE1 + c) % MOD1;
            h2 = (h2 * BASE2 + c) % MOD2;
        }
        return {h1, h2};
    };
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict.insert(getHash(s));
    }
    while (m--) {
        string s;
        cin >> s;
        int len = s.size();
        bool found = false;
        for (int i = 0; i < len && !found; i++) {
            char orig = s[i];
            char next_c;
            if (orig == 'a') next_c = 'b';
            else if (orig == 'b') next_c = 'c';
            else next_c = 'a';

            s[i] = next_c;
            if (dict.count(getHash(s))) found = true;
            s[i] = orig;
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}
