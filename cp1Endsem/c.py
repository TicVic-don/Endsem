class Range:
    def __init__(self, x, y, index):
        self.x = x
        self.y = y
        self.index = index

def compare_by_start(a, b):
    if a.x == b.x:
        return b.y - a.y
    return a.x - b.x

def compare_by_end(a, b):
    if a.y == b.y:
        return b.x - a.x
    return a.y - b.y

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    ranges = []
    index = 1
    for i in range(n):
        x = int(data[index])
        ranges.append(Range(x, 0, i))
        index += 1
    for i in range(n):
        ranges[i].y = int(data[index])
        index += 1
    
    ress = [0] * n
    contained_by_result = [0] * n
    
    ranges.sort(key=lambda r: (r.x, -r.y))
    
    max_y = float('-inf')
    for i in range(n):
        if ranges[i].y < max_y:
            ress[ranges[i].index] = 1
        max_y = max(max_y, ranges[i].y)
    
    ranges.sort(key=lambda r: (r.y, -r.x))
    
    min_y = float('inf')
    for i in range(n-1, -1, -1):
        if ranges[i].y > min_y:
            contained_by_result[ranges[i].index] = 1
        min_y = min(min_y, ranges[i].y)
    
    print(' '.join(map(str, ress)))
    print(' '.join(map(str, contained_by_result)))

if __name__ == "__main__":
    main()