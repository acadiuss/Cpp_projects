#include <iostream>
#include <queue>
using namespace std;

struct edge {
    int s, t;
};

class Graph {
private:
    int** adjMatrix;
    int n; // liczba węzłów
    bool directed; // true - graf skierowany, false - graf nieskierowany

    void dfs(int s, bool* visited) {
        visited[s] = true;
        cout << s << " ";

        for (int i = 0; i < n; i++) {
            if (adjMatrix[s][i] != 0 && !visited[i]) {
                dfs(i, visited);
            }
        }
    }

public:
    Graph(int n, int m, edge edges[], bool directed) {
        this->n = n;
        this->directed = directed;
        adjMatrix = new int*[n];

        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n]{0};
        }

        for (int i = 0; i < m; i++) {
            int s = edges[i].s;
            int t = edges[i].t;
            adjMatrix[s][t] = 1;

            if (!directed) {
                adjMatrix[t][s] = 1;
            }
        }
    }

    void bfs(int s) {
        bool* visited = new bool[n]{false};
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < n; i++) {
                if (adjMatrix[v][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;

        delete[] visited;
    }

    void dfs(int s) {
        bool* visited = new bool[n]{false};
        dfs(s, visited);
        cout << endl;
        delete[] visited;
    }

    friend ostream& operator<<(ostream& out, const Graph& g) {
        for (int i = 0; i < g.n; i++) {
            for (int j = 0; j < g.n; j++) {
                out << g.adjMatrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    ~Graph() {
        for (int i = 0; i < n; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    int n = 6, m = 15;
    edge directedGraph[] = {{0, 4}, {0, 5}, {1, 0}, {1, 2}, {1, 4}, {2, 1}, {2, 3}, {2, 4}, {3, 2}, {3, 5}, {4, 0}, {4, 1}, {4, 3}, {5, 3}, {5, 4}};
    Graph g(n, m, directedGraph, true);
    cout << "Graf w postaci macierzy sąsiedztwa:" << endl;
    cout << g;
    cout << "Przeszukiwanie BFS z wezła 0:" << endl;
    g.bfs(0);
    cout << "Przeszukiwanie DFS z wezła 0:" << endl;
    g.dfs(0);

    return 0;
}








































/*polecenie{
  Zadanie 1:
Dla grafu (skierowanego lub nieskierowanego) reprezentowanego w postaci macierzy sąsiedztwa proszę zaimplementować wskazane algorytmy przeszukiwania grafu. Algorytmy powinien wyświetlać węzły w kolejności odwiedzenia. Proszę przetestować poprawność działania algorytmów.

//Szablon rozwiązania:
struct edge{
    int s;
    int t;
};
class Graph{
    private:
        int** adjMatrix;
        int n;                              //liczba węzłów
        bool directed;              //true - graf skierowany, false - graf nieskierowany
       void dfs(int s, int* visited);    //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
    public:
        Graph(int n, int m, edge edges[], bool directed);    //tworzy graf w oparciu o pdaną listę krawędzi
    Graph(){
            this->n = 6;
            this->directed = directed;
            adjMatrix = new int*[n];
    
            for(int i=0; i< n; i++)
                adjMatrix[i]=new int[n]{0};
               
            adjMatrix[0][4]=1;
            adjMatrix[0][5]=1;
            adjMatrix[1][0]=1;
            adjMatrix[1][2]=1;
            adjMatrix[1][4]=1;
            adjMatrix[2][1]=1;
            adjMatrix[2][3]=1;
            adjMatrix[2][4]=1;
            adjMatrix[3][2]=1;
            adjMatrix[3][5]=1;
            adjMatrix[4][0]=1;
            adjMatrix[4][1]=1;
            adjMatrix[4][3]=1;
            adjMatrix[5][3]=1;
            adjMatrix[5][4]=1;
    }
    Graph(int n, int m, bool directed);    //tworzy losowy graf o n węzłach i m krawędziach, skierowany lub nieskierowany
        void bfs(int s);                //wykonuje przeszukiwanie i wyświetla węzły w porządku odwiedzenia
        void dfs(int s);                //metoda pomocnicza dla dfs - tworzy tabelę visited i wywołuję metodę prywatną dfs
        friend ostream& operator<<(ostream& out, Graph& g);  //wyświetla graf
        ~Graph();
};

w main():
    int n = 6, m =15;
    edge directedGraph[]={{0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4}};  //przykładowy graf
    Graph g(n,m,directedGraph,true);       // lub Graph g; jeśli używany jest konstruktor domyślny z dedykowanym grafem
    cout<<g;
    g.bfs(0);
    g.dfs(0);
// testowanie np. dla różnych węzłów źródłowych, dla innych grafów



POPRZEDNIA AKTYWNOŚĆ
zestaw zadań: znajdywanie wzorca w tekście
  
}*/