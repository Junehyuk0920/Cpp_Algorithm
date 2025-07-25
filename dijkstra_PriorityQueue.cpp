#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<int> parent;

void printPath(int node)
{
    if (parent[node] == -1)
    {
        cout << node;
        return;
    }
    printPath(parent[node]);
    cout << " -> " << node;
}

void dijkstra(int start)
{
    dist.assign(N + 1, INF);
    parent.assign(N + 1, -1);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // {distance, node}
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int currDist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < currDist) continue;

        for (auto& next : graph[curr])
        {
            int nextNode = next.first;
            int nextDist = next.second;

            if (dist[nextNode] > dist[curr] + nextDist)
            {
                dist[nextNode] = dist[curr] + nextDist;
                parent[nextNode] = curr;
                pq.push({ dist[nextNode], nextNode });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int st, ed, w;
        cin >> st >> ed >> w;
        graph[st].push_back({ ed, w });
        graph[ed].push_back({ st, w });  // for undirected graph
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start);
    printPath(end);
    cout << '\n';

    return 0;
}
