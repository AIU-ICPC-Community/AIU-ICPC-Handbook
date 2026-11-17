#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> potions;
    long long health = 0;

    for (int i = 0; i < n; i++) {
        long long value;
        cin >> value;

        health += value;
        potions.push(value);

        if (health < 0) {
            health -= potions.top();
            potions.pop();
        }
    }

    cout << potions.size() << '\n';
    return 0;
}
