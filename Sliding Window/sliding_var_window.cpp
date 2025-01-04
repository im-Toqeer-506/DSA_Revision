#include <iostream>
#include <vector>
using namespace std;
class LongestRepeatingCharacterReplacement
{
public:
    int characterReplacement(string &s, int k)
    {
        vector<int> freq(26, 0);
        int l = 0;
        int maxFreq = 0;
        int maxWindow = 0;
        for (int r = 0; r < s.size(); ++r)
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            int windowLength = r - l + 1;
            if (windowLength - maxFreq > k)
            {
                freq[s[l] - 'A']--;
                ++l;
            }
            windowLength = r - l + 1;
            maxWindow = max(maxWindow, windowLength);
        }
        return maxWindow;
    }
};

int main()
{
    LongestRepeatingCharacterReplacement solver;
    string s = "AABABBACAC";
    int k = 1;
    cout << "Longest Repeating Character Replacement: "<< solver.characterReplacement(s, k) << endl;
    return 0;
}
