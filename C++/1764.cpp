#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    vector<string> answer;
    for(int i=0;i<N;i++)
        cin >> A[i];
    sort(A.begin(),A.end());

    for(int i=0;i<M;i++)
        cin >> B[i];
    sort(B.begin(),B.end());

    int Aidx=0,Bidx=0;
    int Asize = A.size();
    int Bsize = B.size();
    while(Aidx<Asize && Bidx<Bsize)
    {
        if(A[Aidx] == B[Bidx])
        {
            answer.push_back(A[Aidx]);
            Aidx++;
            Bidx++;
        }
        else if(A[Aidx] < B[Bidx])
            Aidx++;
        else
            Bidx++;
    }

    cout<<answer.size()<<'\n';
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<'\n';
    return 0;
}


// GPT 피셜 효율이 좋은 코드
// 시간은 차이가 없고 메모리가 약 28% 효율적
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> unheard;
    vector<string> result;

    string name;

    // 듣도 못한 사람 저장
    for (int i = 0; i < N; ++i) {
        cin >> name;
        unheard.insert(name);
    }

    // 보도 못한 사람 확인하면서 교집합 찾기
    for (int i = 0; i < M; ++i) {
        cin >> name;
        if (unheard.find(name) != unheard.end()) {
            result.push_back(name);
        }
    }

    // 결과 사전순 정렬
    sort(result.begin(), result.end());

    // 출력
    cout << result.size() << '\n';
    for (const string& person : result) {
        cout << person << '\n';
    }

    return 0;
}
