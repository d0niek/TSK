/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef GRAPTH_H
#define GRAPTH_H

#include <vector>
#include "../Util/Vector2f.h"
#include "../Util/Color.h"

/**
 * Szablon klasy Graph
 *
 * @param V Klasa z dodatkowymi informacjami o wierchołku, po której dziedziczy Vertex
 * @param E Klasa z dodatkowymi informacjami o krawędzi, po której dziedziczy Edge
 */
template<class V, class E>
struct Graph {
    struct Edge : public E {
        int vertex;
        int rev;

        Edge(E e, int vertex);
    };

    struct Vertex : public V, public std::vector<Edge> {
        int t;
        int s;
    };

    std::vector<Vertex> vertices;

    Graph(int vertices = 0);

    void edgeUndirected(int vertex_1, int vertex_2, E edge = E());

    /**
     * Przeszukiwanie grafu wszerz.
     *
     * Wierzchołek musi zawierać dodatkowe informacje:
     * int t - odległość wierzchołka od źródła wyszukiwania
     * int s - nr wierzchołka, z którego prowadzi znaleziona, najkrótsza trasa
     */
    void bfs(int source, int depth);

    private:
        void ResetVerticesForBfs(int source);
};

#endif // GRAPTH_H
