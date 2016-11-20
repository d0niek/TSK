/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./ForestGenerator.h"

ForestGenerator::ForestGenerator(int cellsPerRow, int cellsPerColumn)
    : cellsPerRow(cellsPerRow), cellsPerColumn(cellsPerColumn) {
}

Graph<Cell, Empty> ForestGenerator::Generate(float width, float height) {
    Graph<Cell, Empty> forest(cellsPerColumn * cellsPerRow);

    CalculateCellWidthAndHeight(width, height);

    for (int i = 0; i < cellsPerRow; i++) {
        for (int j = 0; j < cellsPerColumn; j++) {
            int cellIndex = (i * cellsPerColumn) + j;

            forest.vertices[cellIndex] = CreateVertex(i, j);

            AddUndirectedEdgeToRightNeighbor(forest, cellIndex);
            AddUndirectedEdgeToBottomNeighbor(forest, cellIndex);
        }
    }

    return forest;
}

void ForestGenerator::CalculateCellWidthAndHeight(float width, float height) {
    cellWidth = (width - cellsPerColumn) / cellsPerColumn;
    cellHeight = (height - cellsPerRow) / cellsPerRow;
}

Graph<Cell, Empty>::Vertex ForestGenerator::CreateVertex(int row, int col) {
    Graph<Cell, Empty>::Vertex vertex = Graph<Cell, Empty>::Vertex();

    Vector2f point(col * cellWidth + col, row * cellHeight + row);
    Color color(0.0f, 255.0f, 0.0f, 1.0f);

    vertex.SetPoint(point);
    vertex.SetWidth(cellWidth);
    vertex.SetHeight(cellHeight);
    vertex.SetColor(color);

    return vertex;
}

void ForestGenerator::AddUndirectedEdgeToRightNeighbor(Graph<Cell, Empty> &forest, int v1) {
    int rightNeighbor = v1 + 1;
    int lastNeighborInRow = (v1 / cellsPerColumn) * cellsPerColumn + cellsPerColumn;

    if (rightNeighbor < lastNeighborInRow) {
        forest.edgeUndirected(v1, rightNeighbor);
    }
}

void ForestGenerator::AddUndirectedEdgeToBottomNeighbor(Graph<Cell, Empty> &forest, int v1) {
    int bottomNeighbor = v1 + cellsPerColumn;

    if (bottomNeighbor < cellsPerRow) {
        forest.edgeUndirected(v1, bottomNeighbor);
    }
}

void ForestGenerator::ResetCellPointAndSize(Graph<Cell, Empty> &forest, float width, float height) {
    CalculateCellWidthAndHeight(width, height);

    for (int i = 0; i < cellsPerRow; i++) {
        for (int j = 0; j < cellsPerColumn; j++) {
            int cellIndex = (i * cellsPerColumn) + j;
            Vector2f point(j * cellWidth + j, i * cellHeight + i);

            forest.vertices[cellIndex].SetPoint(point);
            forest.vertices[cellIndex].SetWidth(cellWidth);
            forest.vertices[cellIndex].SetHeight(cellHeight);
        }
    }
}
