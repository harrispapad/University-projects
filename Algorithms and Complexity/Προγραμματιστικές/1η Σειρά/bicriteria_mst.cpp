#include <iostream>  
#include <vector>  
#include <algorithm>  

//used https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
//for help with the implementation of the graph

  
using namespace std;  
 
int N, M;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

struct Edge  
{  
	int u, v, p, w;  
    	bool operator<(const Edge& other) const
	{
    		return p >= other.p; 
	}
};  
  
class DSU   
{  
private:  
	vector<int> parent, rank;  
  
public:  
    	DSU(int n)  
    	{  
        	parent.resize(n);  
        	rank.resize(n, 0);
		for(int i = 0; i < n; i++) {
			parent[i] = i;
		}	
    	}  
  
    	int find(int x)  
    	{  
        	if(parent[x] != x)   
        		parent[x] = find(parent[x]);  
		return parent[x];
	}  
 
	
    	bool unite(int x, int y) {
        	int rootX = find(x);
        	int rootY = find(y);

        	if (rootX == rootY) return false; 

        	if (rank[rootX] > rank[rootY]) {
            		parent[rootY] = rootX;
        	} else if (rank[rootX] < rank[rootY]) {
            		parent[rootX] = rootY;
        	} else {
            		parent[rootY] = rootX;
            	rank[rootX]++;
        	}
        
		return true;
    	}

};  
 
void kruskal(int n, vector<Edge>& edges)
{
	sort(edges.begin(), edges.end());
	
	DSU ds(n);
	
	int profit = 0;
	int weight = 0;

	for(const Edge& e : edges) {
		if(ds.unite(e.u, e.v)) {
			profit += e.p;
			weight++;

			if(weight == n - 1) break;
		}
	}

	cout << (profit / gcd(profit, N - 1)) << " " << (N - 1)/gcd(profit, N - 1) << endl;
}


int main()  
{  
    	cin >> N >> M;  
    	
      	vector<Edge> edges(M);	
  
    	for (int i = 0; i < M; i++) {  
       	        cin >> edges[i].u >> edges[i].v >> edges[i].p >> edges[i].w;
        	edges[i].u--;
        	edges[i].v--;
	}  
  
    	kruskal(N, edges);  
  
return 0;  
}  

