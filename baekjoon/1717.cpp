// union find를 소개하는 문제

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(const int& size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(const int& k) {
        if (parent[k] != k) {
            parent[k] = find(parent[k]);
        }
        return parent[k];
    }

    void unionSets(const int &a, const int &b) {
        int root_a = find(a), root_b = find(b);

        if (root_a != root_b) {
            if (rank[root_a] > rank[root_b]) {
                parent[root_b] = root_a;
            } else if (rank[root_a] < rank[root_b]) {
                parent[root_a] = root_b;
            } else {
                parent[root_b] = root_a;
                rank[root_a]++;
            }
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m, cmd, a, b;
    cin >> n >> m;

    UnionFind uf(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            uf.unionSets(a, b);
        } else {
            cout << ((uf.find(a) == uf.find(b)) ? "yes\n" : "no\n");
        }
    }
    
    return 0;
}
