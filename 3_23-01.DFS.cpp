#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


Visit 1-> 2 -> Visit 2 -> 1 -> 3 -> Visit: 3 -> 1 -> 4 -> Visit: 4-> 1 ->3 -> 5 -> Visit:5 -> 3 -> 4

// Example Graph
// {{2,3,4}, {1}, {1,4,5}, {1,3,5} , {3,4}}
// start에 시작 vertex, check array는 방문정보 저장
void DFS(int start, vector<int> graph[], bool check[])
{
	check[start] = true;
	printf("Visit: %d -> ", start);

	for (int i = 0; i < graph[start].size(); ++i)
	{
		int next = graph[start][i];
		printf("%d -> ", next);

		if(!check[next])
			DFS(next, graph, check);
	}

}

int main()
{
	int n, m, start;
	cin >> n >> m >> start;

	vector<int> graph[n+1]; // vertex 이름 0 제외
	bool check[n+1]; // 0 제외
	fill(check, check+n+1, false); // [check, check+n+1)

	// edge 수 만큼 순회
	for (int i = 0; i < m; ++i)
	{
		int u,v;

		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}


	for(int i=1; i<=n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(start, graph, check);
	printf("\n");

	return 0;
}