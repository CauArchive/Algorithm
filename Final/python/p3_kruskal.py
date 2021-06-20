numOfVertex, numOfEdge = (9, 14)
edge = [[1, 2, 4], [2, 3, 8],  [1, 8, 8], [2, 8, 11], [8, 9, 7],
        [9, 3, 2], [8, 7, 1],  [9, 7, 6], [3, 4, 7],  [3, 6, 4],
        [7, 6, 2], [4, 6, 14], [4, 5, 9], [6, 5, 10]]
edge.sort(key=lambda e: e[2])
alphabet = 'abcdefghi'
for u, v, w in edge:
    print(alphabet[u-1], alphabet[v-1], w)

parent = list(range(numOfVertex + 1))


def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]


def union(x, y):
    x = find(x)
    y = find(y)
    if y < x:
        parent[x] = y
    else:
        parent[y] = x


i = 1
sum = 0
for f, s, w in edge:
    print(i)
    print("current value is ", alphabet[f-1], alphabet[s-1])
    if find(f) != find(s):
        print(alphabet[f-1], alphabet[s-1], "become unioned")
        union(f, s)
        sum += w
    i += 1

print(sum)
