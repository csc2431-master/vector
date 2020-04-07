#include "vector.h"

#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>

using std::cout;
using std::endl;
using std::stringstream;


int main(int argc, char* argv[]) {
    Vector a(0);
    assert(!a.IsValid());
    cout << "Is Valid passed" << endl;

    Vector b(2);
    assert(b.Dimensions() == 2);
    assert(b[0] == 0.0);
    assert(b[1] == 1.0);
    b[0] = 1.5;
    b[1] = -1.5;
    assert(b[0] == 1.5);
    assert(b[1] == -1.5);
    stringstream stream;
    b.Write(stream);
    assert(stream.str() == "2 1.5 -1.5");
    stream.clear();
    stream.str("2 4.0 0.0");
    b.Read(stream);
    assert(b.Dimensions() == 2);
    assert(b[0] == 4.0);
    assert(b[1] == 0.0);
    stream.clear();

    double data1[] = {1, 2, 3};
    double data2[] = {-1, 2, 1};
    Vector c(3, data1);
    assert(c.Dimensions() == 3);
    assert(c[0] == 1.0);
    assert(c[1] == 2.0);
    assert(c[2] == 3.0);

    Vector d(3, data2);
    assert(d.Dimensions() == 3);
    assert(d[0] == -1.0);
    assert(d[1] == 2.0);
    assert(d[2] == 1.0);

    Vector e(d);
    assert(e.Dimensions() == 3);
    assert(e[0] == -1.0);
    assert(e[1] == 2.0);
    assert(e[2] == 1.0);

    assert(e == d);
    assert(e != c);

    Vector f(0);
    f = c;
    assert(f.Dimensions() == 3);
    assert(f[0] == 1.0);
    assert(f[1] == 2.0);
    assert(f[2] == 3.0);

    Vector g(3);
    Vector h(3);
    Vector i(3);
    g[0] = 2.5;
    g[1] = 1.2;
    g[2] = 0.0;
    h[0] = -0.5;
    h[1] = 0.3;
    h[2] = 4.0;
    i = g + h;
    assert(i.IsValid());
    assert(i[0] == 2.0);
    assert(i[1] == 1.5);
    assert(i[2] == 4.0);

    i = g - h;
    assert(i.IsValid());
    assert(i[0] == 3.0);
    assert(i[1] == 0.9);
    assert(i[2] == -4.0);

    assert(g.EuclidianDistance(h) == sqrt(25.81));
    assert(g.EuclidianDistance(g) == 0);

    cout << "All unit tests passed" << endl;

    return 0;
}
