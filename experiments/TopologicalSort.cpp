// A C++ program to print topological 
// sorting of a DAG 
#include<iostream> 
#include<bits/stdc++.h> 
#include <list> 
#include <stack> 
using namespace std; 

// Class to represent a graph 
class Graph 
{ 
// No. of vertices' 
	int V;	 

	// Pointer to an array containing adjacency listsList 
	map<string, vector<string>> adj; 

	// A function used by topologicalSort 
	void topologicalSortUtil(string v, unordered_set<string> &visited, queue<string> &q); 
public: 
// Constructor 
	//Graph(int V); 

	// function to add an edge to graph 
	void addEdge(string &v, vector<string> &w); 

	// prints a Topological Sort of 
// the complete graph 
	void topologicalSort(); 
}; 

/*Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new vector<>; 
} 
*/

void Graph::addEdge(string &v, vector<string> &w) 
{ 
// Add w to v’s list.
	adj.insert({v,w}); 
} 

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil( 
string v, unordered_set<string> &visited, 
								queue<string> &q) 
{ 
	// Mark the current node as visited. 
	visited.insert(v); 

	// Recur for all the vertices 
// adjacent to this vertex 
	
	if(adj.count(v))
	{
	    vector<string> temp= adj[v];
	    for(string st: temp)
	    {
	        if(!visited.count(st))
	            topologicalSortUtil(st, visited, q);
	    }
	}

	// Push current vertex to stack 
// which stores result 
	q.push(v); 
} 

// The function to do Topological Sort. 
// It uses recursive topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
	queue<string> q; 

	// Mark all the vertices as not visited 
	unordered_set<string> visited; 

	// Call the recursive helper function 
// to store Topological 
	// Sort starting from all 
// vertices one by one 
    map<string, vector<string>>::iterator i;
    for(i = adj.begin(); i != adj.end(); ++i)
    {
        if(!visited.count(i->first))
            topologicalSortUtil(i->first, visited, q);
    }
	
	
	// Print contents of stack 
	while (!q.empty()) 
	{ 
	    string cur = q.front();
	    q.pop();
		cout << cur << ":" << endl; 
		vector<string> tp = adj[cur];
		cout << "\t- ";
		for(string s: tp)
		    cout << s << " ";
		cout << endl;
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g;
	string name = "Arya";
	vector<string> tt{"dad","mom","kiran","prapulla"};
	g.addEdge(name, tt);
	name = "prapulla";
	tt={"kiran","Athe","mava"}; 
	g.addEdge(name, tt);
	name = "kiran";
	tt.clear();
	g.addEdge(name, tt);
	name = "dad";
	tt = {"kiran","kishor"};
	g.addEdge(name, tt);
	name = "mom";
	tt = {"dad","kishor","kiran"};
	g.addEdge(name, tt);
	name = "kishor";
	tt = {"kiran"};
	g.addEdge(name, tt);
	name = "priya";
	tt = {"dad","mom","Athe","mava","kishor"};
	g.addEdge(name, tt);

	cout << "Following is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
} 

