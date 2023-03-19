#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Структура для хранения ребра 
struct Edge {
    int source, destination;
    bool is_gateway;
};

//ищет кратчайший путь от текущего положения вируса до гейта (не проверено, не доделано)
// источник -- https://algorithmica.org/tg/bfs

vector<int> BFS(int n, int si, int ei) {
    vector<int> distance(n,n);
     vector<int> p(n, -1); // : у стартовой вершины предок — некоторая несуществующая вершина
    distance[si] = 0;
    queue<int> q;
    q.push(si);
    // Восстановление пути делается с конца. 
    // Мы знаем последнюю вершину пути — это ei
    // Далее, мы сводим задачу к меньшей, переходя к нахождению пути из ei в p(si)
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        // adjacent — список смежности
        for (int b : adjacent[v]) {
            if (distance[b] > distance[a] + 1) {
                distance[b] = distance[a] + 1;
                q.push(b);
            }
        }
    }
    // если пути не существует, возвращаем пустой vector
    if (distance[ei] == n) {
        return {};
    }
    vector<int> path;
    while (ei != -1) {
        path.push_back(ei);
        ei = p[ei];
    }
    
    // путь был рассмотрен в обратном порядке, поэтому его нужно перевернуть
    reverse(path.begin(), path.end());
    return path;

}



int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();

    vector<Edge> edges;

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        // cin >> n1 >> n2; cin.ignore(); // способ ввода, который дан изначально
        
        cin >> edges[i].source >> edges[i].destination; cin.ignore();
    }
    
    vector<int> gateway(e);
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gateway[i] = ei;
    }
    
    
    // помечаем ссылки, которые ведут к гейту
    for (int i = 0; i < n; i++) {
        for (j = 0; j < e; j++) {
                eges[i].is_gateway = true;}
            else {
                eges[i].is_gateway = false;}
        }
    }
   

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        
        
        // вызов ф-ии, пррсчитывающей кратчайший путь на каждое движение вируса
        BFS(n,si,ei);

        // далее делаем так, что блокируется путь от текущей точки в сторону кратчайшего пути
        // и удаляем этот путь из всех доступных нам, чтоб функция его больше не учитывала
        
        
        /*
            hardcode for test 2 
            // cout << "0 2" << endl;
            // cout << "1 3" << endl;

        */
        
    }
    
}
