import sys

class Graph(object):
    
    def __init__(self, nodes, init_graph):
        
        self.nodes = nodes
        self.graph = self.construct_graph(nodes, init_graph)
        
    def construct_graph(self, nodes, init_graph):                   # makes sure that the graph is symmetrical
        
        graph = {}
        for node in nodes:
            graph[node] = {}
            
        graph.update(init_graph)
        
        for node, edges in graph.items():
            for adjacent_node, value in edges.items():
                if graph[adjacent_node].get(node, False) == False:
                    graph[adjacent_node][node] = value
                    
        return graph
    
    def get_nodes(self):                 # returns nodes of the graph
        return self. nodes
    
    def get_outgoing_edges(self, node):     # returns neighbors of node
        connections = []
        for outgoing_node in self.nodes:
            if self.graph[node].get(outgoing_node, False) != False:
                connections.append(outgoing_node)
        return connections
    
    def value(self, node1, node2):              # Returns the value of an edge between two nodes
        return self.graph[node1][node2]
        
        
        
def dijkstra_algorithm(graph, start_node):
    unvisited_nodes = list(graph.get_nodes())
    shortest_path = {}
    previous_nodes = {}
    
    max_value = sys.maxsize
    for node in unvisited_nodes:
        shortest_path[node] = max_value
    
    shortest_path[start_node] = 0
    
    while unvisited_nodes:
        current_min_node = None
        for node in unvisited_nodes:
            if current_min_node == None:
                current_min_node = node
            elif shortest_path[node] < shortest_path[current_min_node]:
                current_min_node = node
            
        neighbours = graph.get_outgoing_edges(current_min_node)
        for neighbour in neighbours:
            tentative_value = shortest_path[current_min_node] + graph.value(current_min_node, neighbour)
            if tentative_value < shortest_path[neighbour]:
                shortest_path[neighbour] = tentative_value
                previous_nodes[neighbour] = current_min_node
                
                
        unvisited_nodes.remove(current_min_node)
        
    return previous_nodes, shortest_path

def print_result(previous_nodes, shortest_path, start_node, target_node):
    path = []
    node = target_node
    
    while node != start_node:
        path.append(node)
        node = previous_nodes[node]
 
    # Add the start node manually
    path.append(start_node)
    
    print("We found the following best path with a value of {}.".format(shortest_path[target_node]))
    print(" -> ".join(reversed(path)))
        
        

if __name__ == "__main__":
    nodes = ["Reykjavik", "Oslo", "Moscow", "London", "Rome", "Berlin", "Belgrade", "Athens"]
 
    init_graph = {}
    for node in nodes:
        init_graph[node] = {}
    
    init_graph["Reykjavik"]["Oslo"] = 5
    init_graph["Reykjavik"]["London"] = 4
    init_graph["Oslo"]["Berlin"] = 1
    init_graph["Oslo"]["Moscow"] = 3
    init_graph["Moscow"]["Belgrade"] = 5
    init_graph["Moscow"]["Athens"] = 4
    init_graph["Athens"]["Belgrade"] = 1
    init_graph["Rome"]["Berlin"] = 2
    init_graph["Rome"]["Athens"] = 2

    graph = Graph(nodes, init_graph)
    previous_nodes, shortest_path = dijkstra_algorithm(graph=graph, start_node="Reykjavik")

    print_result(previous_nodes, shortest_path, start_node="Reykjavik", target_node="Belgrade")

        
     
    
    
            
            