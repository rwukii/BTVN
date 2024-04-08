#include <iostream>
#include <string>
using namespace std;

string kangaroo(int x01, int v1, int x02, int v2) {
    string yes = "YES";
    string no = "NO";
    if ((x01 < x02 && v1 < v2) || (x01 > x02 && v1 > v2)) return no;
    else if (x01 < x02 && v1 > v2)
    {
        float t = (float)(x02 - x01) / (v1 - v2);
        if (t >= 0 && t == (int)t) {
            return yes;
        }
        return no;
    }
    else {
        float t = (float)(x01 - x02) / (v2 - v1);
        if (t >= 0 && t == (int)t) return yes;
        return no;
    }
}
int main()
{
    int x01, v1, x02, v2;
    cin >> x01 >> v1 >> x02 >> v2;
    cout << kangaroo(x01, v1, x02, v2);
}
