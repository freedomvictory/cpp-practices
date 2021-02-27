//
// Created by dingguoliang on 2021/2/26.
//

#ifndef __IMAGE_H
#define __IMAGE_H

#include <iostream>


enum ImageType{
    LSI,
    SPI,
};
//abstract class
class Image{
private:
    /*used for saving subclass prototype*/
    static Image* prototypes[10];
    static int _count;
    /*got the image type*/
    virtual ImageType returnType() = 0;
    /*subclass clone */
    virtual Image* clone() = 0;

protected:
    /*add subclass prototype to prototypes array*/
    static void addPrototype(Image *image)
    {
        prototypes[_count++] = image;
    }

public:
    /*find subclass type ,and clone it*/
    static Image * findAndClone(ImageType t);
    virtual void draw() = 0;

};

Image* Image::prototypes[];
int Image::_count = 0;


Image* Image::findAndClone(ImageType t)
{
    for(int i = 0; i < _count; i++)
    {
        if(prototypes[i]->returnType() == t)
            return prototypes[i]->clone();
    }
}


#endif


