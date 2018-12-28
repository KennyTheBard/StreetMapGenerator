#include <cstdlib>
#include <iostream>

#include "map.h"

using namespace std;

int main() {
    map *m = new map(10, 40, 0.25);

    m->generate();
    bool **g = m->get_map();

    for (int i = 0; i < m->get_height(); i++) {
        for (int j = 0; j < m->get_width(); j++)
            if (g[i][j])
                cout << "#";
            else
                cout << " ";
        cout << endl;
    }

    return 0;
}
