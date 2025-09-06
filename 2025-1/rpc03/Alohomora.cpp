#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        // Consideramos que la interconexión es bidireccional
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Verificamos la conectividad del grafo.
    // Buscamos un nodo de partida (uno que tenga alguna conexión)
    int start = -1;
    for (int i = 1; i <= n; i++){
        if (!adj[i].empty()){
            start = i;
            break;
        }
    }
    
    if(start == -1){
        // Si ningún eslabón tiene conexión (caso n > 1), no es posible formar el ciclo.
        cout << "no\n";
        return 0;
    }
    
    vector<bool> visited(n + 1, false);
    // Usamos DFS para recorrer el grafo.
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]){
            if(!visited[v])
                dfs(v);
        }
    };
    
    dfs(start);
    
    // Comprobamos que todos los eslabones estén conectados.
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cout << "no\n";
            return 0;
        }
    }
    
    // Para poder formar un ciclo (donde cada eslabón termina conectado a 2 otros),
    // se requiere que el número de interconexiones sea exactamente n (ciclo ya formado)
    // o n - 1 (árbol, que se arregla abriendo un eslabón adecuado).
    if(m == n - 1 || m == n)
        cout << "yes\n";
    else
        cout << "no\n";
    
    return 0;
}
