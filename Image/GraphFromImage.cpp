#include "GraphFromImage.h"

#include <iostream>
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
    try {
        if(isCoordInsideImage(x,y)){
            return y + x * (int)image.width();
        }
    }catch(const out_of_range& e){
        throw e;
    }
}

// throws std::out_of_range
int GraphFromImage::x(int idx) const {
    try {
        if (isIdxInsideImage(idx)) {
            return idx % (int)image.width();
        }
    }catch(const out_of_range& e){
        throw(e);
    }
}

// throws std::out_of_range
int GraphFromImage::y(int idx) const {
    try {
        if (isIdxInsideImage(idx)) {
            return idx / (int) image.height();
        }
    }catch(const out_of_range& e){
        throw(e);
    }
}

int GraphFromImage::V() const {
    return int(image.width() * image.height());
}





bool GraphFromImage::isCoordInsideImage(int x, int y) const{
    // Check that coordinates are inside the image
    if((x >= 0 || x < (int)image.width()) && (y >= 0 || y < (int)image.height())){
        return true;
    }else{
        throw(out_of_range("Coordinates are outside the image"));
    }
}

bool GraphFromImage::isIdxInsideImage(int idx) const{
    if(idx >= 0 || idx < (int)image.width() * (int)image.height()){
        return true;
    }else{
        throw(out_of_range("Index are outside the image"));
    }
}
