"""
    @author: Matko Gabriel
    @email:  ytgabi98@gmail.com
    @date:   2/28/2018 08:57
"""
from directed_graph import DirectedGraph
from ui import UI


def main():
    graph = DirectedGraph("graph_data.txt")
    #graph.showGraph()
    # for edge, neigh in graph.edgeIDs.items():
    #     print(edge, neigh)
    cmdDict = {0: UI.exitApp,
               1: UI.nrOfVertices,
               2: UI.edgeBetween,
               3: UI.inOutDegree,
               4: UI.outboundEdges,
               5: UI.inboundEdges,
               6: UI.endpointsOfEdge,
               7: UI.retriveCost,
               8: UI.modifyCost,
               9: UI.printMenu}

    UI.printMenu()
    while True:
        try:
            cmd = UI.readCommand()
            cmdDict[cmd](graph)
        except Exception as ex:
            print(ex)

main()