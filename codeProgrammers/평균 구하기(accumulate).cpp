#include <string>
#include <vector>
#include <numeric> // accumulate 함수 사용

using namespace std;

double solution(vector<int> arr) {
    // accumulate(첫 번째 인자, 마지막 인자, 반환형 0 = int, 0.0 = double, 0LL = long long)
    return accumulate(arr.begin(), arr.end(), 0.0) / (double)arr.size();
}
