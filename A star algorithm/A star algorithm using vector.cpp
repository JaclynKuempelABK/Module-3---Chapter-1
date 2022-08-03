#include <iostream>
#include <vector>
#include <queue>

/*
using std::cout;
using std::cin;
using std::endl;
using std::vector;*/
using namespace std;

struct Vertex
{
    char x;
    char y;
    int cost;
    int heur; // heuristic

    Vertex()
        : x('a')
        , y('b')
        , cost(1)
    {}

    Vertex(char xParameter, char yParameter, int distParameter)
        : x(xParameter)
        , y(yParameter)
        , cost(distParameter)
    {}

    Vertex(char xParameter, char yParameter, int distParameter, int heurParameter)
        : x(xParameter)
        , y(yParameter)
        , cost(distParameter)
        , heur(heurParameter)
    {}
};

// allows for sorting of Vertex elements within a data structure
struct greater_than_dist
{
    inline bool operator() (const Vertex& struct1, const Vertex& struct2)
    {
        return (struct1.cost > struct2.cost);
    }
};

int aStarPathfind(vector<Vertex>& graph, char source, char destination);
// void printVector(vector<Vertex>& stash); // TODO: REMOVE, THIS IS JUST FOR TESTING


int main()
{

    vector<Vertex> graph;

    // populate map
    graph.push_back(Vertex('a', 'b', 5, 0));
    graph.push_back(Vertex('b', 'c', 1, 0));
    graph.push_back(Vertex('a', 'd', 7, 0));
    graph.push_back(Vertex('c', 'd', 1, 0));


    // path request
    char start = 'a';
    char end = 'b';
    int shortestDist = aStarPathfind(graph, start, end);
    cout << "The shortest path between " << start << " and " << end << " is " << shortestDist << endl;    
}

void printVector(vector<Vertex>& stash)
{
    for (Vertex vertex : stash)
    {
        cout << vertex.x << ", " << vertex.y << ", " << vertex.cost << endl;
    }

    cout << endl;
}

int aStarPathfind(vector<Vertex>& graph, char source, char destination)
{
    /*
    // create vertex priority queue Q
    vector<Vertex> stash;

    // TODO: fill graph in with all existing letters (make sure not already inserted)
    for (int i = 0; i < graph.size(); i++)
    {


        for (int j = 0; j < stash.size(); j++)
        {
            if ((graph[i].x != stash[j].x) || (graph[i].y != stash[j].x))
            {

            }
        }



        // also initialize each dist and prev, using the if statement you see below
        // probably use like push_back
    }

//     if v == source
//          dist[v] <- 0
//          prev[v] <- UNDEFINED
//      if v ≠ source
//          dist[v] ← INFINITY                 // Unknown distance from source to v
//          prev[v] ← UNDEFINED                // Predecessor of v   

  
    // sort stash
    sort(stash.begin(), stash.end(), greater_than_dist());

    */

    vector<Vertex> stash;
    // TODO: this is the manual stash population method, switch to automatic
    stash.push_back(Vertex('d', ' ', 100000));
    stash.push_back(Vertex('c', ' ', 100000));
    stash.push_back(Vertex('b', ' ', 100000));
    stash.push_back(Vertex('a', ' ', 0));

    Vertex vertex = Vertex();
    Vertex neighborInGraph = Vertex();
    Vertex neighborInStash = Vertex();
    int newDist = 0;

    //cout << "stash:" << endl;
    //printVector(stash);

    while (!stash.empty())
    {

        // popping off smallest number in stash (i.e. the last element) AND making it the current vertex
        vertex = stash.back();
        stash.pop_back();
       

        for (int i = 0; i < graph.size(); i++) // traverse graph to find neighbors of vertex
        {

            if (graph[i].x == vertex.x) // neighbor found in graph
            {

                // find corresponding neighbor in stash now
                for (int j = 0; j < stash.size(); j++)
                {
                    
                    if (graph[i].y == stash[j].x) // neighbor from graph found in stash
                    {
                        if (vertex.cost == 100000) // "== infinity"
                        {
                            newDist = graph[i].cost + graph[i].heur;
                        }
                        else
                        {
                            newDist = vertex.cost + graph[i].cost + graph[i].heur;
                        }
                        
                        //cout << "newDist: " << newDist << endl;
                        if (newDist < stash[j].cost)
                        {

                            stash[j].cost = newDist;
                            stash[j].y = vertex.x;
                            sort(stash.begin(), stash.end(), greater_than_dist()); // keep stash sorted in descending order


                            //cout << "stash:" << endl;
                            //printVector(stash);
                        }

                        
                        
                    }
                }
            }
        }
        

        //WHEN FOUND DESTINATION THEN RETURN DIST...
        if (!stash.empty() && stash.back().x == destination)
        {
            return stash.back().cost;
        }

    }

    return 0;
}