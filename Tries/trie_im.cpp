#include <iostream>
#include <vector>
using namespace std;

class Node
{
    Node *links[26];
    bool flag = false;

public:
    bool isEnd()
    {
        return flag;
    }
    bool setEnd()
    {
        flag = true;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void Put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                node->Put(word[i], new Node());
            }
            node = node->get(word[i]);}
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!(node->containsKey(prefix[i])))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true; 
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("applet");
    trie.insert("appneeto");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    cout << trie.startsWith("appnee") << endl;
    return 0;
}
