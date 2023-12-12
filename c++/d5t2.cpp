#include <bits/stdc++.h>
using namespace std;

class boiler
{
public:
    string vegetables;
    string meat;
    string flavour;
    float time;
    float T_required;
    float T_actual;
    float T_up()
    {
        float T_origin = T_actual;
        T_actual = T_required;
        return T_origin;
    }
    void T_down(float t)
    {
        T_actual = t;
    }
    string cook(float& sum)
    {
        float t;
        if (T_required > T_actual)
        {
            sum = (T_required - T_actual) * 2;
            t = T_up();
        }
        else
        {
            sum = 0;
        }
        sum += time;
        T_down(t);
        return vegetables + " " + meat + "(" + flavour + ")";
    }
};

int main()
{
    boiler x;
    x.vegetables = "a";
    x.meat = 'b';
    x.flavour = 'c';
    x.time = 1.2;
    x.T_required = 64.5;
    x.T_actual = 26.3;
    float sum = 0;
    cout << x.cook(sum);
    cout << endl << sum;
}