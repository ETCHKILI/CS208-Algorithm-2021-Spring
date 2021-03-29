#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int index;
    int p_num;
    vector<Node*> sons;
};

class Compare {
public:

    bool operator () (Node* &a, Node* &b) const
    {
        return a->index > b->index;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    Node nodes[n];
    for (int i = 0; i < n; ++i) {
        nodes[i] = {i + 1, 0, };
    }

    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        nodes[x - 1].sons.push_back(&nodes[y - 1]);
        nodes[y - 1].p_num++;
    }

    priority_queue<Node*, vector<Node*>, Compare> first;
    priority_queue<Node*, vector<Node*>, Compare> second;

    priority_queue<Node*, vector<Node*>, Compare> *q = &first;
    priority_queue<Node*, vector<Node*>, Compare> *q2 = &second;
    priority_queue<Node*, vector<Node*>, Compare> *tmp;


    vector<Node*> result;
    for (int i = 0; i < n; ++i) {
        if (nodes[i].p_num == 0) {
            q->push(&nodes[i]);
        }
    }


    while (!q->empty()) {
        while (!q->empty()) {
            for (auto & son : (q->top())->sons) {
                son->p_num --;
                if (son->p_num == 0) {
                    q2->push(son);
                }
            }
            result.push_back(q->top());
            q->pop();
        }

        tmp = q;
        q = q2;
        q2 = tmp;
    }

    if (result.size() != n){
        cout << "impossible\n";
    } else {
        for (int i = 0; i < n - 1; ++i) {
            cout << result[i]->index << " ";
        }
        cout << result[n - 1]->index << '\n';
    }
}