from heapq import heappush, heappop

numOfVertex, numOfEdge = (9, 14)
edge = [[1, 2, 4], [2, 3, 8],  [1, 8, 8], [2, 8, 11], [8, 9, 7],
        [9, 3, 2], [8, 7, 1],  [9, 7, 6], [3, 4, 7],  [3, 6, 4],
        [7, 6, 2], [4, 6, 14], [4, 5, 9], [6, 5, 10]]
alphabet = 'abcdefghi'
graph = [[] for i in range(numOfVertex + 1)]
for i in range(numOfEdge):
    u, v, w = edge[i]
    graph[u].append([v, w])
    graph[v].append([u, w])


def prim(start, weight):
    i = 1
    visit = [0] * (numOfVertex + 1)  # 정점 방문 처리
    q = [[weight, start]]  # 힙 구조를 사용하기 위해 가중치를 앞에 둠
    ans = 0  # 가중치 합
    cnt = 0  # 간선의 개수
    while cnt < numOfVertex:  # 간선의 개수 최대는 V-1
        print(i, "th iteration")
        k, v = heappop(q)
        print("weight is : ", k, "current point is : ", alphabet[v-1])
        if visit[v]:
            print(alphabet[v-1], "already visited")
            continue  # 이미 방문한 정점이면 지나감
        visit[v] = 1  # 방문안했으면 방문처리
        ans += k  # 해당 정점까지의 가중치를 더해줌
        cnt += 1  # 간선의 갯수 더해줌
        for u, w in graph[v]:  # 해당 정점의 간선정보를 불러옴
            heappush(q, [w, u])  # 힙에 넣어줌
        i += 1
    return ans


print(prim(3, 0))
