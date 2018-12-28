#include <string.h>
#include <cstdlib>
#include <ctime>

#include "map.h"

map::map(int height, int width, float chance)
: height(height), width(width), chance(chance) {
    this->nodes = alloc_map(height, width);
}

map::~map() {
    for (int i = 0; i < height; i ++)
        free(nodes[i]);

    free(nodes);
}

bool** map::get_map() {
    bool **ret = alloc_map(height, width);

    for (int i = 0; i < height; i++)
        memcpy(ret[i], nodes[i], width * sizeof(bool));

    return ret;
}

void map::generate() {
    srand(time(NULL));

    int num;
    int scaled_chance = (int) (chance * 10000);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            num = rand() % 10000;
            if (num < scaled_chance)
                nodes[i][j] = false;
            else
                nodes[i][j] = true;
        }
}

int map::get_height() {
    return height;
}

int map::get_width() {
    return width;
}

float map::get_chance() {
    return chance;
}

void map::set_chance(float chance) {
    this->chance = chance;
}

bool** map::alloc_map(int h, int w) {
    bool **map = (bool **) calloc (h, sizeof(bool *));
    for (int i = 0; i < h; i ++)
        map[i] = (bool *) calloc (w, sizeof(bool));

    return map;
}
