#include <iostream>

int main(void)
{
    std::string  s;

    std::cin >> s;
    try
    {
        int n = stoi(s);
        std::cout << n << std::endl;
    }
    catch(...){ std::cout << "Bad String" << std::endl; }
    return 0;
}