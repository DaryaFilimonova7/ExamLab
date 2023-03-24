#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>


using namespace std;
const int imax = std::numeric_limits<int>::max();  //imax declared as the max value for int (in C++)


void add_edge(list<int> adj_list[], int a, int b) {    //add a into the list b, and b into list a
   adj_list[a].push_back(b);
   adj_list[b].push_back(a);
}

void dfs(int n, vector<vector<int>> adjList, int si, int ei)
{
    vector<int> distance(n, imax);
    vector<int> path;
    queue<int> q; q.push(si); distance[si] = 0;

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        for (int i = 0; i < (int)adjList[curr].size(); ++i) {
            if (distance[i] == imax) {
                distance[i] = distance[curr] + 1;
                //save the parent to have the path at the end of the algo.
                path[i] = curr;
            }
        }
    }
     /* t can be anything you want */
    int t = 5;
    printPath(s, t, path); cout << endl;                                                // не понимаю эту часть - что такое t 
}                                                                                       // может быть t это ei ? типа конец пути

// только нам надо сделать не принт весь путь, а только два узла
void printPath(int s, int t, const vector<int> &path)
{
    if (t == s) {
        return;
    }
    printPath(s, path[t], path);
    cout << path[t];
}



int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();

    list<int> adj_list[n];  //create an array of lists whose size is n

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore(); 
    
        add_edge(adj_list, n1, n2);
    }
    
    vector<int> gateway(e);
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gateway[i] = ei;
    }
   

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        // вызов ф-ии, пррсчитывающей кратчайший путь до каждого из гейтов на каждое движение вируса
        for (int i = 0; i < e; i++) {
          dfs(n, adjList, si, gateway[i])
        }
        
      
        // далее делаем так, что блокируется путь от текущей точки в сторону кратчайшего пути
        // и удаляем этот путь из всех доступных нам, чтоб функция его больше не учитывала
        
        
    }
    
}
