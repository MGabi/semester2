"""
    @author: Matko Gabriel
    @email:  ytgabi98@gmail.com
    @date:   3/3/2018 15:53
"""
from directed_graph import DirectedGraph


class UI(object):

    def __init__(self):
        pass

    @staticmethod
    def printMenu(*args):
        print("1. Get the number of vertices")
        print("2. Find if there's an edge between two vertices")
        print("3. Get the in and out degree of a specified vertex")
        print("4. Get the outbound edges of a specified vertex")
        print("5. Get the inbound edges of a specified vertex")
        print("6. Get the endpoints of an edge specified by an EDGE_ID")
        print("7. Retrieve the information attached to an edge")
        print("8. Modify the information attached to an edge")
        print("9. Add vertex")
        print("10. Remove vertex")
        print("11. Add edge")
        print("12. Remove edge")
        print("13. Save graph")
        print("14. Print menu")
        print("0. Exit app")

    @staticmethod
    def readCommand():
        option = int(input(">>> "))
        if option not in range(0, 15):
            raise ValueError("Invalid option")

        return option

    @staticmethod
    def nrOfVertices(graph: DirectedGraph):
        print("The number of vertices is:", graph.vertices, "\n")

    @staticmethod
    def edgeBetween(graph: DirectedGraph):
        x = int(input("    vertexStart : "))
        y = int(input("    vertexIn    : "))
        if graph.vertexExists(x) and graph.vertexExists(y):
            if graph.isEdge(x, y):
                print("There is an edge!\n")
            else:
                print("There is not an edge!\n")
        else:
            print("One or both vertices does not exists!")

    @staticmethod
    def inOutDegree(graph: DirectedGraph):
        vertex = int(input("    vertex : "))
        print("OUT degree:", graph.outDegreeOf(vertex))
        print("IN degree:", graph.inDegreeOf(vertex), "\n")

    @staticmethod
    def outboundEdges(graph: DirectedGraph):
        vertex = int(input("    vertex : "))
        print("Outbound edges of {0}:".format(vertex), graph.outboundEdgesOf(vertex), "\n")

    @staticmethod
    def inboundEdges(graph: DirectedGraph):
        vertex = int(input("    vertex : "))
        print("Inbound edges of {0}:".format(vertex), graph.inboundEdgesOf(vertex), "\n")

    @staticmethod
    def endpointsOfEdge(graph: DirectedGraph):
        edgeID = int(input("    edge id : "))
        print("The endpoints of edge with ID {0} are:".format(edgeID), graph.getEndpointsOf(edgeID), "\n")

    @staticmethod
    def retriveCost(graph: DirectedGraph):
        edgeID = int(input("    edge id : "))
        print("The cost of edge with ID {0} is:".format(edgeID), graph.getCostOf(edgeID), "\n")

    @staticmethod
    def modifyCost(graph: DirectedGraph):
        edgeID = int(input("    edge id : "))
        newCost = int(input("    new cost : "))
        graph.modifyCostOf(edgeID, newCost)
        print("The new cost of {0} is {1}\n".format(edgeID, graph.getCostOf(edgeID)))

    @staticmethod
    def addVertex(graph: DirectedGraph):
        while True:
            vertex = int(input("   vertex id : "))
            if graph.vertexExists(vertex):
                print("This vertex already exists!")
            else:
                graph.addVertex(vertex)
                print("The new vertex is named ", graph.vertices)
                break

    @staticmethod
    def removeVertex(graph: DirectedGraph):
        while True:
            vertex = int(input("   vertex id : "))
            if graph.vertexExists(vertex):
                graph.removeVertex(vertex)
                print("Deletion completed")
                break
            else:
                print("This vertex does not exists!")

    @staticmethod
    def addEdge(graph: DirectedGraph):
        while True:
            vS = int(input("    starting edge : "))
            vE = int(input("    end edge : "))
            cost = int(input("      cost : "))
            id = int(input("    id : "))
            try:
                graph.addEdge(vS, vE, cost, id)
                break
            except Exception as ex:
                print(ex)

    @staticmethod
    def removeEdge(graph: DirectedGraph):
        vS = int(input("    starting edge : "))
        vE = int(input("    end edge : "))
        graph.removeEdge(vS, vE)
        print("Edge {0} -> {1} deleted!".format(vS, vE))

    @staticmethod
    def saveGraph(graph: DirectedGraph):
        with open("newGraph.txt", "w+") as f:
            for vertex in graph.verticesList:
                f.write(str(vertex) + " " + str(13graph.graphOut[vertex]) + "\n")

    @staticmethod
    def exitApp(*args):
        exit(0)
