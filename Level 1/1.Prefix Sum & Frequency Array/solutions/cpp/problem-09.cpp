#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    long long total = 0;
    for (long long &value : a) {
        cin >> value;
        total += value;
    }

    if (n < 3 || total % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    long long part = total / 3;
    long long prefix = 0;
    long long firstCuts = 0;
    long long answer = 0;

    for (int i = 0; i < n - 1; i++) {
        prefix += a[i];
        if (prefix == 2 * part) answer += firstCuts;
        if (prefix == part) firstCuts++;
    }

    cout << answer << '\n';
    return 0;
}
