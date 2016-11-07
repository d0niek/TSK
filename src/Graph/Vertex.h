#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "./Edge.h"

/**
 * Szablon klasy Vertex
 *
 * @param V Klasa z dodatkowymi informacjami o wierchołku
 * @param E Klasa z dodatkowymi informacjami o krawędzi, po której dziedziczy Edge
 */
template<class V, class E>
class Vertex : public V, public std::vector<Edge<E> >
{
    //
};

#endif // VERTEX_H
