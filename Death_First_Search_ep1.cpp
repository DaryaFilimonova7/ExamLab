#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;


void find_closest_gate(int e, vector<vector<int>> paths)
{
    int index = 0; // индекс пути к ближайшему гейту
    int min = paths[0].size();
    for (int j = 0; j < e; j++) 
    {
        if (paths[j].size() < min) { min = paths[j].size(); index = j; }
    }
    // блокируем ребро от текущего положения вируса до следующего в сторону короткого пути
    cout << paths[index][0] << " " << paths[index][1] << endl;
}


int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();

    vector<int> adj[n]; // список смежности вершин графа

    for (int i = 0; i < l; i++) 
    {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<int> gateway(e);   // контейнер для гейтов
    for (int i = 0; i < e; i++) 
    {
        int ei;  //the index of a gateway node
        cin >> ei; cin.ignore();
        gateway[i] = ei;
    }


    // game loop
    while (1) 
    {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        vector<vector<int>> paths;

        
        // вызов ф-ии, просчитывающей кратчайший путь до каждого из гейтов на текущее положение вируса
        for (int i = 0; i < e; i++) 
        {
            int visited[n] ={0};
            int distance[n];
            int parent[n];
            visited[si] =1;
            distance[si] =0;
            parent[si]= -1;
            queue<int> q;
            q.push(si);

            while (!q.empty())
            {
                int v = q.front();
                q.pop();

                for(int u: adj[v]) 
                {
                    if (!visited[u]) 
                    {
                        visited[u] =1;
                        q.push(u);
                        distance[u] = distance[v]+1;  // coming from v to u
                        parent[u] = v;
                    }
                }
            }

            // path to destination
            int x = gateway[i];
            vector<int> path;
            while (x != -1) 
            {
                path.push_back(x);
                x = parent[x];
            }
            reverse(path.begin(), path.end());
            paths.push_back(path);
        }

        
        //  определяем ближайший гейт и блокируем путь
        find_closest_gate(e, paths);

    }

}
