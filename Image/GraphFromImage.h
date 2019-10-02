/**
 * File: GraphFromImage.h
 * Authors: Olivier Cuisenaire
 * Modified by: Robin Demarta, Loïc Dessaules, Doran Kayoumi
 *
 * Created on 2. octobre 2014, 12:09
 * Description: Class to generate a Graph based on an Image
 *
 * Details :    We've decided to not add the complexities
 *              because all the methods are simple checks and didn't
 *              add any useful info.
 */

#ifndef GRAPHFROMIMAGE_H
#define    GRAPHFROMIMAGE_H

#include <list>
#include <vector>

#include "bitmap_image.hpp"

class GraphFromImage {
// INTERFACE PUBLIQUE A NE PAS MODIFIER
public:

    // constructeur
    GraphFromImage(const bitmap_image &i);

    typedef std::list<int> Iterable;

    /**
     * @brief Get the adjacent vertexes of given vertex
     * @param v vertex
     * @throws std::out_of_range
     *
     * @return list of all the adjacent
     */
    Iterable adjacent(int v) const;

    /**
     * @return the number of vertexes
     */
    int V() const;

    /**
     * @brief Get the index of the vertex representing the pixel @ the position x & y
     *
     * @param x coordinate
     * @param y coordinate
     * @throws std::out_of_range
     *
     * @return the index of vertex representing the pixel
     */
    int idx(int x, int y) const;

    /**
     * @brief Get the x coordinet of a vertex
     *
     * @param idx vertex
     * @throws std::out_of_range
     *
     * @return x coordinate of the given vertex
     */
    int x(int idx) const;

    /**
     * @brief Get the y coordinet of a vertex
     *
     * @param idx vertex
     * @throws std::out_of_range
     *
     * @return y coordinate of the given vertex
     */
    int y(int idx) const;

private:
    const bitmap_image &image;


    /**
     * @brief Check if an index is within the graph
     * @param idx index to check
     * @return boolean indicating if index is within the graph
     */
    bool isIdxInsideGraph(const int idx) const;

    /**
     * @brief Check if given coordinates are in the image
     * @param x coordinate
     * @param y coordinate
     * @return boolean indicating if the coordinates are in the image
     */
    bool isCoordInsideImage(const int x, const int y) const;

    /**
     * @brief Check if a vertex is a correct adjacent. i.e. it has the correct rgb
     * @param v vertex to check
     * @param rWanted wanted red
     * @param gWanted wanted green
     * @param bWanted wanted blue
     * @return boolean indicating if it's a correct adjacent
     */
    bool isCorrectAdjacent(const int v, const unsigned char rWanted, const unsigned char gWanted,
                           const unsigned char bWanted) const;
};

#endif    /* GRAPHFROMIMAGE_H */
