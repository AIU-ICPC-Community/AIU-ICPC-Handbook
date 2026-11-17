#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n;
        cin >> n;

        vector<long long> position(n);
        vector<long long> dressing(n);
        for (long long &value : position) cin >> value;
        for (long long &value : dressing) cin >> value;

        long long rightSide = LLONG_MIN / 2;
        long long leftSide = LLONG_MIN / 2;

        for (int i = 0; i < n; i++) {
            rightSide = max(rightSide, position[i] + dressing[i]);
            leftSide = max(leftSide, dressing[i] - position[i]);
        }

        double meetingPoint = (rightSide - leftSide) / 2.0;
        cout << fixed << setprecision(1) << meetingPoint << '\n';
    }

    return 0;
}
