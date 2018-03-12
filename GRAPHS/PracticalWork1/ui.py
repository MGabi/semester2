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
        print("9. Print menu")
        print("0. Exit app")

    @staticmethod
    def readCommand():
        option = int(input(">>> "))
        if option not in range(0, 10):
            raise ValueError("Invalid option")

        return option

    @staticmethod
    def nrOfVertices(graph: DirectedGraph):
        print("The number of vertices is:", graph.vertices, "\n")

    @staticmethod
    def edgeBetween(graph: DirectedGraph):
        x = int(input("    vertexStart : "))
        y = int(input("    vertexIn    : "))
        if graph.isEdge(x, y):
            print("There is an edge!\n")
        else:
            print("There is not an edge!\n")

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
    def exitApp(*args):
        exit(0)
