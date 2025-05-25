#include <iostream>  
#include <vector>  
  
// defining constant  
#define MAX_INT 10000000  
  
// using the standard namespace   
using namespace std;  
  
// prototyping of the DijkstraAlgorithm() function  
void DijkstraAlgorithm();  
  
// main function  
int main() {  
  DijkstraAlgorithm();  
  return 0;  
}  
  
// declaring the classes  
class Vertex;  
class Edge;  
  
// prototyping the functions  
void Dijkstra();  
vector<Vertex*>* Adjacent_Remaining_Nodes(Vertex* vertex);  
Vertex* Extract_Smallest(vector<Vertex*>& vertices);  
int Distance(Vertex* vertexOne, Vertex* vertexTwo);  
bool Contains(vector<Vertex*>& vertices, Vertex* vertex);  
void Print_Shortest_Route_To(Vertex* des);  
  
// instantiating the classes  
vector<Vertex*> vertices;  
vector<Edge*> edges;  
  
// defining the class for the vertices of the graph  
class Vertex {  
   public:  
  Vertex(char id)  
    : id(id), prev(NULL), distance_from_start(MAX_INT) {  
    vertices.push_back(this);  
  }  
  
   public:  
  char id;  
  Vertex* prev;  
  int distance_from_start;  
};  
  
// defining the class for the edges of the graph  
class Edge {  
  public:  
    Edge(Vertex* vertexOne, Vertex* vertexTwo, int distance)  
    : vertexOne(vertexOne), vertexTwo(vertexTwo), distance(distance) {  
    edges.push_back(this);  
  }  
  bool Connects(Vertex* vertexOne, Vertex* vertexTwo) {  
    return (  
      (vertexOne == this->vertexOne &&  
       vertexTwo == this->vertexTwo) ||  
      (vertexOne == this->vertexTwo &&  
       vertexTwo == this->vertexOne));  
  }  
  
  public:  
    Vertex* vertexOne;  
    Vertex* vertexTwo;  
    int distance;  
};  
  
// defining the function to collect the details of the graph  
void DijkstraAlgorithm() {  
  // declaring some vertices  
  Vertex* vertex_a = new Vertex('A');  
  Vertex* vertex_b = new Vertex('B');  
  Vertex* vertex_c = new Vertex('C');  
  Vertex* vertex_d = new Vertex('D');  
  Vertex* vertex_e = new Vertex('E');  
  Vertex* vertex_f = new Vertex('F');  
  Vertex* vertex_g = new Vertex('G');  
  
  // declaring some edges  
  Edge* edge_1 = new Edge(vertex_a, vertex_c, 1);  
  Edge* edge_2 = new Edge(vertex_a, vertex_d, 2);  
  Edge* edge_3 = new Edge(vertex_b, vertex_c, 2);  
  Edge* edge_4 = new Edge(vertex_c, vertex_d, 1);  
  Edge* edge_5 = new Edge(vertex_b, vertex_f, 3);  
  Edge* edge_6 = new Edge(vertex_c, vertex_e, 3);  
  Edge* edge_7 = new Edge(vertex_e, vertex_f, 2);  
  Edge* edge_8 = new Edge(vertex_d, vertex_g, 1);  
  Edge* edge_9 = new Edge(vertex_g, vertex_f, 1);  
  
  vertex_a -> distance_from_start = 0;  // setting a start vertex  
  
  // calling the Dijkstra() function to find the shortest route possible  
  Dijkstra();  
  
  // calling the Print_Shortest_Route_To() function to print the shortest route from the source vertex to the destination vertex  
  Print_Shortest_Route_To(vertex_f);  
}  
  
// defining the function for Dijkstra's Algorithm  
void Dijkstra() {  
  while (vertices.size() > 0) {  
    Vertex* smallest = Extract_Smallest(vertices);  
    vector<Vertex*>* adjacent_nodes =  
      Adjacent_Remaining_Nodes(smallest);  
  
    const int size = adjacent_nodes -> size();  
    for (int i = 0; i < size; ++i) {  
      Vertex* adjacent = adjacent_nodes -> at(i);  
      int distance = Distance(smallest, adjacent) +  
               smallest -> distance_from_start;  
  
      if (distance < adjacent -> distance_from_start) {  
        adjacent -> distance_from_start = distance;  
        adjacent -> prev = smallest;  
      }  
    }  
    delete adjacent_nodes;  
  }  
}  
  
// defining the function to find the vertex with the shortest distance, removing it, and returning it  
Vertex* Extract_Smallest(vector<Vertex*>& vertices) {  
  int size = vertices.size();  
  if (size == 0) return NULL;  
  int smallest_position = 0;  
  Vertex* smallest = vertices.at(0);  
  for (int i = 1; i < size; ++i) {  
    Vertex* current = vertices.at(i);  
    if (current -> distance_from_start <  
      smallest -> distance_from_start) {  
      smallest = current;  
      smallest_position = i;  
    }  
  }  
  vertices.erase(vertices.begin() + smallest_position);  
  return smallest;  
}  
  
// defining the function to return all vertices adjacent to 'vertex' which are still in the 'vertices' collection.  
vector<Vertex*>* Adjacent_Remaining_Nodes(Vertex* vertex) {  
  vector<Vertex*>* adjacent_nodes = new vector<Vertex*>();  
  const int size = edges.size();  
  for (int i = 0; i < size; ++i) {  
    Edge* edge = edges.at(i);  
    Vertex* adjacent = NULL;  
    if (edge -> vertexOne == vertex) {  
      adjacent = edge -> vertexTwo;  
    } else if (edge -> vertexTwo == vertex) {  
      adjacent = edge -> vertexOne;  
    }  
    if (adjacent && Contains(vertices, adjacent)) {  
      adjacent_nodes -> push_back(adjacent);  
    }  
  }  
  return adjacent_nodes;  
}  
  
// defining the function to return distance between two connected vertices  
int Distance(Vertex* vertexOne, Vertex* vertexTwo) {  
  const int size = edges.size();  
  for (int i = 0; i < size; ++i) {  
    Edge* edge = edges.at(i);  
    if (edge -> Connects(vertexOne, vertexTwo)) {  
      return edge -> distance;  
    }  
  }  
  return -1;  // should never happen  
}  
  
// defining the function to check if the 'vertices' vector contains 'vertex'  
bool Contains(vector<Vertex*>& vertices, Vertex* vertex) {  
  const int size = vertices.size();  
  for (int i = 0; i < size; ++i) {  
    if (vertex == vertices.at(i)) {  
      return true;  
    }  
  }  
  return false;  
}  
  
// defining the function to print the shortest route to the destination  
void Print_Shortest_Route_To(Vertex* des) {  
  Vertex* prev = des;  
  cout << "Distance from start: "  
     << des -> distance_from_start << endl;  
  while (prev) {  
    cout << prev -> id << " ";  
    prev = prev -> prev;  
  }  
  cout << endl;  
}  
