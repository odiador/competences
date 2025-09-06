#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;         // Número de nodos en la componente
    vector<long long> edges;  // Número de amistades (aristas) en la componente

    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        edges.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    
    // Encuentra el representante (raíz) del nodo "a" con compresión de caminos
    int find(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    
    // Une los conjuntos que contienen a "a" y "b", actualizando tamaño y contador de aristas
    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            // Ya están en la misma componente: se añade esta amistad extra
            edges[a]++;
            return;
        }
        // Unión por tamaño: unimos el de menor tamaño al de mayor tamaño
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        // Las aristas totales serán la suma de las aristas de ambas componentes más la nueva amistad
        edges[a] += edges[b] + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    
    // Procesamos cada amistad y unimos los conjuntos correspondientes
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unionSet(a, b);
    }
    
    // Para cada componente (representada por su raíz), calculamos el número de nuevas amistades
    // La fórmula es: máximo de amistades posibles - amistades actuales.
    // Si en una componente hay k estudiantes, máximo amistades = k*(k-1)/2.
    long long ans = 0;
    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        int r = dsu.find(i);
        if (!visited[r]) {
            visited[r] = true;
            long long k = dsu.size[r]; // Número de nodos en la componente
            long long currentEdges = dsu.edges[r];
            // Se suman las nuevas amistades para esta componente
            ans += (k * (k - 1LL) / 2) - currentEdges;
        }
    }
    
    cout << ans << "\n";
    return 0;
}