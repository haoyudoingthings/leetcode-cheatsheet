def adj(i, j, m, n):
    """
    i, j: current position
    m, n: size of the grid
    return List[(x, y)]: x, y that are adjacent to i, j
    """
    out = []
    if i > 0:
        out.append((i-1, j))
    if j > 0:
        out.append((i, j-1))
    if i < m-1:
        out.append((i+1, j))
    if j < n-1:
        out.append((i, j+1))
    return out