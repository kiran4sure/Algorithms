#include<bits/stdc++.h>
#include <vector>

using namespace std;


class Graph
{
    vector<int> *adj;
    int N;

public:
    Graph(int n)
    :N(n)
    {
        adj = new vector<int>[N];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bridgeUtil(int node, int parent, vector<bool> &visited, vector<int> &low, vector<int> &disc, int &time)
    {

        low[node] = disc[node] = time++;

        for(int a: adj[node])
        {
            if(a == parent) continue;

            if(visited[node] == false)
            {
                visited[node] = true;
                bridgeUtil(a, node, visited, low, disc, time);

                low[node] = min(low[node], low[a]);

                if(disc[node] < low[a])
                {
                    cout << a << " " << node << endl;
                }
            }
            else
            {
                low[node] = min(low[node], disc[a]);
            }
        }
    }

    void bridge()
    {
        vector<bool> visited(N,false);
        vector<int> low(N, -1);
        vector<int> disc(N, -1);

        int time = 0;
        int parent = -1;

        for(int i=0; i<N; i++)
        {
            if(visited[i] == false)
            {
                bridgeUtil(i,parent, visited, low, disc, time);
            }
        }

    }

};

int main()
{
    // Create graphs given in above diagrams
	cout << "\nBridges in first graph \n";
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.bridge();

	cout << "\nBridges in second graph \n";
	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.bridge();

	cout << "\nBridges in third graph \n";
	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(1, 2);
	g3.addEdge(2, 0);
	g3.addEdge(1, 3);
	g3.addEdge(1, 4);
	g3.addEdge(1, 6);
	g3.addEdge(3, 5);
	g3.addEdge(4, 5);
	g3.bridge();

	return 0;
}