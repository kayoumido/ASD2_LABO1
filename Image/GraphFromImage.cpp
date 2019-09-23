#include "GraphFromImage.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {
    // Nothing to do ?
}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {

}

// throws std::out_of_range
int GraphFromImage::idx(int x, int y) const {
    // Check that coordinates are inside the image
    if((x >= 0 || x < (int)image.width()) && (y >= 0 || y < (int)image.height())){
        return y + x * (int)image.width();
    }else{
        throw(out_of_range("Coordinates are outside the image"));
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
