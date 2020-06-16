#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/*
有股神吗？
有，小赛就是！
经过严密的计算，小赛买了一支股票，他知道从他买股票的那天开始，股票会有以下变化：第一天不变，以后涨一天，跌一天，涨两天，跌一天，涨三天，跌一天...依此类推。
为方便计算，假设每次涨和跌皆为1，股票初始单价也为1，请计算买股票的第n天每股股票值多少钱？
*/


int main()
{
	int day;
    while(std::cin >> day)
    {
    	double price = 0.0; 
        int down = 0;
        int sumDay = 0;
        
        while(true)
        {
        	int current=down+2;
            sumDay+=current;
            if(sumDay >= day)
            {
            	break;
            }
            down++;
        }
        
        price = day - 2*down;
        
    	std::cout << price << std::endl; 
        
    }
    return 0;
}






