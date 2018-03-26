#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;


// directed graph
class Graph
{
private:
	int V;
	list<iPair> *adj;

public:
	Graph(int V);

	void AddEdge(int u, int v, int w);

	void ShortestPath(int s);

};


Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::AddEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}
	
void Graph::ShortestPath(int s)
{
	// priority queue
	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

	// saving shortest path
	vector<int> dist(V, INF);

	pq.push(make_pair(0, s));

	dist[s] = 0;


	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();


		list<iPair>::iterator iter;
		for (iter = adj[u].begin(); iter!= adj[u].end(); ++iter)
		{
			int v = (*iter).first;
			int weight = (*iter).second;

			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}

		}

	}
	    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}


// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.AddEdge(0, 1, 4);
    g.AddEdge(0, 7, 8);
    g.AddEdge(1, 2, 8);
    g.AddEdge(1, 7, 11);
    g.AddEdge(2, 3, 7);
    g.AddEdge(2, 8, 2);
    g.AddEdge(2, 5, 4);
    g.AddEdge(3, 4, 9);
    g.AddEdge(3, 5, 14);
    g.AddEdge(4, 5, 10);
    g.AddEdge(5, 6, 2);
    g.AddEdge(6, 7, 1);
    g.AddEdge(6, 8, 6);
    g.AddEdge(7, 8, 7);
 
    g.ShortestPath(0);
 
    return 0;
}