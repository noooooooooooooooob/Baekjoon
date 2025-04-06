#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    unordered_map<string,string> passwords;
    for(int i=0;i<N;i++){
        string name,password;
        cin>>name>>password;
        passwords[name] = password;
    }
    for(int i=0;i<M;i++)
    {
        string site;
        cin>>site;
        cout<<passwords[site]<<'\n';
    }
    return 0;
}
