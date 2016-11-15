/**
 * Copyright 2016 Damian Glinkowski <damianglinkowski@gmail.com>
 */

#include "./ForestGenerator.h"

ForestGenerator::ForestGenerator(int cellsPerRow, int cellsPerColumn)
    : cellsPerRow(cellsPerRow), cellsPerColumn(cellsPerColumn) {
}

std::vector<Cell> ForestGenerator::Generate(float width, float height) {
    std::vector<Cell> forest;
    float cellWidth = (width - cellsPerColumn) / cellsPerColumn;
    float cellHeight = (height - cellsPerRow) / cellsPerRow;

    for (int i = 0; i < cellsPerRow; i++) {
        for (int j = 0; j < cellsPerColumn; j++) {
            Vector2f point(j * cellWidth + j, i * cellHeight + i);
            Color color(0.0f, 255.0f, 0.0f, 1.0f);

            forest.push_back(Cell(point, cellWidth, cellHeight, color));
        }
    }

    return forest;
}
