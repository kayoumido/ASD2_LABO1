/**
 * File: GraphFromImage.cpp
 * Authors: Olivier Cuisenaire
 * Modified by: Robin Demarta, Loïc Dessaules, Doran Kayoumi
 *
 * Created on 18. septembre 2014, 10:46
 * Description: Class to generate a Graph based on an Image
 */

#include "GraphFromImage.h"

#include <iostream>
#include <stdexcept>

using namespace std;

GraphFromImage::GraphFromImage(const bitmap_image &i) : image(i) {}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
    Iterable adj = {};

    if (!isIdxInsideGraph(v)) {
        throw(out_of_range("Index is outside of the graph"));
    }

    unsigned char rWanted, gWanted, bWanted;

    // get the colour of the selected pixel
    image.get_pixel((unsigned) x(v), (unsigned) y(v), rWanted, gWanted, bWanted);

    // calculate the indexes of the potential adjacent pixels
    // i.e. the top, bottom, right and left pixels
    int topAdj   = v - (int) image.width();
    int leftAdj  = v - 1;
    int rightAdj = v + 1;
    int botAdj   = v + (int) image.width();

    // check that adjacent are correct
    if (isCorrectAdjacent(topAdj, rWanted, gWanted, bWanted)) {
        adj.push_back(topAdj);
    }

    if (isCorrectAdjacent(leftAdj, rWanted, gWanted, bWanted)) {
        adj.push_back(leftAdj);
    }

    if (isCorrectAdjacent(rightAdj, rWanted, gWanted, bWanted)) {
        adj.push_back(rightAdj);
    }

    if (isCorrectAdjacent(botAdj, rWanted, gWanted, bWanted)) {
        adj.push_back(botAdj);
    }

    return adj;
}

// throws std::out_of_range
int GraphFromImage::idx(int x, int y) const {
    if (isCoordInsideImage(x, y)) {
        return x + y * (int) image.width();
    }

    throw(out_of_range("Coordinates are outside of the image"));
}

// throws std::out_of_range
int GraphFromImage::x(int idx) const {
    if (isIdxInsideGraph(idx)) {
        return idx % (int) image.width();
    }

    throw(out_of_range("Index is outside of the graph"));
}

// throws std::out_of_range
int GraphFromImage::y(int idx) const {
    if (isIdxInsideGraph(idx)) {
        return idx / (int) image.width();
    }

    throw(out_of_range("Index is outside of the graph"));

}

int GraphFromImage::V() const {
    return int(image.width() * image.height());
}


bool GraphFromImage::isCoordInsideImage(const int x, const int y) const {
    // Check that coordinates are inside the image
    return (x >= 0 && x < (int) image.width()) && (y >= 0 && y < (int) image.height());
}

bool GraphFromImage::isIdxInsideGraph(const int idx) const {

    // check that the given idx is within the Graph
    return idx >= 0 && idx < (int) image.width() * (int) image.height();
}

bool GraphFromImage::isCorrectAdjacent(int v, unsigned char rWanted, unsigned char gWanted, unsigned char bWanted) const {
    unsigned char r, g, b;

    if (isIdxInsideGraph(v)) {
        image.get_pixel((unsigned) x(v), (unsigned) y(v), r, g, b);
        return (r == rWanted && g == gWanted && b == bWanted);
    }

    return false;
}
