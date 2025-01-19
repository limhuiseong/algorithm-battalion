#include <iostream>
#include <stack>

using namespace std;

stack<char> s;
string ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string sentence;
        getline(cin, sentence);

        if (sentence == ".")
            break;
        
        ans = "yes";

        for (const char c: sentence) {
            switch (c)
            {
            case '(':
                s.push('(');
                break;
            case '[':
                s.push('[');
                break;
            case ')':
                if (s.empty() || s.top() != '(')
                    ans = "no";
                else
                    s.pop();
                break;
            case ']':
                if (s.empty() || s.top() != '[')
                    ans = "no";
                else
                    s.pop();
                break;
            default:
                break;
            }
        }

        if (!s.empty())
            ans = "no";
        
        cout << ans << '\n';

        while (!s.empty())
            s.pop();
    }


}