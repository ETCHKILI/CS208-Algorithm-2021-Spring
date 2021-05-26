//
// Created by GuoYubin on 2021/4/27.
//
#include <iostream>
#include <vector>
#include <queue>


using namespace std;


struct Node {
    int freq = 0;
    char key = ' ';
    Node *left = nullptr;
    Node *right = nullptr;
};

class Compare {
public:
    bool operator() (Node* a, Node* b) const{
        return a->freq > b->freq;
    }
};

void Search(Node* root, int *size, int level) {
    if (root == nullptr) {
        return;
    }
    if (root->key != ' ') {
        size[root->key - 'a'] = level;
    }

    Search(root->left, size, level + 1);
    Search(root->right, size, level + 1);
}


int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        int freq[26]{0};
        int code_size[26]{0};
        priority_queue<Node*, vector<Node*>, Compare> nodes;

        cin >> s;
        for (auto item : s) {
            freq[item - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) {
                Node* tmp = new Node{freq[i], char ('a' + i)};
                nodes.push(tmp);
            }
        }

        while (nodes.size() > 1) {
            Node* a = nodes.top();
            nodes.pop();
            Node* b = nodes.top();
            nodes.pop();

            Node* c = new Node{a->freq + b->freq};
            c->left = a;
            c->right = b;
            nodes.push(c);
        }

        Node *root = nodes.top();
        Search(root, code_size, 0);

        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            sum += code_size[i] * freq[i];
        }
        cout << sum <<'\n';
    }
}