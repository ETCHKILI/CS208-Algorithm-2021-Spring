#include <iostream>
#include <vector>

using namespace std;

long long result = 0;

struct Node {
    int weight = 0;
    long long sum = 0;
    long long tmp_result = 0;
    vector<Node*> cons;
    bool built = false;
    bool visited = false;
};

void build(Node *root) {
    root->built = true;
    for (auto &son : root->cons) {
        if (!son->built) {
            build(son);
            root->sum += son->sum;
            root->tmp_result += son->tmp_result;
        }
    }
    root->tmp_result += root->sum;
    root->sum += root->weight;
}

void rec(Node *root) {
    root->visited = true;
    Node *rev = nullptr;
    for (auto & son : root->cons) {
        if (son->visited) {
            rev = son;

            rev->tmp_result -= (root->tmp_result + root->sum);
            rev->sum -= root->sum;

            root->sum += rev->sum;
            root->tmp_result += rev->tmp_result + rev->sum;
        }
    }

    result = max(result, root->tmp_result);

    for (auto & son : root->cons) {
        if (!son->visited) {
            rec(son);
        }
    }

    if (rev != nullptr) {
        root->tmp_result -= rev->tmp_result + rev->sum;
        root->sum -= rev->sum;
        rev->sum += root->sum;
        rev->tmp_result += (root->tmp_result + root->sum);
    }
}

int main() {
    int n;
    cin >> n;

    Node nodes[n];

    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].weight;
    }

    int t0, t1;
    for (int i = 0; i < n - 1; ++i) {
        cin >> t0 >> t1;
        nodes[t0 - 1].cons.push_back(&nodes[t1 - 1]);
        nodes[t1 - 1].cons.push_back(&nodes[t0 - 1]);
    }

    build(&nodes[0]);

    rec(&nodes[0]);

    cout << result << '\n';
}