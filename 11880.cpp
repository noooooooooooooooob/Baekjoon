#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long a, b, c, tmp, sum;
    cin >> N;
    while(N--) {
        cin >> a >> b >> c;
        tmp = max(max(a, b), c);
        if (tmp == a)
            sum = b + c;
        else if (tmp == b)
            sum = a + c;
        else
            sum = b + a;
        // endl은 \n보다 오래 걸려 시간초과가 됨
        cout << sum * sum + tmp * tmp << "\n";
    }
    return 0;
}
