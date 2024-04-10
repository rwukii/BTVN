#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int query; std::cin >> query;
    set<int> s;
    int x, y;
    for (int i = 0; i < query; i++)
    {
        cin >> x >> y;
        if (x == 1)
        {
            s.insert(y);
        }
        else if (x == 2)
        {
            s.erase(y);
        }
        else if (x == 3)
        {
            set<int>::iterator itr = s.find(y);
            if (itr != s.end())
            {
                cout << "Yes" << "\n";
            }
            else {
                cout << "No" << "\n";
            }
        }
    } 
    return 0;
}
