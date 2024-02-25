class DisjointSet:  # with rank and path compression
    def __init__(self, elements):
        self.sets = [Node() for n in elements]
        self.count = len(self.sets)
        
    def find(self, element):
        return self._find(self.sets[element])
        
    def _find(self, n):
        if n.parent != n:
            # path compression
            n.parent = self._find(n.parent)
        return n.parent
        
    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        if u != v:
            # put the one with smaller rank under the other one
            if u.rank < v.rank:
                u.parent = v
            else:
                v.parent = u
                if v.rank == u.rank:
                    u.rank += 1
            self.count -= 1

    def __len__(self):
        return self.count
    
    def reset(self, element):
        return self._reset(self.sets[element])
    
    def _reset(self, n):
        if n.parent != n:
            self.count += 1
            n.parent = n
            n.rank = 0


class Node:
    def __init__(self):
        self.parent = self
        self.rank = 0
