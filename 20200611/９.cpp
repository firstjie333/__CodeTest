#include <iostream>
#include <string>

/**
 * @brief 字符判断
 * 
 * @return int 
 */
int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2 ;

    bool yes = false;
    for(auto i=0;i<str2.size(); i++)
    {
        size_t index = str1.find(str2[i]);
        if(index == str1.npos)
        {
            std::cout <<"0" << std::endl; 
            return 0;
        }
        else
        {
            
            str1.erase(str1.begin()+index);
        }
    }
    

    std::cout << "1" << std::endl;

    return 0;
    
}