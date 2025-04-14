#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// priority queue 
// priority_queue<'자료형', '구현체', '비교연산자'> 이름;
// 구현체 => 보통 vector , 선언하지 않으면 vector가 기본
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int,vector<int>,greater<int>> arr;
    int T;
    cin>>T;
    int input;

    while(T--)
    {
        cin>>input;
        if(input==0)
        {
            if(arr.size() == 0)
                cout<<0;
            else
            {
                cout<<arr.top();
                arr.pop();
            }
            cout<<"\n";
        }
        else
        {
            arr.push(input);
        }
    }
    return 0;
}
