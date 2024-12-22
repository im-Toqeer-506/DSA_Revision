#include <iostream>
#include <vector>
using namespace std;

class Solution
{
     void Parenthesis(vector<string> &ans, int n, int os, int cs, string str)
    {
        if (str.size() == n * 2)
        {
            ans.push_back(str);
            return;
        }
        if (os < n)
        {
            Parenthesis(ans, n, os + 1, cs, str + "(");
        }
        if (cs < os)
        {
            Parenthesis(ans, n, os, cs + 1, str + ")");
        }
    }
public:
   
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        Parenthesis(result, n, 0, 0, "");
        return result;
    }
};

int main()
{
    Solution s1;
    vector<string>vec1=s1.generateParenthesis(3);
    cout<<"[";
    for(auto &str:vec1)
    {
        cout<<","<<str;
    }
    cout<<"]";
    
}