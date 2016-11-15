/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef GRAPTH_H
#define GRAPTH_H

#include <vector>

/**
 * Szablon klasy Graph
 *
 * @param V Klasa z dodatkowymi informacjami o wierchołku, po której dziedziczy Vertex
 * @param E Klasa z dodatkowymi informacjami o krawędzi, po której dziedziczy Edge
 */
template<class V, class E>
class Graph {
    public:
        class Ed : public E {
            private:
                int vertex;

            public:
                Ed(E e, int v);

                int getVertex();

                void setVertex(int vertex);
        };

        class Ve : public V, public std::vector<Ed> {
        };

    protected:
        std::vector<Ve> vertices;

        void resetVerticesForBfs(int source);

    public:
        Graph(int vertices = 0);

        void edgeDirected(int from, int to, E edge = E());
        void edgeUndirected(int vertex_1, int vertex_2, E edge = E());

        /**
         * Przeszukiwanie grafu wszerz.
         *
         * Wierzchołek musi zawierać dodatkowe informacje:
         * int t - odległość wierzchołka od źródła wyszukiwania
         * int s - nr wierzchołka, z którego prowadzi znaleziona, najkrótsza trasa
         */
        void bfs(int source);

        std::vector<Ve> getVertices();
};

#endif // GRAPTH_H
