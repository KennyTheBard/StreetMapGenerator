#ifndef MAP_H
#define MAP_H

using namespace std;

class map {

public:
    // chance should be between 0 and 1,
    // 0 being a full grid, and 1 an empty map
    map(int height, int width, float chance);
    ~map();
    bool** get_map();
    void generate();

    int get_height();
    int get_width();
    float get_chance();
    void set_chance(float chance);

private:
    bool** nodes;
    int height, width;
    float chance;

    bool** alloc_map(int h, int w);

};

#endif
