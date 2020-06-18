#include <iostream>
#include <vector> 
#include <math.h>


/**
 * @brief 输出第ｉ个01数
 * 
 * @return int 
 */
int main()
{
    int k;
    while(std::cin>> k)
    {
        std::vector<int> data;
        data.push_back(0);
        data.push_back(1);
        data.push_back(10);
        data.push_back(11);
        

        int baseNum = 10; 
        int sumNum = 4;
        for(int i=4; i<k; i++)
        {
            int count = 0;
            for(int j=0;j<i;j++)
            {   
                int num = 10*baseNum +  data[j];
                data.push_back(num);
                count++;

                if(count==sumNum)
                {
                    sumNum += count;
                    baseNum = 10*baseNum;
                    break;
                }
            }
            
        }

        for(auto &n : data)
            std::cout << n<<  "," << sumNum   << std::endl; 
    }

    
}