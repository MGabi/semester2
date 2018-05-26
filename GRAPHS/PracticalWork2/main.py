"""
    @author: Matko Gabriel
    @email:  ytgabi98@gmail.com
    @date:   2/28/2018 08:57
"""
import traceback

from directed_graph import UndirectedGraph
from ui import UI


def main():
    graph = UndirectedGraph("graph_data.txt")
    # graph = UndirectedGraph("g_small.txt")
    #graph.showGraph()
    # for edge, neigh in graph.edgeIDs.items():
    #     print(edge, neigh)
    print("Isolated nodes: ", len(graph.isolatedNodes()))
    cmdDict = {0: UI.exitApp,
               1: UI.nrOfVertices,
               2: UI.edgeBetween,
               3: UI.inOutDegree,
               4: UI.outboundEdges,
               5: UI.inboundEdges,
               6: UI.endpointsOfEdge,
               7: UI.retriveCost,
               8: UI.modifyCost,
               9: UI.addVertex,
               10: UI.removeVertex,
               11: UI.addEdge,
               12: UI.removeEdge,
               13: UI.saveGraph,
               14: UI.findAllConnectedComponents,
               15: UI.printMenu}

    UI.printMenu()
    while True:
        try:
            cmd = UI.readCommand()
            cmdDict[cmd](graph)
        except Exception as ex:
            traceback.print_stack()
            print(ex)

main()