#include<iostream>
int main()
{
    time_t t;
    srand((unsigned)&t);
    int x = rand()%10;
    std::cout<<x;
    return 0;

}
