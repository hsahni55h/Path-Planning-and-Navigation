/* 

Grid(5x6):

0 1 0 0 0 0                             Where 1's represent obstacles and 0's represent free space.
0 1 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 0 0 1 1 0


Robot Start position: 0,0

Robot Goal Position: 4,5

Direction of Movement: Up(-1,0) - left(0,-1) - down(1,0) - right(0,1)

The Direction of Movement vector is a collection of four different 2D vectors each of which enables you to move between grid cells in the map.

Movement Arrows: Up(^) - left(<) - down(v) - right(>)

The Movement Arrows vector store the robot actions, this vector will be used to visualize the robot orientation at each grid cell on the shortest path.

Cost of Movement: 1

The Cost of Movement value indicates how much it cost to move from one cell to another. Here, the cost is equal for all possible movements.

*/
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Implemented the BFS: Expansion List

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Map class
class Map {
public:
    const static int mapWidth = 6;
    const static int mapHeight = 5;
    vector<vector<int> > grid = {                   // 0 indicates empty cell and 1 indicates obstacle
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0 }
    };
};

// Planner class
class Planner : Map {
public:
    int start[2] = { 0, 0 };
    int goal[2] = { mapHeight - 1, mapWidth - 1 };
    int cost = 1;

    string movements_arrows[4] = { "^", "<", "v", ">" };

    vector<vector<int> > movements{
        { -1, 0 },
        { 0, -1 },
        { 1, 0 },
        { 0, 1 }
    };
};

// Template function to print 2D vectors of any type
template <typename T>
void print2DVector(T Vec)
{
    for (int i = 0; i < Vec.size(); ++i) {
        for (int j = 0; j < Vec[0].size(); ++j) {
            cout << Vec[i][j] << ' ';
        }
        cout << endl;
    }
}

/*#### TODO: Code the search function which will generate the expansion list ####*/
// You are only required to print the final triplet values
void search(Map map, Planner planner)
{
    vector<vector<int>> closed(map.mapHeight, vector<int> (map.mapWidth));
    closed[planner.start[0]][planner.start[1]] = 1;                             // marking the visited nodes

    size_t x = planner.start[0];
    size_t y = planner.start[1];
    int g = 0;

    vector<vector<int>> open;
    open.push_back({g, static_cast<int>(x), static_cast<int>(y)});

    bool found = false;
    bool empty = false;

    size_t x2;
    size_t y2;

    while(!found && !empty)
    {
        if (open.size() == 0)
        {
            empty = true;
            cout << "Failed to reach a goal" << endl;
        }

        else
        {
            sort(open.begin(), open.end());
            reverse(open.begin(), open.end());

            vector <int> next{3};
            next = open.back();
            open.pop_back();
            x = static_cast<size_t>(next[1]);
            y = static_cast<size_t>(next[2]);
            g = next[0];
            
            if (x == static_cast<size_t>(planner.goal[0]) && y == static_cast<size_t>(planner.goal[1]))
            {
                found = true;
                cout << "[" << g << ", " << x << ", " << y << "]" << endl;
            }

            else
            {
                for(size_t i = 0; i < planner.movements.size(); i++)
                {
                    x2 = x + planner.movements[i][0];
                    y2 = y + planner.movements[i][1];
                    if (x2 >= 0 && x2 < map.grid.size() && y2 >= 0 && y2 < map.grid[0].size())
                    {
                        if (closed[x2][y2] == 0 and map.grid[x2][y2] == 0) 
                        {
                            int g2 = g + planner.cost;
                            open.push_back({ g2, static_cast<int>(x2), static_cast<int>(y2)});
                            closed[x2][y2] = 1;
                        };
                    };
                };

            };
        };
    };
};

int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Search for the expansions
    search(map, planner);

    return 0;
}