//
// Created by GuoYubin on 2021/5/12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int *fa;
long long *sz;
long long rk = 0;

struct eg {
    eg(int u, int v, long long w) : u(u), v(v), w(w) {}
    int u;
    int v;
    long long w;
};

void init(int n) {
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void merge(int i, int j) {
    rk += sz[find(i)] * sz[find(j)];
    sz[find(i)] += sz[find(j)];
    fa[find(j)] = find(i);
}



int main() {
    int n, m, u, v, w, q;
    cin >> n >> m;

    fa = new int [n];
    sz = new long long [n];
    init(n);

    vector<eg> edges;
    vector<eg> queries;


    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        edges.emplace_back(u - 1, v - 1, w);
    }

    for (int i = 0; i < m; ++i) {
        cin >> q;
        queries.emplace_back(i, q, 0);
    }

    sort(edges.begin(), edges.end(), [](eg &a, eg &b) {return a.w < b.w;});
    sort(queries.begin(), queries.end(), [](eg &a, eg &b) {return a.v < b.v;});
//    sort(queries.begin(), queries.end(), [](pair<int, int> &a, pair<int, int> &b) {return a.second > b.second;});

    int i = 0;
    for (auto &item : queries) {
        q = item.v;
        while ((i < n - 1) && (edges[i].w <= q)) {
            merge(edges[i].u, edges[i].v);
            ++i;
        }
        item.w = rk;
    }

    sort(queries.begin(), queries.end(), [](eg &a, eg &b) {return a.u < b.u;});
    for (int j = 0; j < m; ++j) {
        cout << queries[j].w << ' ';
    }
}