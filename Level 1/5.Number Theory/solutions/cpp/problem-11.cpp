#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int maximum = 0;
    for (int &value : a) {
        cin >> value;
        maximum = max(maximum, value);
    }

    vector<int> largestUpTo(maximum + 1, 0);
    for (int value : a) largestUpTo[value] = value;
    for (int value = 1; value <= maximum; value++)
        largestUpTo[value] = max(largestUpTo[value], largestUpTo[value - 1]);

    int answer = 0;

    for (int divisor = 1; divisor <= maximum; divisor++) {
        if (largestUpTo[divisor] != divisor) continue;

        for (int start = divisor; start <= maximum; start += divisor) {
            int end = min(maximum, start + divisor - 1);
            int candidate = largestUpTo[end];
            if (candidate >= start) answer = max(answer, candidate - start);
        }
    }

    cout << answer << '\n';
    return 0;
}
