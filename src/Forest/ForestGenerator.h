/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#ifndef FORESTGENERATOR_H
#define FORESTGENERATOR_H

#include "../Util/Vector2f.h"
#include "../Graph/Graph.h"
#include "../Graph/Empty.h"
#include "./Cell.h"

class ForestGenerator {
    private:
        int cellsPerRow;
        int cellsPerColumn;
        float cellWidth;
        float cellHeight;

        void CalculateCellWidthAndHeight(float width, float height);

        Graph<Cell, Empty>::Vertex CreateVertex(int row, int col);

        void AddUndirectedEdgeToRightNeighbor(Graph<Cell, Empty> &forest, int v1);
        void AddUndirectedEdgeToBottomNeighbor(Graph<Cell, Empty> &forest, int v1);

    public:
        ForestGenerator(int cellsPerRow, int cellsPerColumn);

        Graph<Cell, Empty> Generate(float width, float height);
        void ResetCellPointAndSize(Graph<Cell, Empty> &forest, float width, float height);
};

#endif //FORESTGENERATOR_H
