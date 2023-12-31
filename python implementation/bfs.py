# BFS, Breadth-First Search, is a vertex-based technique for finding the shortest path in the graph. 
# It uses a Queue data structure that follows first in first out. 
# In BFS, one vertex is selected at a time when it is visited and marked then its adjacent are visited and stored in the queue.


graph = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}


visited = []    # store the visited node of the graph 
queue = []      # storing the nodes in the queue

def bfs(visited, graph, node):
    visited.append(node)
    queue.append(node)
    
    # Creating loop to visit each node
    while queue:
        m = queue.pop(0)
        print(m, end =" ")
    
        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)
                
print("Following is the Breadth-First Search")
bfs(visited, graph, '5')    # function calling
            
