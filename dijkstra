#include <iostream>

using namespace std;

const int INF = 1e9;
const int MAX = 100;

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];

void printPath(int node, int parent[])
{
	if (parent[node] == -1)  // reached start node
	{
		cout << node;
		return;
	}
	printPath(parent[node], parent);  // parent node
	cout << " -> " << node;           // current node
}

int main()
{
	int parent[MAX];
	int n, m; cin >> n >> m; //vertex : n, edge : m

	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		visited[i] = false;
		parent[i] = -1;
		for (int j = 0; j < n; j++) graph[i][j] = INF;
	}

	for (int i = 0; i < m; i++)
	{
		int st, ed, w; cin >> st >> ed >> w;
		graph[st][ed] = w;
	}

	int start, end; cin >> start >> end;
	dist[start] = 0;

	for (int i = 0; i < n; i++)
	{
		int minDist = INF;
		int st = -1;

		for (int ed = 0; ed < n; ed++)
		{
			if (!visited[ed] && dist[ed] < minDist)
			{
				minDist = dist[ed];
				st = ed;
			}
		}

		if (st == -1) break;
		visited[st] = true;

		for (int ed = 0; ed < n; ed++)
		{
			if (!visited[ed] && graph[st][ed] != INF)
			{
				if (dist[ed] > dist[st] + graph[st][ed]) //find shorter route
				{
					dist[ed] = dist[st] + graph[st][ed];
					parent[ed] = st;
				}
			}
		}
	}

	printPath(end, parent);
	cout << endl;

	return 0;
}
