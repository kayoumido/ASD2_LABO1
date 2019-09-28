/**
 * File: GraphFromImage.h
 * Authors: Olivier Cuisenaire
 * Modified by: Robin Demarta, Loïc Dessaules, Doran Kayoumi
 *
 * Created on 2. octobre 2014, 12:09
 * Description: Class to generate a Graph based on an Image
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

// ELEMENTS PRIVES: LIBRE D'AJOUTER DES ELEMENTS
private:
    const bitmap_image &image;

    // **** ___VOTRE CODE CI-DESSOUS___ **** //
    bool isIdxInsideGraph(int idx) const;

    bool isCoordInsideImage(int x, int y) const;

    bool isCorrectAdjacent(int v, unsigned char rWanted, unsigned char gWanted, unsigned char bWanted) const;
};

#endif    /* GRAPHFROMIMAGE_H */
