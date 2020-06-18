#include <iostream>
#include <array>

/**
 * @brief 击鼓传花（动态规划）
 * 
 * @return int 
 */

int main()
{
    int N, M;
    std::cin >> N  >> M;
    int dp[31][31];

    dp[1][1]=1;
    dp[1][N-1]=1;


    for(auto i=2;i<=M;i++)
    {
        for(auto j=0;j<N;j++)
        {
            int addOne = (N - (j+1))%N;
            int subOne = (N - (j-1))%N;
            dp[i][j] = dp[i-1][addOne] + dp[i-1][subOne];

        } 
    }

    std::cout <<  dp[M][0] << std::endl; 
    
}