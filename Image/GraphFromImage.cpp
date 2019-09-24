#include "GraphFromImage.h"

#include <iostream>
#include <stdexcept>

using namespace std;

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {
    // Nothing to do ?
}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
    Iterable adj;
    try {
        if(isIdxInsideImage(v)){
            unsigned char rWanted, gWanted, bWanted;
            image.get_pixel((unsigned) x(v), (unsigned) y(v), rWanted, gWanted, bWanted);

            int topAdj = v - (int)image.width();
            int leftAdj = v - 1;
            int rightAdj = v + 1;
            int botAdj = v + (int)image.width();

            try {
                if(isCorrectAdjacent(topAdj, rWanted, gWanted, bWanted)){
                    adj.push_back(topAdj);
                }
            }catch(const out_of_range& e){}

            try {
                if(isCorrectAdjacent(leftAdj, rWanted, gWanted, bWanted)){
                    adj.push_back(leftAdj);
                }
            }catch(const out_of_range& e){}

            try {
                if(isCorrectAdjacent(rightAdj, rWanted, gWanted, bWanted)){
                    adj.push_back(rightAdj);
                }
            }catch(const out_of_range& e){}

            try {
                if(isCorrectAdjacent(botAdj, rWanted, gWanted, bWanted)){
                    adj.push_back(botAdj);
                }
            }catch(const out_of_range& e){}
        }
    }catch(const out_of_range& e){
        throw e;
    }
    return adj;
}

// throws std::out_of_range
int GraphFromImage::idx(int x, int y) const {
    try {
        if(isCoordInsideImage(x,y)){
            return x + y * (int)image.width();
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
            return idx / (int)image.width();
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
    if((x >= 0 && x < (int)image.width()) && (y >= 0 && y < (int)image.height())){
        return true;
    }else{
        throw(out_of_range("Coordinates are outside the image"));
    }
}

bool GraphFromImage::isIdxInsideImage(int idx) const{
    if(idx >= 0 && idx < (int)image.width() * (int)image.height()){
        return true;
    }else{
        throw(out_of_range("Index are outside the image"));
    }
}

bool GraphFromImage::isCorrectAdjacent(int v, unsigned char rWanted, unsigned char gWanted, unsigned char bWanted) const {
    unsigned char r,g,b;
    try{
        if (isIdxInsideImage(v)) {
            image.get_pixel((unsigned) x(v), (unsigned) y(v), r, g, b);
            return (r == rWanted && g == gWanted && b == bWanted);
        }
    }catch(const out_of_range& e){
        throw e;
    }
}
