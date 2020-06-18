#include <iostream>
#include <math.h>
#include <vector>

/**************************************************************************************************
    Project 3

    给定N个二维平面上的点，则在平面上存在无数个矩形可以覆盖这些点，请编写程序求出可覆盖这些点的最小矩形的面积。
    函数rectangle():
    Input:
        double (*data)[2]: 二维点列，为N*2的二维矩阵，第一列表示x坐标，第二列表示y坐标；
        int N: 点的个数。
    return:
        double: 最小矩形的面积。
    注意：题目要求是矩形，而不是圆形或三角形等，矩形可能是长方形或者正方形。点列坐标在main函数中给定。
*/

void rotatePoint(double& x, double& y, double angle) 
{
  double a = x * cos(angle) - y * sin(angle);
  double b = x * sin(angle) + y * cos(angle);
  x = a;
  y = b;
}

void Rect(const std::vector<double>& x, const  std::vector<double>& y, double& length,double& width) 
{
  double area = 1024;
  int size = x.size();

  // rotate 0~90 degree
  for (int i = 0; i <= 90; ++i) 
  {
    double tmpx = x[0], tmpy = y[0];
    rotatePoint(tmpx, tmpy, i);

    double xl = tmpx, xr = tmpx, yt = tmpy, yb = tmpy;
    // traverse all points
    for (int j = 1; j < size; ++j) 
    {
      tmpx = x[j];
      tmpy = y[j];
      rotatePoint(tmpx, tmpy, i);
      if (tmpx < xl)
        xl = tmpx;
      if (tmpx > xr)
        xr = tmpx;
      if (tmpy < yb)
        yb = tmpy;
      if (tmpy > yt)
        yt = tmpy;
    }


    double xx = xr - xl, yy = yt - yb;
    if (area > xx * yy) 
    {
      area = xx * yy;
      length = xx;
      width = yy;
    }
  }
  //
  if (length < width) 
  {
    double tmp = length;
    length = width;
    width = tmp;
  }
}



/**************************************************************************************************
    Project 3

    给定N个二维平面上的点，则在平面上存在无数个矩形可以覆盖这些点，请编写程序求出可覆盖这些点的最小矩形的面积。
    函数rectangle():
    Input:
        double (*data)[2]: 二维点列，为N*2的二维矩阵，第一列表示x坐标，第二列表示y坐标；
        int N: 点的个数。
    return:
        double: 最小矩形的面积。
    注意：题目要求是矩形，而不是圆形或三角形等，矩形可能是长方形或者正方形。点列坐标在main函数中给定。
*/
#include <algorithm>
void rotateOnePoint(double& x, double& y, int angle) 
{
  double a = x * cos(angle) - y * sin(angle);
  double b = x * sin(angle) + y * cos(angle);
  x = a;
  y = b;
}
void rotatePoints(double (*data)[2], int N, int angle, std::vector<double> &XAxis, std::vector<double> &YAxis)
{
    for(size_t i=0;i<N;i++)
    {
        double x = data[i][0];
        double y = data[i][1];
        rotateOnePoint(x, y, angle);
        XAxis.push_back(x);
        YAxis.push_back(y);
    }
}


double getRectangle(std::vector<double> &XAxis, std::vector<double> &YAxis)
{
    double minX = *std::min_element(XAxis.begin(),XAxis.end());
    double maxX = *std::max_element(XAxis.begin(),XAxis.end());

    double minY = *std::min_element(YAxis.begin(),YAxis.end());
    double maxY = *std::max_element(YAxis.begin(),YAxis.end());
    
    double width  = maxX - minX;
    double height = maxY - minY;

    if(width >0 && height >0 )
    {
        return  width * height;
    }
    else
    {
        return -1;
    }
}

using namespace std;
double rectangle(double (*data)[2], int N)
{   
    int bestAngle  = 0;
    double minArea = 1e+7;

    for (int angle = 1; angle <= 90; ++angle) 
    {
        std::vector<double> XAxis, YAxis;
        rotatePoints(data, N, angle, XAxis, YAxis);
        double area = getRectangle(XAxis, YAxis);
        if(area>0 && minArea > area)
        {
            bestAngle = angle; 
            minArea = area; 
        }
    }
    std::cout << "minArea=" << minArea << std::endl;
    std::cout << "bestAngle=" << bestAngle << std::endl;
    return minArea;
}

int main()
{
   
    // // Project 3
    cout << "==========Project3=================" << endl;
    double data[5][2] = {0,0, 1,1, 2,2, 1,3, -1,2};
    cout << "The area of the min rectangle is " << rectangle(data, 5) << endl;
    cout << endl;
    cout << "==========Project3=================" << endl;


    std::vector<double> x;
    std::vector<double> y;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(1);
    x.push_back(-1);

    y.push_back(0);
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(2);

    double length = 0;
    double  width =0;
    Rect(x,y, length, width) ;
    std::cout << "Rect=" << length * width << std::endl;

    return 0;
}
