"""
    a -- b
    |    |
    c -- d  -- e
"""
def showEdges(graph):
    edges=[]
    for vertex in graph:
        for everyConnectedVertex in graph[vertex]:
            if {everyConnectedVertex, vertex} not in edges:
                edges.append({vertex,everyConnectedVertex})
                print(vertex + " - " + everyConnectedVertex)
    # return edges
if __name__ == '__main__':
    # print "hello forhad from main"
    graph = {
        "a": ["b", "c"],
        "b": ["a", "d"],
        "c": ["a", "d"],
        "d": ["e"],
        "e": ["d"]
    }
    print "========= GRAPH ========="
    print graph
    print("========== VERTICES ============")
    print graph.keys()
    print("=========== EDGES =======")
    # print showEdges(graph)
    showEdges(graph)