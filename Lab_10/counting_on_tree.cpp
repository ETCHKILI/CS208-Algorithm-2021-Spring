//
// Created by 郭宇宾 on 2021/5/12.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int id;
    vector<pair<TreeNode*, int>> cons;
};

void dfs(TreeNode &start, TreeNode *up, TreeNode &ts, int q, bool *vis, unordered_map<TreeNode*, long long> &trees) {
    vis[ts.id] = true;
    trees[&start] += 1;
    for (auto &item : ts.cons) {
        if (item.first == up) {
            continue;
        }
        if (vis[item.first->id]) {
            continue;
        }
        if (item.second > q) {
            continue;
        }

        dfs(start, &ts, *item.first, q, vis, trees);
    }
}

int main() {
    int n, m, u, v, w;
    cin >> n >> m;

    auto nodes = new TreeNode[n];
    for (int i = 0; i < n; ++i) {
        nodes[i].id = i;
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        nodes[u - 1].cons.emplace_back(&nodes[v - 1], w);
        nodes[v - 1].cons.emplace_back(&nodes[u - 1], w);
    }

    for (int i = 0; i < m; ++i) {
        int q;
        long long res = 0;
        cin  >> q;
        auto vis = new bool [n] {false};
        unordered_map<TreeNode*, long long> trees;

        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                trees.emplace(&nodes[j], 0);
                dfs(nodes[j], nullptr, nodes[j], q, vis, trees);
            }
        }

        for (auto item : trees) {
            res += item.second * (item.second - 1) / 2;
        }

        cout << res << ' ';
        delete [] vis;
    }


    return 0;
}
