// Author Sean Davis

#include "FindMax.h"
#include <iostream>
#include <queue>
#include <stack>

FindMax::FindMax(int citySize, const StreetBlock *streets, int numStreets) {
    citysize = citySize;
    int x, y;

    for (int i = 0; i < numStreets; i++) {
        int speed = streets[i].speed;

        if (streets[i].startX == streets[i].endX) {
            x = streets[i].startX;
            int min_Y = std::min(streets[i].startY, streets[i].endY);
            int max_Y = std::max(streets[i].startY, streets[i].endY);

            v[x][min_Y].right = speed;
            v[x][min_Y].accept_how = 1;  //接受哪个方向上过来的

            v[x][max_Y].left = speed;
            v[x][max_Y].accept_how = 3;

            for (int end_y = min_Y + 1; end_y < max_Y; end_y++) {
                v[x][end_y].left = speed;
                v[x][end_y].right = speed;
            }

        } else if (streets[i].startY == streets[i].endY) {
            y = streets[i].startY;
            int min_X = std::min(streets[i].startX, streets[i].endX);
            int max_X = std::max(streets[i].startX, streets[i].endX);

            v[min_X][y].up = speed;
            v[min_X][y].accept_how = 2;

            v[max_X][y].down = speed;
            v[max_X][y].accept_how = 0;

            for (int end_x = min_X + 1; end_x < max_X; end_x++) {
                v[end_x][y].up = speed;
                v[end_x][y].down = speed;
            }
        } else {
            std::cout << "error" << std::endl;
        }
    }
}  // FindMax()

void FindMax::find(Coordinate fireHouses[4], Coordinate *furthest, int *time) {
    bfs(fireHouses);

    int x = 0, y = 0, max = 0;

    // dfs_stack(5, 17);
    // for (int i = 0; i < 4; i++) {
    //     // dfs(fireHouses[i].x, fireHouses[i].y, -2, 0);
    //     dfs_stack(fireHouses[i].x, fireHouses[i].y);
    // }

    // dfs(5, 17, -2, 0);
    // *time = v[10][10].time / 100000.0 * 3600;
    // furthest->x =10;
    // furthest->y = 10;

    for (int i = 0; i < citysize; i++) {
        for (int j = 0; j < citysize; j++) {
            if (max < v[i][j].time && v[i][j].accept == true) {
                max = v[i][j].time;
                x = i;
                y = j;
            }
        }
    }

    *time = v[x][y].time / 10000000.0 * 3600;
    furthest->x = x;
    furthest->y = y;

    std::cout << x << ' ' << y << std::endl;
    std::cout << v[x][y].time << std::endl;
    std::cout << v[x][y].time / 10000000.0 * 3600 << std::endl;

    std::cout << v[10][10].time << std::endl;
    std::cout << v[10][10].time / 10000000.0 * 3600 << std::endl;
}  // find()

void FindMax::bfs(Coordinate fireHouses[]) {
    std::queue<bfsnode> q;
    // q.push(bfsnode(5, 17, -2, 0));
    // q.push(bfsnode(16, 3, -2, 0));
    // q.push(bfsnode(4, 17, -2, 0));
    // q.push(bfsnode(4, 10, -2, 0));
    for (int i = 0; i < 4; i++) {
        q.push(bfsnode(fireHouses[i].x, fireHouses[i].y, -2, 0));
    }
    bfsnode top = bfsnode();
    while (!q.empty()) {
        top = q.front();
        q.pop();
        int x = top.x, y = top.y, time = top.time, how = top.how;
        if (x < 0 || x >= citysize || y < 0 || y >= citysize || time < 0) {
            //数字越界
            continue;
        }
        // std::cout << x << ' ' << y << ' ' << time << std::endl;

        if (v[x][y].accept_how == how && v[x][y].time > time) {  // 可以进入block且时间短
            v[x][y].time = time;
            v[x][y].accept = true;
        }

        // if (v[x][y].visited == true) {  //如果已经visited过， 进行路径时间判断
            if (v[x][y].visit_time > time) {
                v[x][y].visit_time = time;
            } else {
                continue;
            }
        // } else {  // 如果没有visit过， 进行标记及路径时间赋值
        //     v[x][y].visited = true;
        //     v[x][y].visit_time = time;
        // }

        // 继续广搜
        if (v[x][y].right != 0) {
            q.push(bfsnode(x, y + 1, 3, time + 0.1*10000000 / (v[x][y].right)));
        }
        if (v[x][y].up != 0) {
            q.push(bfsnode(x + 1, y, 0, time + 0.1*10000000 / (v[x][y].up)));
        }
        if (v[x][y].down != 0) {
            q.push(bfsnode(x - 1, y, 2, time + 0.1*10000000 / (v[x][y].down)));
        }
        if (v[x][y].left != 0) {
            q.push(bfsnode(x, y - 1, 1, time + 0.1*10000000 / (v[x][y].left)));
        }
    }
}




































// void FindMax::dfs(int x, int y, int how, int time) {
//     std::cout << x << ' ' << y << ' ' << time << std::endl;
//     if (x < 0 || x >= 20 || y < 0 || y >= 20 || time < 0) {
//         //数字越界
//         return;
//     }

//     if (v[x][y].visited == true) {  //如果已经visited过， 进行路径时间判断
//         if (v[x][y].visit_time > time) {
//             v[x][y].visit_time = time;
//         } else {
//             return;
//         }
//     } else {
//         v[x][y].visited = true;
//     }

//     if (v[x][y].accept_how == how) {
//         // v[x][y].time = std::min(v[x][y].time, time);  //找出时间最小的进入街区的点
//         if (v[x][y].time > time) {
//             v[x][y].time = time;
//             v[x][y].accept = true;
//         }
//     }

//     // 继续深搜
//     dfs(x + 1, y, 0, time + 0.1 * 1000000 / (v[x][y].up + 0.00000001));
//     dfs(x - 1, y, 2, time + 0.1 * 1000000 / (v[x][y].down + 0.0000001));
//     dfs(x, y - 1, 1, time + 0.1 * 1000000 / (v[x][y].left + 0.00000001));
//     dfs(x, y + 1, 3, time + 0.1 * 1000000 / (v[x][y].right + 0.0000001));
// }

void FindMax::dfs_stack(int starx, int stary) {
    std::stack<bfsnode> q;
    q.push(bfsnode(starx, stary, -2, 0));
    while (!q.empty()) {
        bfsnode top = q.top();
        q.pop();

        int x = top.x, y = top.y, how = top.how, time = top.time;

        std::cout << x << ' ' << y << ' ' << time << std::endl;
        if (x < 0 || x >= 20 || y < 0 || y >= 20 || time < 0) {
            //数字越界
            continue;
        }

        if (v[x][y].visited == true) {  //如果已经visited过， 进行路径时间判断

            if (v[x][y].accept_how == how && v[x][y].time > time) {  //找出时间最小的进入街区的点
                v[x][y].time = time;
                v[x][y].accept = true;
            }
            if (v[x][y].visit_time > time) {
                v[x][y].visit_time = time;
            } else {
                continue;
            }
        } else {
            v[x][y].visited = true;
            v[x][y].visit_time = time;

            if (v[x][y].accept_how == how && v[x][y].time > time) {  //找出时间最小的进入街区的点
                v[x][y].time = time;
                v[x][y].accept = true;
            }
        }

        // if (v[x][y].accept_how == how && v[x][y].time > time) {  //找出时间最小的进入街区的点
        //     v[x][y].time = time;
        //     v[x][y].accept = true;
        // }

        // 继续深搜

        // q.push(bfsnode(x - 1, y, 2, time + 0.1 * 1000000 / (v[x][y].down + 0.0000001)));
        // q.push(bfsnode(x, y + 1, 3, time + 0.1 * 1000000 / (v[x][y].right + 0.0000001)));
        // q.push(bfsnode(x, y - 1, 1, time + 0.1 * 1000000 / (v[x][y].left + 0.00000001)));
        // q.push(bfsnode(x + 1, y, 0, time + 0.1 * 1000000 / (v[x][y].up + 0.00000001)));

        q.push(bfsnode(x, y + 1, 3, time + 0.1 * 1000000 / (v[x][y].right + 0.0000001)));
        q.push(bfsnode(x + 1, y, 0, time + 0.1 * 1000000 / (v[x][y].up + 0.00000001)));
        q.push(bfsnode(x - 1, y, 2, time + 0.1 * 1000000 / (v[x][y].down + 0.0000001)));
        q.push(bfsnode(x, y - 1, 1, time + 0.1 * 1000000 / (v[x][y].left + 0.00000001)));
    }
}