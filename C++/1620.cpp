#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cctype>
#include <unordered_map>

// unordered_map 예제

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> Pokemons(N + 1);
    unordered_map<string, int> nameToIndex;

    for(int i = 1; i <= N; ++i)
    {
        cin >> Pokemons[i];
        nameToIndex[Pokemons[i]] = i;
    }

    string input;
    while(M--)
    {
        cin >> input;
        if(isdigit(input[0]))
        {
            int idx = stoi(input);
            cout << Pokemons[idx] << '\n';
        }
        else
        {
            cout << nameToIndex[input] << '\n';
        }
    }

    return 0;
}
