#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

struct Edge {
    int source, toSubject;
    set<string> rules;

    Edge(int from, int to, set<string> rules) {
        this->source = from;
        this->toSubject = to;
        this->rules = rules;
    }
};

struct Graph {
    set<int> activeObjects;
    int objectsCount;
    vector<Edge> edges;

    Graph(int count, set<int> active, vector<Edge> edges) {
        this->objectsCount = count;
        this->edges = edges;
        this->activeObjects = active;
    }
    bool contains(set<int> a, int b){
	return a.count(b)!=0;
   }
   
   bool containsS(set<string> a, string b){
	return a.count(b)!=0;
   }
   bool contSTAR(int t,std::set <int> *obj){
    auto i  = obj->find(t);
    return i!=obj->end();
    }

    vector<set<int>> getIsland() {
        vector<set<int>> result;
        set<int> usedObjects;

        for(int objIndex = 0; objIndex < objectsCount; objIndex++) {
            if (!contains(usedObjects,objIndex) && contains(activeObjects,objIndex)) {
                set<int> islandObjects;

                usedObjects.insert(objIndex);
                islandObjects.insert(objIndex);

                for(int isObjIndex = 0; isObjIndex < objectsCount; isObjIndex++) {
                    if (!contains(usedObjects,isObjIndex)) {
                        if (isInIsland(islandObjects, isObjIndex)) {
                            islandObjects.insert(isObjIndex);
                            usedObjects.insert(isObjIndex);
                        }
                    }
                }

                result.push_back(islandObjects);
            }
        }

        return result;
    }

   
private:
    bool isInIsland(set<int> island, int object) {
        for(auto islandObject = island.begin(); islandObject != island.end(); islandObject++) {
            if (!(isTgWayExist(*islandObject, object))) {
                return false;
            }
        }

        return true;
    }

    bool isTgWayExist(int from, int to) {
        set<int> objects;
        return isTgWayExist(from, to, &objects);
    }


    bool isTgWayExist(int from, int to, set<int> *visitedObjects) {
        if (from == to) return true;

        vector<int> neighbours = findNeighbours(from);

        for(auto neighbour = neighbours.begin(); neighbour != neighbours.end(); neighbour++) {
            int edgeIndex = findEdge(from, *neighbour);
            if ((containsS(edges[edgeIndex].rules,"t") || containsS(edges[edgeIndex].rules,"g")) && !contSTAR(*neighbour,visitedObjects)) {
                visitedObjects->insert(*neighbour);
                bool isExist = isTgWayExist(*neighbour, to, visitedObjects);
                visitedObjects->erase(*neighbour);

                if (isExist) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findNeighbours(int object) {
        vector<int> neighbours;

        for(int objIndex = 0; objIndex < objectsCount; objIndex++) {
            for(auto edge = edges.begin(); edge != edges.end(); edge++) {
                int index = findEdge(object, objIndex);
                if (index != -1) {
                    neighbours.push_back(objIndex);
                    break;
                }
            }
        }

        return neighbours;
    }

    int findEdge(int obj1, int obj2) {
        for(auto edgeIndex = 0; edgeIndex < edges.size(); edgeIndex++) {
            if ((edges[edgeIndex].source == obj1 && edges[edgeIndex].toSubject == obj2) || (edges[edgeIndex].source == obj2 && edges[edgeIndex].toSubject == obj1)) {
                return edgeIndex;
            }
        }

        return -1;
    }


};

int main() {
    Graph g = Graph(4, set<int>{ 1, 2, 3 }, vector<Edge>{
        Edge(1, 2, { "r", "t" }),
        Edge(1, 3, { "w", "g" }),
        Edge(2, 0, { "r" }),
        Edge(3, 0, { "w" }),
    });




    vector<set<int>> islands = g.getIsland(); // 2 острова - 0, 1 и 2

    for(auto island = islands.begin(); island != islands.end(); island++) {
        for(auto obj = island->begin(); obj != island->end(); obj++) {
            cout << *obj << " ";
        }
        cout << endl;
    }

    return 0;
}
