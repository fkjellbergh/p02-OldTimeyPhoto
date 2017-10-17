#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"

using namespace std;

int main()
{
        Bitmap image;
        vector <vector <Pixel> > bmp;
        Pixel rgb;
        string pixelPic; 
        bool validImage;
        validImage = false;

        do
        {
                //Asks for a file
                cout<<"What file would you like to edit?"<<endl;
                cin>>pixelPic;
                //Opens image
                image.open(pixelPic);
                //Verify file is image
                validImage = image.isImage();
                if(validImage == false)
                {
                        cout<<"File is invalid. Please re-eneter file or enter new file."<<endl;
                }
        } 
        while(validImage == false);
        if (validImage == true)
        {
                bmp = image.toPixelMatrix();
        }
        if (bmp.size() > 0 && bmp[0].size() > 0)
        {
                for(int row = 0; row < bmp.size(); row++)
                {
                        for(int col = 0; col < bmp[row].size(); col++)
                        {
                                rgb = bmp[row][col];
                                int avg = (rgb.red + rgb.blue+ rgb.green)/3;
                                rgb.red = avg;
                                rgb.blue = avg;
                                rgb.green = avg;
                                bmp[row][col] = rgb;
                        }
                }
        }
        image.fromPixelMatrix(bmp);
        image.save("OldTimeyPhotoFilter.bmp");









        return 0;
}

