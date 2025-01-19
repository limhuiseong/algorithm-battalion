#include <iostream>
#include <list>

using namespace std;

string s;
list<char> l;
int M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for (auto c: s)
        l.push_back(c);
    
    auto cursor = l.end();
    cin >> M;
    while (M--) {
        char op;
        cin >> op;
        
        switch (op)
        {
        case 'L':
            if (cursor != l.begin())
                cursor--;
            break;
        case 'D':
            if (cursor != l.end())
                cursor++;
            break;
        case 'B':
            if (cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);
            }
            break;
        case 'P':
            char c;
            cin >> c;
            l.insert(cursor, c);
            break;
        default:
            break;
        }
    }

    for (auto c: l)
        cout << c;
    cout << '\n';
}