import heapq

graph = {
    'x': {'z': 2},
    'y': {'x': 4, 'z': 6, 't': 1},
    'z': {'x': 7, 's': 0},
    't': {'x': 6, 'y': 2},
    's': {'y': 5, 't': 3}
}


def dijkstra(graph, start, end1, end2):
    # dists dictionary 초기화합니다
    dists = {node: [float('inf'), start]
             for node in graph}
    # 시작점의 값을 0으로 초기화합니다
    dists[start] = [0, start]
    queue = []
    # 시작 노드를 priority_queue에 넣어서 탐색을 시작합니다
    heapq.heappush(queue, [dists[start][0], start])

    # queue에 값이 없을때까지 반복합니다
    while queue:
        # 큐에서 맨 앞 q를 가져와서 탐색할 노드의 정보를 가져옵니다
        # cur_dist는 거리, cur_dest는 목적지
        cur_dist, cur_dest = heapq.heappop(queue)
        # 만약 기존 거리보다 길다면 skip합니다
        if dists[cur_dest][0] < cur_dist:
            continue
        for next_dest, next_dist in graph[cur_dest].items():
            # 해당 node를 지나갈때의 거리를 구합니다
            dist = cur_dist + next_dist
            # 만약 해당 거리가 현재까지 알고 있었던 값보다 작다면 작은 값으로 갱신해줍니다
            if dist < dists[next_dest][0]:
                dists[next_dest] = [dist, cur_dest]
                # 다음 탐색을 위해 queue에 넣어줍니다
                heapq.heappush(queue, [dist, next_dest])
    # end1 패스에서부터 start까지 탐색합니다
    path1 = end1
    output1 = end1 + '<-'
    # dists배열에 저장한 경로를 output에 붙입니다
    while dists[path1][1] != start:
        output1 += dists[path1][1] + '<-'
        # 저장하면 path1을 다음 path로 업데이트 해줍니다
        path1 = dists[path1][1]
    # output을 저장합니다
    output1 += start

    # end2 패스에서부터 start까지 탐색합니다
    path2 = end2
    output2 = end2 + '<-'
    # 위와 같습니다
    while dists[path2][1] != start:
        output2 += dists[path2][1] + '<-'
        path2 = dists[path2][1]
    output2 += start
    # dists, output1, output2를 return 합니다
    return dists, output1, output2


result, route1, route2 = dijkstra(graph, 's', 'y', 'z')
# 결과에 따라 경로와 비용을 출력합니다
print("at s to y")
print("path : ", route1)
print("costs : ", result['y'][0])
print()
print("at s to z")
print("path : ", route2)
print("costs : ", result['z'][0])
