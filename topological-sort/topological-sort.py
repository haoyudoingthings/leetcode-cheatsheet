from collections import deque
def topological_sort(lst, pred, succ):
    # lst: iterable of integers
    # pred: dict of sets for predecessor info
    # succ: dict of sets for successor info
    # pred and succ can contain useless info (items not in lst)
    out = []
    no_b4 = deque(item for item in lst if not pred[item])
    
    while no_b4:
        cur = no_b4.popleft()
        out.append(cur)
        for item in succ[cur]:
            pred[item].discard(cur)
            if not pred[item]:
                no_b4.append(item)
    
    if len(out) == len(lst):
        return out
    else:
        return []