//
// Created by dingguoliang on 2021/2/26.
//

#ifndef IMAGECHILDREN_H
#define IMAGECHILDREN_H

#include "Image.h"
class LandSatImage : public Image {

private:
    static LandSatImage _LandSatImage;
    Image* clone() override;
    ImageType returnType() override {return LSI;}

    LandSatImage();
    LandSatImage(int i);
public:
    void draw() override;
};
//auto call default constructor : addPrototype(this)
//add self to base class
LandSatImage LandSatImage::_LandSatImage;

LandSatImage::LandSatImage()
{
    addPrototype(this);
}

LandSatImage::LandSatImage(int i)
{

}

Image* LandSatImage::clone()
{
    return new LandSatImage(1);
}
void LandSatImage::draw()
{
    std::cout << "LandSatImage::draw()" << std::endl;
}

class SpotImage : public Image {

private:
    static SpotImage _SpotImage;
    Image* clone() override;
    ImageType returnType() override {return SPI;}

    SpotImage();
    SpotImage(int i);
public:
    void draw() override;
};

SpotImage SpotImage::_SpotImage;

SpotImage::SpotImage()
{
    addPrototype(this);
}

SpotImage::SpotImage(int i)
{

}

Image* SpotImage::clone()
{
    return new SpotImage(1);
}
void SpotImage::draw()
{
    std::cout << "SpotImage::draw()" << std::endl;
}



#endif //HOUJIEPRAC_IMAGECHILDREN_H
