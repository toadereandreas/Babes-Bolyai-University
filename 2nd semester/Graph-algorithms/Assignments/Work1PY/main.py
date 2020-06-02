import random


class DictStructure:
    def __init__(self, n):
        self.dictIn = {}
        self.dictOut = {}
        self.cost = {}
        for i in range(n):
            self.dictIn[i] = []
        for i in range(n):
            self.dictOut[i] = []

    def add_Edge(self, vin, vout, cost):
        self.dictIn[vout].append(vin)
        self.dictOut[vin].append(vout)
        self.cost[(vin, vout)] = cost

    def remove_Edge(self, vin, vout):
        if vout in self.dictOut[vin]:
            self.dictOut[vin].remove(vout)
        if vout in self.dictIn[vout]:
            self.dictIn[vout].remove(vin)
        del self.cost[(vin, vout)]

    def remove_Node(self, vertex):
        for i in self.dictOut[vertex]:
            self.dictIn[i].remove(vertex)

        del self.dictOut[vertex]
        del self.dictIn[vertex]
        list = []
        for i in self.cost:
            if vertex in i:
                list.append(i)
        for i in list:
            del self.cost[i]

    def displayGraph(self):
        for i in self.cost:
            print(i, self.cost[i])

def menu():
    print(" 1. Get the number of vertices.")
    print(" 2. Verify an edge.")
    print(" 3. Get the in degree of a given vertex.")
    print(" 4. Get the out degree of a given vertex.")
    print(" 5. Get the in list.")
    print(" 6. Get the out list.")
    print(" 7. Modify the cost of an edge.")
    print(" 8. Add a new edge.")
    print(" 9. Remove an edge.")
    print("10. Add a node.")
    print("11. Remove a node.")
    print("12. Display all the edges.")
    print("13. BFS")


def run ():
    menu()
    global n
    command = int(input("Enter command >> "))
    while command:
        if command == 1:
            global n
            print(n)
        elif command == 2: #is an edge
            edge = input("Type the edge : ")
            edge = edge.split(" ")
            x = int(edge[0])
            y = int(edge[1])
            global graph
            try:
                if y in  graph.dictOut[x]:
                    print ("The edge exists.")
                else:
                    print ("The edge does not exist.")
            except:
                print("The edge does not exist.")
        elif command == 3: #in degree of a node
            node = int(input("Type node : "))
            try:
                print (len(graph.dictIn[node]))
            except:
                print("The node does not exist")
        elif command == 4: #out degree of a node
            node = int(input("Type node : "))
            try:
                print(len(graph.dictOut[node]))
            except:
                print("The node does not exist")
        elif command == 7: #modify a cost of an existing edge
            edge = input("Type the edge:")
            edge = edge.split(" ")
            (x,y) = (int(edge[0]), int(edge[1]))
            newCost = int(input("Type the new cost : "))
            if y in graph.dictOut[x]:
                graph.cost[(x, y)] = newCost
            else :
                print("The edge does not exist")
            print (graph.cost)
        elif command == 8: # add edge
            newEdge = input("Type the new edge and its cost: ")
            newEdge = newEdge.split(" ")
            try:
                if int(newEdge[1])in graph.dictOut[int(newEdge[0])]:
                    print("The edge does already exist, you can only modify the cost")
                else:
                    graph.add_Edge(int (newEdge[0]), int (newEdge[1]), int (newEdge[2]))
            except:
                print("Invalid vertices.");
            #print(graph.dictOut)
            #print(graph.dictIn)
            #print(graph.cost)
        elif command == 9: #remove an edge
            removeEdge = input("Type the edge to be removed : ")
            removeEdge = removeEdge.split(" ")
            try:

                if int(removeEdge[1])in graph.dictOut[int(removeEdge[0])]:
                    graph.remove_Edge(int(removeEdge[0]), int(removeEdge[1]))
                else:
                    print ("The edge does not exist")

            except:
                print("The edge does not exist")
        elif command == 10: #add node
            n += 1
            inp = int (input ("Type the new node"))
            if inp in graph.dictOut:
                print("The node does already exist")
            else:
                graph.dictOut[inp] = []
                graph.dictIn[inp] = []
        elif command == 11:#remove node
            try:
                node = int(input("Type node to be removed: "))
                try:
                    graph.remove_Node(node)
                    n -= 1
                    print(graph.dictOut)
                    print(graph.dictIn)
                    print(graph.cost)
                except:
                    print("The node does not exist")

            except:
                print("Node could not be found")
        elif command == 12: #display all edges
            graph.displayGraph()
        elif command == 5: # in list
            inp = int(input("Type the node : "))
            try:
                print(graph.dictIn[inp])
            except:
                print("The node does not exist")
        elif command == 6: #out list
            inp = int(input("Type the node: "))
            try:
                print(graph.dictOut[inp])
            except:
                print("The node does not exist")
        elif command == 13: #bfs1

            start = int(input ("Type the start node: "))
            end = int(input("Type the end node: "))

            try:
                bfs(start, end)
            except:
                print("Invalid input data!")

        menu()
        command = int(input("->"))

def bfs(start, end):
    visited = []
    pred = []
    for i in range(n):
        visited.append(False)
        pred.append(-1)

    q = []
    visited[start] = True
    q.append(start)
    while len(q):
        v = q[0]
        q.remove(v)
        for i in graph.dictOut[v]:
            if visited[i] == False:
                visited[i] = True
                pred[i] = v
                q.append(i)

    visited.clear()
    count = 0
    v = end
    while pred[v] != -1:
        #print (v, end = ", " )
        count += 1
        v = pred[v]
    print(start)
    print ("the length is ", count)


def read():
    contor = 0

    global graph
    global n
    global m

    with open("in.txt", "r") as file:
        raw_line = file.readlines()

    try:
        while len(raw_line) != 0:
            if contor == 0:
                line = raw_line[contor].split(" ")
                n = int(line[0])
                m = int(line[1])
                graph = DictStructure(n)

            else:
                line = raw_line[contor].split(" ")
                graph.add_Edge(int(line[0]), int(line[1]), int(line[2]))
            contor += 1
    except:
        run()

def createGraph():
    global n

    n = int(input("Enter the number of the vertices: "))
    with open("in.txt", "w") as file:
        file.write(str(n) + " ")
    edges = int(input("Type the number of edges: "))
    with open("in.txt", "a") as file:
        file.write(str(edges) + "\n")

    for i in range(edges):
        x = random.randrange(n-1)
        y = random.randrange(n-1)
        cost = random.randrange(100)
        with open("in.txt", "a") as file:
           file.write(str(x) + " " + str(y) + " " + str(cost) + "\n")
    read()

if __name__ == "__main__":
    inp = int(input("Enter 1 for reading from file or enter 2 for creating a random graph: "))
    if inp == 1:
        read()
    else:
        createGraph()

graph = DictStructure(0)
n = 0
m = 0
