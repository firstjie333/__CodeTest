// 评测题目1: 
// 1. C++编程题：实现一个Image类，支持创建指定大小的图片，获取指定像素值
#include <iostream>
#include <vector> 

typedef unsigned char Byte;

struct DataInfo
{
    Byte r;
    Byte g;
    Byte b;
};

class Image
{
public:
  
    Image(int w,int h): row(w), col(h)
    {
        // new 
        dataPtr = new DataInfo*[row];
        for(size_t r=0;r<row; r++)
            dataPtr[r] = new DataInfo[col];

        std::cout <<"new a image :" << sizeof(dataPtr) << std::endl;
    }

    ~Image()
    {
        //free 
        for(int r=0;r<row;r++)
            delete []dataPtr[r];

        delete []dataPtr;
    }


    void  setDataInfoByIndex(int r, int c, DataInfo &data)
    {
        dataPtr[r][c] = data;
    }

    DataInfo getDataInfoByIndex(int r, int c)
    {
        return dataPtr[r][c];
    }
    
private:
  int row;
  int col;

  DataInfo** dataPtr = nullptr;
};


int main()
{
    Image* img = new Image(400,400);
    for(size_t r=0;r<400;r++)
    {
        for(size_t c=0;c<400;c++)
        {
            DataInfo d;
            d.b= 3;
            d.r= 5;
            d.g= 7;
            img->setDataInfoByIndex(r,c,d);
        }
    }

    DataInfo tmpPixel = img->getDataInfoByIndex(3,6);
    std::cout << (int)tmpPixel.b  <<"," << (int)tmpPixel.g << "," << (int)tmpPixel.r <<  std::endl;

    delete img;
    
    return 0;

}