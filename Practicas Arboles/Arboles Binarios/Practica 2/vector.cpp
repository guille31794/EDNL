#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> v(32);
    
    cout << "Size is: " << v.size() << '\n';
    cout << "Element at v[0] is : " << v.at(15) << endl;

    return 0;
}