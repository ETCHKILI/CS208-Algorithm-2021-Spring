#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    long long ans = LLONG_MAX;
    bool out = false;
    int red;
    int green;
    vector<pair<Node*, int>> cons;
};

class Compare {
public:
    bool operator() (Node* a, Node* b) const{
        return a->ans >= b->ans;
    }
};

long long cal(Node &a, Node &b, int weight) {
    long long time = a.ans + weight;
    int cycle = b.red + b.green;
    if (time % cycle - b.red < 0 ) {
        return b.red - time % cycle;
    }
    return 0;
}


int main() {
    int n, m;
    cin >> n >> m;
    Node nodes[n];
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < m; ++i) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        nodes[n1 - 1].cons.emplace_back(&nodes[n2 - 1], w);
    }

    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].red >> nodes[i].green;
    }

    nodes[0].ans = 0;
    pq.push(&nodes[0]);
    while (!pq.empty()) {
        Node &tmp = *pq.top();
        pq.pop();

        if (tmp.out) {
            continue;
        }

        tmp.out = true;
        for (auto &item : tmp.cons) {
            if (item.first->out || tmp.ans + item.second + cal(tmp, *(item.first), item.second) >= item.first->ans) {
                continue;
            }
            item.first->ans = tmp.ans + item.second + cal(tmp, *(item.first), item.second);
            pq.push(item.first);
        }
    }

    cout << nodes[n - 1].ans;
}