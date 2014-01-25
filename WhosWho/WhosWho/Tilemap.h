#ifndef TILEMAP_H
#define TILEMAP_H
#include "Debug.h"
#include "Tile.h"
//#include "Camera.h"
#include "CC_Texture.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

using std::string;

#define TILE_WIDTH 16
#define TILE_HEIGHT 16
#define MAP_WIDTH 50
#define MAP_HEIGHT 40
#define DEFAULT_TILE 0
#define NUMBER_OF_TILES 4

class TileMap
{
public:
	TileMap(CC_Texture* tileSheet);
	~TileMap();
	int GetCellByPointX(int x); //Get x map cell for this pixel point
	int GetCellByPointY(int y); //Get y map cell for this pixel point
	bool IsCellPassable(int x, int y);
	bool IsCellPassableByPoint(int x, int y);
	Tile* GetTileAtCell(int x, int y);
	Tile* GetTileAtPoint(int x, int y);
	void Draw(SDL_Renderer* renderer/*, Camera* camera*/);
	void LoadMap(string fileName);
	void ClearMap();
private:
	Tile* m_p_MapCells[MAP_WIDTH][MAP_HEIGHT];
	int m_TileCollideInfo[NUMBER_OF_TILES];
	CC_Texture* m_p_TileSheet;
	int TilesPerRow();
	SDL_Rect TileSourceRectangle(int index);
	void SetTileCollideInformation();
};

#endif

