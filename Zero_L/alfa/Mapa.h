#ifndef _MAPA_H_
#define _MAPA_H_

#include <vector>
#include <random>
#include <curses.h>
#include <ctime>
#include "Obj.h"
#include "Wall.h"
#include "Character.h"
#include "Enemy.h"
#include "Sword.h"

class Mapa{
  public:
    Mapa();
    Mapa(Character* , std::vector<Wall>, int, int);
    bool wall_colision() const;//Verifica si el jugador colisiona con alguo de los muros
    bool wall_colision(int, int) const;//Verifica si la posicion (x, y) colisiona con alguno de los muros
    bool outside() const;
    bool enemys_colision();
    bool enemys_colision(const Obj&, int);
    bool enemys_colision(const Sword espada);
    void generate_enemy();
    void move_enemys();
    void move_agresive();
    void draw_walls();//Dibuja los muros
    void draw_enemys();

  private:
    int rows;
    int cols;
    std::mt19937 motor;
    std::uniform_int_distribution<int> rand_x;
    std::uniform_int_distribution<int> rand_y;
    std::uniform_int_distribution<int> rand_mov;
    std::vector<Wall> walls;
    Character* player;
    Enemy enemys;
    bool inside;
};

#endif
