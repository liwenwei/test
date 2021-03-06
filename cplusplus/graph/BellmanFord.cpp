#include <queue>
#include <iostream>

using namespace std;

const int N = 7;

void Print(const int* path, int N)
{
    for (int i = 0; i < N; i++)
        cout << i << ":\t" << path[i] << '\n';
    cout << endl;
}

//邻接矩阵为graph，结点数目为N，计算start到其他所有点的最短路径
void BellmanFord(int graph[N][N], int N, int* path, int start)
{
    int i, j, k;
    for (i = 0; i < N; i++)
        path[i] = 1000000;

    path[start] = 0;
    for (i = 0; i < N; i++)
    {
        //对于每条边
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            {
                if (graph[j][k] != 0)	//说明有边
                {
                    path[k] = min(path[k], path[j] + graph[j][k]);
                }
            }
        }
    }
}

void BellmanFord1(int graph[N][N], const int* vertex, int N, int* gas, int start)
{
    int i, j, k;
    for (i = 0; i < N; i++)
        gas[i] = 0;	//没有汽油
    gas[start] = vertex[start];

    for (i = 0; i < N; i++)
    {
        //对于每条边
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < N; k++)
            {
                if (graph[j][k] != 0)	//说明有边
                {
                    if (gas[j] >= graph[j][k])	//保证能够有足够多的汽油到达k点
                        gas[k] = max(gas[k], gas[j] - graph[j][k] + vertex[k]);
                }
            }
        }
    }
}

void Calc(int graph[N][N], const int* vertex, int N, int start, int* path, int size, int& m)
{
    int pre = 0;
    for (int i = 0; i < N; i++)
    {
        if (graph[start][i] != 0)
        {
            int curEdge = graph[start][i];
            graph[start][i] = 0;
            pre = 0;
            Calc(graph, vertex, N, i, path, pre);
            m = pre - curEdge + vertex[i];
            graph[start][i] = curEdge;
        }
    }
}

int main()
{
    int graph[N][N] = { 0 };
    graph[0][1] = 4;
    graph[0][2] = 3;
    graph[0][3] = 5;
    graph[1][0] = 4;
    graph[1][2] = 2;
    graph[1][4] = 3;
    graph[2][0] = 3;
    graph[2][1] = 2;
    graph[2][4] = 4;
    graph[3][0] = 5;
    graph[3][4] = 3;
    graph[3][5] = 2;
    graph[4][1] = 3;
    graph[4][2] = 4;
    graph[4][3] = 3;
    graph[4][5] = 5;
    graph[4][6] = 6;
    graph[5][3] = 2;
    graph[5][4] = 5;
    graph[5][6] = 7;
    graph[6][4] = 6;
    graph[6][5] = 7;
    int vertex[] = { 7, 5, 4, 3, 4, 7, 0 };

    int start = 0;	//起点
    int path[N];	//最短路的值
    //BellmanFord1(graph, vertex, N, path, start);
    //SPFA1(graph, vertex, N, path, start);	//Shortest Path Faster Algorithm
    Calc(graph, vertex, N, start, path, 0);
    Print(path, N);
    return 0;
}

