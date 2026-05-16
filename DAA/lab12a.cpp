#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[100];

int find(int i) {
    if(parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unite(int x, int y) {
    parent[x] = y;
}

int main() {
    Edge edges[] = {{0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}};
    int n = 4, e = 5;

    for(int i = 0; i < n; i++) parent[i] = i;

    sort(edges, edges + e, cmp);

    for(int i = 0; i < e; i++) {
        int x = find(edges[i].u);
        int y = find(edges[i].v);

        if(x != y) {
            cout << edges[i].u << "-" << edges[i].v << " : " << edges[i].w << endl;
            unite(x, y);
        }
    }
}