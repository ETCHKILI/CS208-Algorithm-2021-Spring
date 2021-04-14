#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long food = 0;
    long long cost = 0;
    long long income = 0;
    long long pure = 0;

    vector< pair<Node*, int> > cons;
    bool visited = false;
};

bool compare(pair<Node*, int> &a, pair<Node*, int> &b) {
    Node &x= *a.first;
    Node &y= *b.first;
    if (x.pure >= 0) {
        if (y.pure >= 0) {
            return x.cost < y.cost;
        }
    } else {
        if (y.pure < 0) {
            return x.income > y.income;
        }
    }
    return x.pure > y.pure;
}

void dfs(Node& root) {
    root.visited = true;
    root.income = root.food - root.cost;
    int n = root.cons.size();
    for (int i = 0; i < n; ++i) {
        if (!root.cons[i].first->visited) {
            root.cons[i].first->cost = root.cons[i].second;
            dfs(*root.cons[i].first);

            root.pure += root.cons[i].first->pure;
        }
    }

    sort(std::begin(root.cons), std::end(root.cons), compare);
    root.pure += root.food - 2 * root.cost;
}

void cal1(long long &hp, long long &time, long long ob) {
    if (hp >= ob) {
        hp -= ob;
    } else {
        time += ob - hp;
        hp = 0;
    }
}

void dfs2(Node& root, long long &hp, long long &time) {
    root.visited = true;
    hp += root.food;
    int n = root.cons.size();
    for (int i = 0; i < n; ++i) {
        if (!root.cons[i].first->visited) {
            cal1(hp, time, root.cons[i].second);
            dfs2(*root.cons[i].first, hp, time);
            cal1(hp, time, root.cons[i].second);
        }
    }
}


int main() {
    int n;
    cin >> n;

    Node nodes[n];
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].food;
    }

    int u, v, w;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        nodes[u - 1].cons.emplace_back(&nodes[v - 1], w);
        nodes[v - 1].cons.emplace_back(&nodes[u - 1], w);
    }

    dfs(nodes[0]);

    for (int i = 0; i < n; ++i) {
        nodes[i].visited = false;
    }

    long long hp = 0;
    long long time = 0;
    dfs2(nodes[0], hp, time);
    cout << time <<'\n';
}