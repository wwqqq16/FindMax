#ifndef _FINDMAX_H
#define _FINDMAX_H
#include "RunFind.h"

class node {
public:
  int up, down, left, right;
  int time = 117483647;       //用于储存到达这个block所用时间
  int visit_time = 117483647; //用于储存到达这个街道所用时间， dfs过程用
  bool visited = false;
  int accept_how = -1;  // accept_how how y正为0，逆时针0-4
  bool accept = false;
  node(int up = 0, int down = 0, int left = 0, int right = 0){
    this->down = down;
    this->up = up;
    this->left = left;
    this->right = right;
  }
};

class bfsnode {
public:
  int x, y, how, time;
  bfsnode(){
    ;
  };
  bfsnode(int x, int y, int how, int time){
    this -> x = x;
    this -> y = y;
    this -> how = how;
    this -> time = time;
  };
};

class FindMax {
public:
    FindMax(int citySize, const StreetBlock *streets, int numStreets);
    void find(Coordinate fireHouses[4], Coordinate *furthest, int *time);
    int citysize = 0;
    node v[1000][1000];
private:
    // void reset_visited();
    void bfs(Coordinate fireHouses[]);
    void dfs(int x, int y, int how, int time);
    void dfs_stack(int starx, int stary);
};  // class FindMax

#endif /* _FINDMAX_H */
