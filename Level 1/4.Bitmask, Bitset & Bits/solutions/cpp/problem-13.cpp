#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;
int bestFirst = 0, bestSecond = 0;

bool possible(long long limit) {
    int full = (1 << m) - 1;
    vector<int> firstRow(1 << m, -1);

    for (int row = 0; row < n; row++) {
        int mask = 0;
        for (int column = 0; column < m; column++)
            if (a[row][column] >= limit) mask |= 1 << column;
        firstRow[mask] = row;
    }

    for (int left = 0; left <= full; left++) {
        if (firstRow[left] == -1) continue;
        for (int right = left; right <= full; right++) {
            if (firstRow[right] == -1) continue;
            if ((left | right) == full) {
                bestFirst = firstRow[left];
                bestSecond = firstRow[right];
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.assign(n, vector<int>(m));
    for (int row = 0; row < n; row++)
        for (int column = 0; column < m; column++)
            cin >> a[row][column];

    long long low = 0, high = 1000000000;

    while (low < high) {
        long long middle = (low + high + 1) / 2;
        if (possible(middle)) low = middle;
        else high = middle - 1;
    }

    possible(low);
    cout << bestFirst + 1 << ' ' << bestSecond + 1 << '\n';
    return 0;
}
