# 연결된 인접 리스트 입니다
list = {
    'x': {'y', 'w', 't', 'u'},
    'y': {'x', 'u'},
    'v': {'r'},
    'w': {'x', 's', 't'},
    'r': {'v', 's'},
    's': {'w', 'r'},
    't': {'x', 'w', 'u'},
    'u': {'x', 'y', 't'}
}

# 인자로 vertex, distance, predecessor, visited dict을 받습니다


def dfs(vertex, dist, pred, visited={}):
    # visited[vertex]에 distancce값과 pred값을 넣습니다
    visited[vertex] = {"distance": dist, "predecessor": pred}
    # vertex의 인접 리스트에 담긴 vertex들을 순환합니다
    for u in list[vertex]:
        # 만약 이미 방문한 vertex일 경우 새로 계산된 거리가 기존 거리보다 작다면 update합니다
        if u in visited and dist+1 < visited[u]['distance']:
            visited[u]['distance'] = dist+1
        # 방문하지 않은 vertex일 경우 dfs 재귀함수를 실행합니다
        if not u in visited:
            visited = dfs(u, dist+1, vertex, visited)
    return visited


# 함수를 실행합니다
results = dfs('s', 0, 'none')
# 각 vertex의 distance, predecessor정보를 출력합니다
for v in results:
    print('at vertex : ', v)
    print('distance from origin : ', results[v]['distance'])
    print('predecessor : ', results[v]['predecessor'])
    print()
