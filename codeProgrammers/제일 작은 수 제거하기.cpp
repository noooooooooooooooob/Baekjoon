#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1)
        return vector<int>(1 , -1);
    arr.erase(remove(arr.begin(), arr.end(), *min_element(arr.begin(), arr.end())), arr.end());
    return arr;
}
