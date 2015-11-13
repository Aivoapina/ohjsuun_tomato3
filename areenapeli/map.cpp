#include "map.h"
#include "tile.h"

Map::Map()
{

}

void Map::makeMap()
{
    for ( int i = 1; i < 16; i++){
        map_.insertRow(i, Tile("#FF0000"));
    }
    for ( int j = 1; j < 10; j++){

    }
}

