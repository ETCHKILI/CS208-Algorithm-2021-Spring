#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long cost = 0;
    long long profit = 0;
    long long hp;
    vector< pair<Node*, int> > cons;
    bool visited = false;
};

bool compare(pair<Node*, int> &a, pair<Node*, int> &b) {
    if (a.first->cost == 0 && b.first->cost == 0) {
        return a.first->profit > b.first->profit;
    } else {
        return
    }

}

void dfs(Node& root) {
    root.visited = true;
    int n = root.cons.size();
    for (int i = 0; i < n; ++i) {
        if (!root.cons[i].first->visited) {
            dfs(*root.cons[i].first);
            (*root.cons[i].first).cost += root.cons[i].second;
        }
    }
    sort

}


int main() {
    int n;
    cin >> n;

    Node nodes[n];
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].hp;
    }

    int u, v, w;
    for (int i = 0; i < n; ++i) {
        cin >> u >> v >> w;
        nodes[u].cons.emplace_back(&nodes[v], w);
        nodes[v].cons.emplace_back(&nodes[u], w);
    }







}