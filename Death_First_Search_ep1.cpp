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
    int n; // общее количество узлов на уровне, включая шлюзы
    int l; // количество ссылок
    int e; // количество выходных шлюзов
    cin >> n >> l >> e; cin.ignore();

    vector<int> adj[n]; // список смежности вершин графа

    for (int i = 0; i < l; i++) 
    {
        int n1; // N1 и N2 определяют связь между этими узлами
        int n2;
        cin >> n1 >> n2; cin.ignore();

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    vector<int> gateway(e);   // контейнер для гейтов
    for (int i = 0; i < e; i++) 
    {
        int ei;  // индекс узла шлюза
        cin >> ei; cin.ignore();
        gateway[i] = ei;
    }


    // игровой цикл
    while (1) 
    {
        int si; // Индекс узла, на котором находится агент Bobnet в этот ход
        cin >> si; cin.ignore();

        vector<vector<int>> paths;

        
        // вызов ф-ии, просчитывающей кратчайший путь до каждого из гейтов на текущее положение вируса
        for (int i = 0; i < e; i++) 
        {
            int visited[n] ={0};
            int distance[n];
            int parent[n]; // хранит предшествующие вершины
            visited[si] =1;
            distance[si] =0; // хранит дистанции
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
                        distance[u] = distance[v]+1;  // идет от v (из очереди) до u (до каждого элемента adj)
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
