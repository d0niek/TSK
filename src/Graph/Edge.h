/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef EDGE_H
#define EDGE_H

/**
 * Szablon klasy Edge
 *
 * @param E Klasa z dodatkowymi informacjami o krawędzi
 */
template<class E>
class Edge : public E
{
    private:
        /**
         * Nr wierzchołka, do którego prowadzi krawędź
         *
         * @var int v
         */
        int v;

    public:
        Edge(E e, int v);

        //region Getters & Setters

        /**
         * @return int
         */
        int getV();

        //endregion
};

#endif // EDGE_H
