#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare {
    bool operator()(long long a, long long b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<long long, vector<long long>, compare> pq;
    int n;
    cin >> n;
    while (n--) {
        long long input;
        cin >> input;

        if (input == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(input);
        }
    }
    return 0;
}
