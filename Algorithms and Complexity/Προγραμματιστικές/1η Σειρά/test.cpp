#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

struct Edge
{
    int u, v, p, w;
    bool operator<(const Edge& other) const
    {
        return p > other.p;
    }
};

class DSU
{
private:
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    int find(int x)
    {
        if (parent[x] == -1)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};

class Graph
{
private:
    vector<Edge> edges;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v, int p, int w)
    {
        edges.push_back({u, v, p, w});
    }

    void kruskal()
    {
        sort(edges.begin(), edges.end());

        DSU s(V);
        int profit = 0;
        int weight = 0;

        for (auto edge : edges) {
            if (s.find(edge.u) != s.find(edge.v)) {
                s.unite(edge.u, edge.v);
                profit += edge.p;
                weight++;
            }
        }

        cout << (profit / gcd(profit, weight)) << " " << (weight / gcd(profit, weight)) << endl;
    }
};

int main()
{
    ifstream infile("input.txt"); // Open the input file

    if (!infile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int N, M;
    infile >> N >> M;
    Graph g(N);

    for (int i = 0; i < M; i++) {
        int u, v, p, w;
        infile >> u >> v >> p >> w;
        g.addEdge(u, v, p, w);
    }

    infile.close(); // Close the input file

    g.kruskal();

    return 0;
}

