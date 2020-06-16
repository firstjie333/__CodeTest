#include <iostream>
#include <iomanip>

/*约德尔测试
*/

bool bNumOrDig(char c)
{
    return (isdigit(c) || isalpha(c));
}

int main()
{
    std::string a,b;
    std::cin >> a >> b;

    if(a.size() != b.size())
    {
        std::cout << 0.00 <<  "%" << std::endl;
    }

    int length = a.size();
    int count=0;

    for(size_t i=0; i<length;i++)
    {
        if( bNumOrDig(a[i]) && b[i]=='1')
            count++;
        else if( !bNumOrDig(a[i]) && b[i]=='0')
            count++;
    }
    double ratio = (100.0 * (double)count)/length ;
    std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
    std::cout << ratio << "%" << std::endl;
}