//
// Created by dingguoliang on 2021/2/26.
//

#include "ImageChildren.h"

ImageType imageTypes[] = {LSI, SPI, LSI, SPI};

int main(int argc, char **argv)
{
    Image* images[4];
    int i = 0;
    for(auto typ : imageTypes)
    {
        images[i] = Image::findAndClone(typ);
        i++;
    }

    for(auto image : images)
        image->draw();
    //release memory
    for(auto image : images)
        delete image;
    return 0;
}