#include <iostream>
using namespace std;

// 최대공약수
int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// 최소공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int limit = lcm(M, N);
        int result = -1;

        for (int k = 0; x + k * M <= limit; ++k) {
            int year = x + k * M;

            if ((year - 1) % N + 1 == y) {
                result = year;
                break;
            }
        }

        cout << result << "\n";
    }

    return 0;
}
