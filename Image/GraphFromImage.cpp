#include "GraphFromImage.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {
    // All pixel (a x,y pair) is a vertex of the graph
    for(int row = 0; row < (int)i.width(); ++row){
        for(int col = 0; col < (int)i.height(); ++col){
            this->vertexes.emplace_back(make_pair(row,col));
        }
    }
}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {

}

// throws std::out_of_range
int GraphFromImage::idx(int x, int y) const {
    pair<int, int> xy = make_pair(x,y);
    auto it = find(this->vertexes.begin(), this->vertexes.end(), xy);

    if(it != this->vertexes.end()){
        return (int)distance(vertexes.begin(), it);
    }else{
        throw std::out_of_range("x,y outside the image");
    }
}

// throws std::out_of_range
int GraphFromImage::x(int idx) const {
}

// throws std::out_of_range
int GraphFromImage::y(int idx) const {
    /* A IMPLEMENTER */
}

int GraphFromImage::V() const {
    /* A IMPLEMENTER */
}
