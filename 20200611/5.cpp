#include <iostream>
#include <vector>

/**
 * @brief 格子游戏
 * 
 * @return int 
 */
int main()
{
    int N,M;
    std::cin >> N >>M;

    std::vector<int> Box;
    // Box.reserve(N);
    for(auto i=0; i<N; i++)
    {
        int tmp; 
        std::cin >> tmp;
        Box.push_back(tmp);
    }

    for(auto j=0;j<M;j++)
    {
        int a,b,c;
        std::cin >> a >> b >> c;

        if(a==2)
        {
            int sum=0;
            for(auto k=b;k<=c;k++)
            {
                sum+= Box[k-1];
            }
            std::cout << sum << std::endl;
        }
           
        if(a==3)
        {
            int max=0;
            for(auto k=b;k<=c;k++)
            {
                max = std::max(max,Box[k-1]) ;
            }
            std::cout << max << std::endl;
        }
    }
}