#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<long long> arr(2 * N);
        vector<long long> sale;
        
        for (int i = 0; i < 2 * N; i++) {
            cin >> arr[i];
        }

        // 오름차순으로 정렬된 상태를 유지하고, 순차적으로 처리
        vector<bool> used(2 * N, false);  // 사용 여부를 체크하는 배열
        
        for (int i = 0; i < 2 * N; i++) {
            if (!used[i]) {  // 아직 사용되지 않은 경우에만 검사
                long long discountPrice = arr[i];
                long long normalPrice = discountPrice * 4 / 3;

                // 정상가격과 매칭되는지 확인
                for (int j = i + 1; j < 2 * N; j++) {
                    if (!used[j] && arr[j] == normalPrice) {
                        sale.push_back(discountPrice);
                        used[i] = true;
                        used[j] = true;
                        break;
                    }
                }
            }
        }

        // 출력
        cout << "Case #" << t << ": ";
        for (long long price : sale) {
            cout << price << " ";
        }
        cout << endl;
    }

    return 0;
}
