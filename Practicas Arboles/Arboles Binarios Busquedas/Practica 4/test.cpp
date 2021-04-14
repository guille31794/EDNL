#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v({1,2,3,4,5});
    vector<int>::iterator b{v.begin()}, e{v.end()};
    vector<int>::iterator m = b + e;


    return 0;
}
