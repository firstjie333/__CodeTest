
/**
 * A，B，C均为整数, A<C, B<C；c装满了水，a，b是空的。
水可以在容器之间互相灌装，灌装要求或者接收容器被注满，或者源容器被倒空。
灌装时水不会溢出或减少，灌装可以一直进行下去。


请输出所有a容器为空时，c容器内水的值。请将这些值按升序排序。
 */


// ! 我写的两种方案，应该还是不太对，有空再研究一下


#include <iostream>
#include <typeinfo>
#include <math.h> 
#include <cmath> 
#include <set>
#include <algorithm>


//　容量
int a,b,c;
// 杯子
int A,B,C;

bool moveC2B()
{
    if(C<b)
    {
        B=C;
        C=0;
    }
    else
    {
        C-=b;
        B=b;
    }
    return A==0;
}

bool moveC2A()
{
    if(C<a)
    {
        A=C;
        C=0;
    }
    else
    {
        C-=a;
        A=a;
    }
    return A==0;
}


bool moveB2A()
{
    if(B<a)
    {
        A=B;
        B=0;
    }
    else
    {
        B-=a;
        A=a;
    }
    return A==0;
}


bool moveB2C()
{
    C += B;
    B = 0;
    return A==0;
}

bool moveA2C()
{
    C += A;
    A = 0;
    return A==0;
}

bool moveA2B()
{
    if( (B+A)>b)
    {
        B=b;
        A=A-b;
    }
    else
    {
        B=B+a;
        A=0;
    }
    return A==0;
}



void FinalStep(std::set<int> &result)
{

    while(A!=0)
    {
        moveA2B();
        if(A!=0)
            moveA2C(); 

        moveA2C(); 
    }

    result.insert(C);
}

int main()
{

    // 方案１
    std::set<int> result1;
    std::cin >> a >>b >>c;
    A=B=0;C=c;
    if(a==b)
    {
        result1.insert(c-b);
        result1.insert(c);
    }
    else
    {
        size_t i=c-b, j=c;
        result1.insert(i);
        result1.insert(j);
        for(; i<=c && j>=0 && i<j;)
        {
            
            i+=a;
            j-=a;
            result1.insert(i);
            result1.insert(j);
        }
    }
    

    for(auto &it : result1)
    {
        std::cout <<"Result A: "<< it << std::endl; 
    }


    // 方案２　
    A=B=0;C=c;


    std::set<int> result;

    // case 1:
    moveC2A();
    int tmpA=A; int tmpB = B; int tmpC=C;
    if(A!=0)
    {
        A=tmpA;B=tmpB;C=tmpC;
        if(moveA2B())   result.insert(C);
        std::cout <<"Plan:" << A <<","<<B <<","<<C <<std::endl;

        A=tmpA;B=tmpB;C=tmpC;
        if(!moveA2B() && moveA2C() ) result.insert(C);
        std::cout <<"Plan:" << A <<","<<B <<","<<C <<std::endl;

        A=tmpA;B=tmpB;C=tmpC;
        if(moveA2C())   result.insert(C);
        std::cout <<"Plan:" << A <<","<<B <<","<<C <<std::endl;
    }

    A=0;B=0;C=c;
    moveC2B(); moveB2A();
    tmpA=A;  tmpB = B;  tmpC=C;
    if(A!=0)
    {
        A=tmpA;B=tmpB;C=tmpC;
        if(moveA2B())   result.insert(C);
        std::cout <<"Plan:" << A <<","<<B <<","<<C <<std::endl;

        A=tmpA;B=tmpB;C=tmpC;
        if(!moveA2B() && moveA2C() ) result.insert(C);
        std::cout <<"Plan:" << A <<","<<B <<","<<C <<std::endl;

        A=tmpA;B=tmpB;C=tmpC;
        if(moveA2C())   result.insert(C);
        std::cout <<"Plan:" << A <<","<<B <<","<<C <<std::endl;
    }

    for(auto &it : result)
    {
        std::cout <<"Result B: "<<  it << std::endl; 
    }

}
