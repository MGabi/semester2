"""
    @author: Matko Gabriel
    @email:  ytgabi98@gmail.com
    @date:   2/28/2018 08:38

Requirements:
    DONE - get the number of vertices;
    DONE - given two vertices, find out whether there is an edge from the first one to the second one, and retrieve the Edge_id if there is an edge (the latter is not required if an edge is represented simply as a pair of vertex identifiers);
    DONE - get the in degree and the out degree of a specified vertex;
    DONE - iterate through the set of outbound edges of a specified vertex (that is, provide an iterator). For each outbound edge, the iterator shall provide the Edge_id of the curren edge (or the target vertex, if no Edge_id is used).
    DONE - iterate through the set of inbound edges of a specified vertex (as above);
    DONE - get the endpoints of an edge specified by an Edge_id (if applicable);
    DONE - retrieve or modify the information (the integer) attached to a specified edge.
"""
from copy import deepcopy

import matplotlib.pyplot as plt
import networkx as nx
import numpy


class DirectedGraph(object):

    def __init__(self, fileName):
        self.__vertices = 0
        self.__verticesList = []
        self.__edges = 0
        self.__graphIn = {}
        self.__graphOut = {}
        self.__costs = {}
        self.__edgeIDs = {}
        self.readGraph(fileName)

    @property
    def verticesList(self):
        return self.__verticesList

    @property
    def vertices(self):
        return self.__vertices

    @vertices.setter
    def vertices(self, increment):
        self.__vertices += increment

    @property
    def edges(self):
        return len(self.__costs)

    @property
    def graphIn(self):
        return self.__graphIn

    @property
    def graphOut(self):
        return self.__graphOut

    @property
    def costs(self):
        return self.__costs

    @property
    def edgeIDs(self):
        return self.__edgeIDs

    def readGraph(self, fileName):
        id = 0
        with open(fileName, "r") as graph:
            line = graph.readline().split()
            self.__vertices = int(line[0])
            self.__verticesList = [el for el in range(self.__vertices)]
            for i in range(0, self.__vertices):
                self.graphOut[i] = []
                self.graphIn[i] = []

            self.__edges = int(line[1])

            for i in range(0, self.__vertices):
                self.__graphIn[i] = []
                self.__graphOut[i] = []

            try:
                line = graph.readline().split()
                while line != []:
                    edge = Edge(int(line[0]), int(line[1]), int(line[2]), id)
                    id += 1
                    self.addEdge(edge.x, edge.y, edge.cost, edge.ID)
                    line = graph.readline().split()

            except EOFError as eof:
                graph.close()
            except Exception as ex:
                print(ex)


    def addEdge(self, vertexStart, vertexEnd, cost, id):
        if self.vertexExists(vertexStart) and self.vertexExists(vertexEnd):
            if not self.isEdge(vertexStart, vertexEnd):
                if id not in self.__edgeIDs.keys():
                    self.__graphOut[vertexStart].append(vertexEnd)
                    self.__graphIn[vertexEnd].append(vertexStart)
                    self.__costs[vertexStart, vertexEnd] = cost
                    self.__edgeIDs[id] = [vertexStart, vertexEnd]
                else:
                    raise Exception("ID {0} already exists!".format(id))
            else:
                raise Exception("Edge {0} -> {1} already exists!".format(vertexStart, vertexEnd))
        else:
            raise Exception("One or both vertices does not exists!")

    def removeEdge(self, vertexStart, vertexEnd):
        if self.isEdge(vertexStart, vertexEnd):
            self.__graphOut[vertexStart].remove(vertexEnd)
            self.__graphIn[vertexEnd].remove(vertexStart)
            #del self.__costs[vertexStart, vertexEnd]
            self.__costs.pop(vertexStart, vertexEnd)

            for id, edge in self.__edgeIDs.copy().items():
                if edge == [vertexStart, vertexEnd]:
                    self.__edgeIDs.pop(id)
                    #del self.__edgeIDs[id]

        else:
            raise Exception("Edge {0} -> {1} does not exists!".format(vertexStart, vertexEnd))

    def getCostOf(self, edgeID):
        if self.edgeIDExists(edgeID):
            return self.__costs[tuple(self.__edgeIDs[edgeID])]
        else:
            raise Exception("Edge with id {0} does not exists!".format(edgeID))

    def modifyCostOf(self, edgeID, newCost):
        if self.edgeIDExists(edgeID):
            self.__costs[tuple(self.__edgeIDs[edgeID])] = newCost
        else:
            raise Exception("Edge with id {0} does not exists!".format(edgeID))

    def getEndpointsOf(self, edgeID):
        if self.edgeIDExists(edgeID):
            return self.__edgeIDs[edgeID]
        else:
            raise Exception("Edge with id {0} does not exists!".format(edgeID))


    def edgeIDExists(self, edgeID):
        return edgeID in self.__edgeIDs.keys()

    def isEdge(self, vertexStart, vertexEnd):
        return vertexEnd in self.__graphOut[vertexStart]

    def inDegreeOf(self, vertex):
        return len(self.__graphIn[vertex])

    def outDegreeOf(self, vertex):
        return len(self.__graphOut[vertex])

    def vertexExists(self, vertex):
        return vertex in self.verticesList

    def outboundEdgesOf(self, vertex):
        return self.__graphOut[vertex]

    def inboundEdgesOf(self, vertex):
        return self.__graphIn[vertex]

    def showGraph(self):
        g = nx.DiGraph()

        for k, v in self.__graphOut.items():
            for el in v:
                g.add_edge(k, el)

        nx.draw(g, with_labels=True)
        plt.draw()
        plt.show()

    def isolatedNodes(self):
        isolated = []
        for el in range(self.vertices):
            if self.graphIn[el] == [] and self.graphOut[el] == []:
                isolated.append(el)
        return isolated

    def addVertex(self, vertex):
        self.graphIn[vertex] = []
        self.graphOut[vertex] = []
        self.vertices = 1
        self.verticesList.append(vertex)

    def removeVertex(self, vertex):
        self.verticesList.remove(vertex)
        self.graphOut.pop(vertex)
        self.graphIn.pop(vertex)
        self.vertices = -1

class Edge(object):

    def __init__(self, x, y, cost, ID):
        self.__x = x
        self.__y = y
        self.__cost = cost
        self.__ID = ID

    @property
    def x(self):
        return self.__x

    @property
    def y(self):
        return self.__y

    @property
    def cost(self):
        return self.__cost

    @property
    def ID(self):
        return self.__ID