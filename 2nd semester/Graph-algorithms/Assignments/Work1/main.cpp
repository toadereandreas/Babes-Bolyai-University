#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <assert.h>
using namespace std ;
ifstream fin("input.txt");

class Edge{
private:
    int vertex_in ;
    int vertex_out ;
    int cost ;
public:
    Edge( int initial_vertex_in, int initial_vertex_out, int initial_cost){
        vertex_in = initial_vertex_in ;
        vertex_out = initial_vertex_out ;
        cost = initial_cost ;
    }
    bool is_the_same( Edge other){
        if( vertex_out == other.vertex_out && vertex_in == other.vertex_in )
            return true ;
        return false;
    }
    void print_edge(){
        cout << "Vertex_in = " << vertex_in << ", vertex_out = " << vertex_out << ", cost = " << cost << ".\n";
    }
    // Getters
    const int get_vertex_in(){
        return vertex_in ;
    }
    const int get_vertex_out(){
        return vertex_out ;
    }
    const int get_cost(){
        return cost ;
    }
};

class Graph
{
private:
    int nr_vertices;
    map <int, vector<int>> In;
    map <int, vector<int>> Out;
    vector<Edge> Array_of_edges ;

public:
    Graph( int vertex ){
        // This is the constructor of the class.
        nr_vertices = vertex;
    }
    const int get_number_of_vertices(){
        // This function returns the current number of vertices of the graph.
        return nr_vertices ;
    }
    std::vector<int>::iterator In_begin_itr( int vertex ){
        // This function returns an iterator to the first element of the inbound elements.
        return In[vertex].begin();
    }
    std::vector<int>::iterator In_end_itr( int vertex ){
        // This function returns an iterator to the last element of the inbound elements.
        return In[vertex].end();
    }
    std::vector<int>::iterator Out_begin_itr( int vertex ){
        // This function returns an iterator to the first element of the outbound elements.
        return Out[vertex].begin();
    }
    std::vector<int>::iterator Out_end_itr( int vertex ){
        // This function returns an iterator to the last element of the outbound elements.
        return Out[vertex].end();
    }
    bool exists_Edge(Edge the_edge){
        /* This is a boolean functiont that returns whether a given edge exists in the graph.
         * If it exists it returns true.
         * If not, it returns false. */
        for( Edge e: Array_of_edges ) {
            if( e.is_the_same(the_edge) )
                return true;
        }
        return false ;
    }
    void add_edge(Edge new_edge){
        /* This function adds an edge to the graph.
         * Firstly, it cheks whether the edge exists or not.
         * If it does, is displays on the screen a message and does not add it to the graph.
         * Otherwise, it adds it to the graph. */
        if( exists_Edge(new_edge) )
            cout << "The edge (" << new_edge.get_vertex_in() << ',' << new_edge.get_vertex_out() << ") already exists.\n" ;
        else {
            In[new_edge.get_vertex_in()];
            In[new_edge.get_vertex_in()].push_back(new_edge.get_vertex_out());
            Out[new_edge.get_vertex_out()];
            Out[new_edge.get_vertex_out()].push_back(new_edge.get_vertex_in());
            Array_of_edges.push_back(new_edge);
            cout << "The addition of the edge (" << new_edge.get_vertex_in() << ',' << new_edge.get_vertex_out() <<") was successful.\n" ;
        }
    }
    bool check_edge( int out_vertex, int in_vertex){
        /* This function checks if there is an edge from out_vertex to in_vertex.
         * If there is one, the function returns true.
         * If not, it returns false. */
        Edge fake_Edge = Edge(out_vertex,in_vertex,0);
        return exists_Edge(fake_Edge);
    }
    bool valid_vertex( int vertex){
        // This funtion cheks whether the given vertex is valid or not.
        return vertex > 0 && vertex <= nr_vertices ;
    }
    int get_in_degree( int vertex){
        /* This function returns the in degree of the given vertex.
         * If the vertex is not valid, it returns -1. */
        if( valid_vertex(vertex) )
            return In[vertex].size();
        else return -1;
    }
    int get_out_degree( int vertex){
        /* This function returns the out degree of the given vertex.
         * If the vertex is not valid, it returns -1. */
        if( valid_vertex(vertex) )
            return Out[vertex].size();
        else return -1;
    }
    void modify_cost_of_edge( int vertex_in, int vertex_out, int new_cost){
        // This function modifies the cost of a given edge.
        Edge the_Edge = Edge(vertex_in,vertex_out,new_cost);
        int position = 0 ;
        for( Edge e: Array_of_edges ) {
            if( e.is_the_same(the_Edge) )
                break;
            ++position ;
        }
        Array_of_edges.erase(Array_of_edges.begin()+position) ;
        Array_of_edges.push_back(the_Edge);
    }
    void add_vertex( int new_Vertex){
        // This function adds a vertex.
        In[new_Vertex]  ;
        Out[new_Vertex] ;
        ++nr_vertices ;
    }
    bool exists_vertex( int the_Vertex){
        // This function checks whether a vertex exists or not.
        cout << "Vertex " << the_Vertex << " In: " << ( In.find(the_Vertex) != In.end() ) << ", Out: " << ( Out.find(the_Vertex) != Out.end() ) << "\n";
        return ( In.find(the_Vertex) != In.end() && Out.find(the_Vertex) != Out.end() );
    }
    void remove_vertex( int the_Vertex){
        // This function removes a vertex.
        In.erase(the_Vertex);
        Out.erase(the_Vertex);
        for( int y = 0 ; y < 10 ; ++y ) {
            int pos = 0 ;
            for (auto x: Array_of_edges) {
                if (x.get_vertex_in() == the_Vertex) {
                    Array_of_edges.erase(Array_of_edges.begin() + pos);
                    --pos;
                }
                if (x.get_vertex_out() == the_Vertex) {
                    Array_of_edges.erase(Array_of_edges.begin() + pos);
                    --pos;
                }
                ++pos;
            }
        }
        --nr_vertices ;
    }
    void remove_edge( int vertex_in, int vertex_out ){
        // This function removes an edge based on a given vertex_in and vertex_out.
        Edge the_Edge = Edge(vertex_in, vertex_out, 0);
        int position = 0 ;
        for( Edge e: Array_of_edges ) {
            if( e.is_the_same(the_Edge) )
                break;
            ++position ;
        }
        Array_of_edges.erase(Array_of_edges.begin()+position) ;
        //-------
        auto it = In.find(vertex_in) ;
        int in_position = 0;
        for( auto itr = it->second.begin() ; itr != it->second.end() ; ++itr ){
            if( *itr == vertex_out )
                break ;
            ++in_position;
        }
        it->second.erase(it->second.begin()+in_position);
        In.erase(it);
    }
    void print_edges(){
        // This function prints all the edges of the graph.
        for( Edge e: Array_of_edges )
            e.print_edge();
    }
    Edge get_edge_by_pos( int pos ){
        // This function returns the edge from the position pos in the array of edges.
        int position = 0;
        for( auto Edge: Array_of_edges ){
            if( position == pos )
                return Edge;
            ++position;
        }
    }
    int return_Array_of_edges_size(){
        // This function returns the size of the Array_of_edges.size();
        return Array_of_edges.size();
    }
    int return_cost_of_edge( int vertex_in, int vertex_out){
        // This function returns the cost of an edge given by its in vertex and out vertex.
        for( auto Edge: Array_of_edges ){
            if( Edge.get_vertex_in() == vertex_in && Edge.get_vertex_out() == vertex_out )
                return Edge.get_cost() ;
        }
    }
};

void ui_help(){
    std::cout << "-1. Exit.\n";
    std::cout << " 0. Help.\n";
    std::cout << " 1. Get number of vertices.\n" ;
    std::cout << " 2. Parse set of vertices.\n" ;
    std::cout << " 3. Check if there is an edge between 2 vertices.\n" ;
    std::cout << " 4. Get the in and out degree of a specified vertex.\n" ;
    std::cout << " 5. Parse the set of outbound edges of a given vertex.\n"
                 "    Parse the set of inbound edges of a given vertex.\n" ;
    std::cout << " 6. Get the end points of an edge specified via id.\n" ;
    std::cout << " 7. Modify cost of an edge.\n" ;
    std::cout << " 8. Get cost of an edge.\n" ;
    std::cout << " 9. Add new edge.\n";
    std::cout << "10. Print all edges.\n";
    std::cout << "11. Delete edge.\n";
    std::cout << "12. Add vertex.\n";
    std::cout << "13. Delete vertex.\n";
}

int main() {
    /* --------- READ FROM FILE ---------
    ofstream my_file ;
    my_file.open("input.txt");
    cout << my_file.bad();
    int vertices_number, edge_number, vertex_in, vertex_out, edge_cost ;
    fin >> vertices_number >> edge_number ;
    Graph G = Graph(vertices_number);
    for( int i = 0 ; i < edge_number ; ++i )
    {
        fin >> vertex_in >> vertex_out >> edge_cost ;
        Edge new_Edge = Edge(vertex_in,vertex_out,edge_cost);
        G.add_edge(new_Edge) ;
    }
    my_file.close();
    */
    Graph G = Graph(10);
    Edge new_Edge = Edge(1,2,10);
    G.add_edge(new_Edge);
    new_Edge = Edge(1,6,10);
    G.add_edge(new_Edge);
    new_Edge = Edge(2,7,10);
    G.add_edge(new_Edge);
    new_Edge = Edge(3,9,10);
    G.add_edge(new_Edge);
    new_Edge = Edge(1,6,10);
    G.add_edge(new_Edge);
    while(true){
        int command;
        std::cout << "Select command. Enter 0 to print all possible commands >> ";
        cin >> command;
        if( command == 0 )
            ui_help();
        else if( command == -1)
            return 0;
        else if( command == 1 )
            std:: cout << "Number of vertices are: " << G.get_number_of_vertices() << ".\n";
        else if( command == 2 ){
            int vertices_set[100];
            for (int i = 1; i <= G.get_number_of_vertices(); ++i)
                vertices_set[i] = i ;
            std::cout << "The set of vertices is: [" ;
            for (int i = 1; i < G.get_number_of_vertices(); ++i)
                std::cout << vertices_set[i] << ",";
            std::cout << vertices_set[G.get_number_of_vertices()] << "]\n" ;
        }
        else if( command == 3 ){
            std::cout << "Enter 2 integers, <vertex_in> and <vertex_out> to check if there is an edge between them>> ";
            int vin, vout;
            std::cin >> vin >> vout ;
            if( G.check_edge(vin,vout) )
                std::cout << "There is an edge between " << vin << " and " << vout << ".\n" ;
            else
                std::cout << "There is not an edge between " << vin << " and " << vout << ".\n" ;
        }
        else if( command == 4 ){
            int v;
            std::cout << "Specify the vertex, as an integer: ";
            std::cin >> v ;
            std::cout << "The in degree of " << v << " is: " << G.get_in_degree(v) << " and the out degree is: " << G.get_out_degree(v) << ".\n";
        }
        else if( command == 5 ){
            int v;
            std::cout << "Specify the vertex, as an integer: ";
            std::cin >> v ;
            std::cout << "The list of inbound edges is: " ;
            for( std::vector<int>::iterator it = G.In_begin_itr(v) ; it != G.In_end_itr(v) ; ++it )
                std::cout << (*it) << " ";
            std::cout << "\nThe list of outbound edges is: " ;
            for( std::vector<int>::iterator it = G.Out_begin_itr(v) ; it != G.Out_end_itr(v) ; ++it )
                std::cout << (*it) << " ";
            std::cout << "\n" ;
        }
        else if( command == 6 ){
            int id;
            std::cout << "Specify the id of the edge, as an integer: ";
            std::cin >> id;
            if( id < 0 || id >= G.return_Array_of_edges_size() )
                std::cout << "Invalid edge id!\n";
            else {
                Edge the_edge = G.get_edge_by_pos(id);
                the_edge.print_edge();
            }
        }
        else if( command == 7 ){
            int vin, vout, newvalue ;
            std::cout << "Specify the <vertex_in>, <vertex_out> and <new_cost> as integers:" ;
            std::cin >> vin >> vout >> newvalue ;
            if( G.check_edge(vin,vout) ) {
                G.modify_cost_of_edge(vin, vout, newvalue);
                std::cout << "The edge was successfully updated.\n";
            }
            else
                std::cout << "Invalid edge vertices! The edge does not exist!\n";
        }
        else if( command == 8 ){
            int vin, vout ;
            std::cout << "Specify the <vertex_in> and <vertex_out> as integers:" ;
            std::cin >> vin >> vout ;
            if( G.check_edge(vin,vout) ) {
                Edge the_edge = Edge(vin,vout,0);
                cout << "The cost is: " << G.return_cost_of_edge(vin,vout) << ".\n";
            }
            else
                std::cout << "Invalid edge vertices! The edge does not exist!\n";
        }
        else if( command == 9 ){
            int vin, vout, cost;
            std::cout << "Specify the <vertex_in>, <vertex_out> and <new_cost> as integers:" ;
            std::cin >> vin >> vout >> cost ;
            Edge new_Edge = Edge(vin,vout,cost) ;
            G.add_edge(new_Edge);
        }
        else if( command == 10 ){
            std::cout << "The edges are :\n";
            G.print_edges();
        }
        else if( command == 11 ){
            std::cout << "Specify the edge by giving its <vertex_in> and <vertex_out>, as integers:\n";
            int vin, vout;
            std::cin >> vin >> vout ;
            if( G.check_edge(vin,vout) ) {
                G.remove_edge(vin, vout);
                std::cout << "The edge was successfully removed.\n";
            } else
                std::cout << "Invalid edge. The given edge does not exist!\n";
        }
        else if( command == 12 ){
            std::cout << "Enter new vertex :" ;
            int v = 0;
            G.add_vertex(v);
            std::cout << "Vertex was added.\n";
        }
        else if( command == 13 ){
            std::cout << "Enter the vertex you want to delete :";
            int v ;
            std::cin >> v ;
            G.remove_vertex(v);
            std::cout << "The vertex was successfully removed.\n";
        }
    }
}