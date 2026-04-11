#include "bits/stdc++.h"

using namespace std;

struct Node
{
    char c;
    int frequency;
    Node *left;
    Node *right;
    Node()
    {
        left = nullptr;
        right = nullptr;
        frequency = 0;
    }
};

class Compare
{
public:
    bool operator()(const Node *a, const Node *b) const
    {
        if (a->frequency == b->frequency)
        {
            return a->c > b->c;
        }
        return a->frequency > b->frequency;
    }
};

string huffmanCoding(string &text)
{
    /*
        text: string to be compressed
    */

    /*
        Asymptotic Analysis

    */

    if (text.empty())
        return "";

    map<char, int> mp;
    for (char c : text)
        mp[c]++;

    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto [k, v] : mp)
    {
        Node *n = new Node();
        n->c = k;
        n->frequency = v;
        pq.push(n);
    }

    while (pq.size() > 1)
    {
        Node *r = pq.top();
        pq.pop();

        Node *l = pq.top();
        pq.pop();

        // cout << r->c << ' ' << l->c << endl;

        Node *temp = new Node();
        temp->frequency = l->frequency + r->frequency;
        temp->left = l;
        temp->right = r;
        temp->c = min(l->c, r->c);

        pq.push(temp);
    }
    Node *root = pq.top();

    map<char, string> codes;

    auto dfs = [&](auto &&dfs, Node *n, string &code) -> void
    {
        // cout << n->frequency << ' ' << n->c << ' ' << code << '\n';
        if (!n->left && !n->right)
        {
            // Leaf Node
            if (code == "")
                code = "0";
            codes[n->c] = code;
        }
        else
        {
            if (n->left)
            {
                // Add 0
                code += '0';
                dfs(dfs, n->left, code);
                code.pop_back();
            }
            if (n->right)
            {
                // Add 1
                code += '1';
                dfs(dfs, n->right, code);
                code.pop_back();
            }
        }
    };

    string code;
    dfs(dfs, root, code);

    string compressedString = "";
    for (char c : text)
    {
        compressedString += codes[c];
    }

    for (auto [k, v] : codes)
    {
        cout << k << ' ' << v << '\n';
    }
    return compressedString;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string text = "AABACDACA";
    // string text = "ABCD";

    cout << huffmanCoding(text) << endl;
}