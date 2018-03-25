#include <iostream>
#include <stdio.h>
#include <limits.h> // INT_MAX

const int V = 5;

int minDistance(int dist[V], bool sptSet[V])
{

}


int main()
{
    // 다익스트라를 이용할 그래프
    int graph[V][V] = 
    { 
        { 0, 3, 6, 8, 7 },
        { 3, 0, 2, 4, 8 },
        { 6, 2, 0, 5, 5 },
        { 8, 4, 5, 0, 2 },
        { 7, 8, 5, 2, 0 },
    };
 
    // dijkstra(최단 거리를 구하고자 하는 그래프, 시작 하고자 하는 정점);
    dijkstra(graph, 0);
 
    return 0;
}
 


출처: http://www.crocus.co.kr/533?category=209527 [Crocus]