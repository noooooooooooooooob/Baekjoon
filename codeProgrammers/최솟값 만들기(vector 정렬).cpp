#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { 
  return a > b; 
}

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(),B.end(),cmp); // sort 나만의 정렬 이용하기
    //sort(B.rbegin(),B.rend()); -> 내림차순 정렬
    int answer = 0;
    for(int i=0;i<A.size();i++)
        answer += A[i] * B[i];
    return answer;
}
