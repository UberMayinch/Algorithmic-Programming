
import sys

MOD = 1000000007

dxy = [(-1, 0), (0, -1), (1, 0), (0, 1)]

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        G = [[] for _ in range(n)]
        edgesSet = set()  
        flag = False
        queries = 15 * n
        prev_query = n
        edges = [0] * n
        node = 0
        idx = 1
        
        while queries and not flag:
            found = False
            query = prev_query

            
            while not found and queries:
           
                if query == idx:
                    prev_query = query  
                    query = node  
                    continue
                
                sys.stdout.write(f"? {idx} {query}\n")
                sys.stdout.flush()
                queries -= 1
                node = int(input().strip())

                
                if node == idx:
                    found = True
                    G[idx-1].append(query)
                    edges[idx-1] = 1
                    edgesSet.add(tuple(sorted([idx, query])))
                    break
                else:
                    prev_query = query
                    query = node

               
                if query == idx or queries == 0:
                    break


            if all(e == 1 for e in edges):
                flag = True
            else:

                try:
                    idx = edges.index(0) + 1
                except ValueError:

                    break


        sys.stdout.write("! ")
        sys.stdout.flush()
        for edge in edgesSet:
            sys.stdout.write(f"{edge[0]} {edge[1]} ")
            sys.stdout.flush()
        sys.stdout.flush()

if __name__ == "__main__":
    main()
