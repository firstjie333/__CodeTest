#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief 路灯
 * 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */


bool myfunction (int i,int j) { return (i<j); }


int main()
{
    int N,L;
    std::cin >> N >> L;

    std::vector<int> light;
    // light.reserve(N);

    for(size_t i=0;i<N;i++)
    {
        int a;
        std::cin >> a ;
        light.push_back(a);
    }
        
    

    std::sort(light.begin(),light.end(), myfunction);
    double distance = 0.0;
    for(size_t i=0; i<N;i++)
    {   
        double tmpDistance = 0.0;
        if(i==0)
        {
            tmpDistance = light[i];
        }
        else if(i==N-1)
        {
            tmpDistance = 15 - light[i];
        }
        else 
        {
            tmpDistance = (light[i] -light[i-1])*0.5;
        }
        distance = std::max(distance, tmpDistance);
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << distance << std::endl;

}