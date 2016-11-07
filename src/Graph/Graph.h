/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef GRAPTH_H
#define GRAPTH_H

#include <vector>
#include "./Vertex.h"
#include "./Edge.h"

/**
 * Szablon klasy Graph
 *
 * @param V Klasa z dodatkowymi informacjami o wierchołku, po której dziedziczy Vertex
 * @param E Klasa z dodatkowymi informacjami o krawędzi, po której dziedziczy Edge
 */
template<class V, class E>
class Graph
{
    private:
        std::vector<Vertex<V, E> > g;

        /**
         * Pamiętania aktualnego czasu przetwarzania przy dfs
         *
         * @var int t
         */
        int t;

        /**
         *
         * @param v
         */
        void dfsR(int v);

    public:
        Graph(unsigned long n = 0);

        /**
         * Dodawanie krawędzi skierowanej
         *
         * @param b
         * @param e
         * @param d
         */
        void edgeD(int b, int e, E d = E());

        /**
         * Dodawanie krawędzi nieskierowanej
         *
         * @param b
         * @param e
         * @param d
         */
        void edgeU(int b, int e, E d = E());

        /**
         * Przeszukiwanie grafu wszerz.
         *
         * Wierzchołek musi zawierać dodatkowe informacje:\n
         * int t - odległość wierzchołka od źródła wyszukiwania\n
         * int s - nr wierzchołka, z którego prowadzi znaleziona, najkrótsza trasa
         *
         * @param s
         */
        void bfs(int s);

        /**
         * Przeszukiwanie grafu w głąb
         *
         * Wierzchołek musi zawierać dodatkowe informacje:\n
         * int d - czas wejścia do wierzchołka\n
         * int f - czas wyjścia z wierzchołka\n
         * int s - nr wierzchołka, z którego prowadzi znaleziona, najkrótsza trasa
         *
         * @param e
         */
        void dfs(int e = -1);

        //region Getters & Setters

        /**
         * @return std::vector<Vertex<V, E>>
         */
        std::vector<Vertex<V, E> > getG();

        //endregion
};

#endif // GRAPTH_H
