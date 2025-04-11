x = [4, 5, 10, 4, 3, 11, 14 , 6, 10, 12]
y = [21, 19, 24, 17, 16, 25, 24, 22, 21, 21]
xy = [(x[i], y[i]) for i in range(len(x))]
# xy = [(2, 10), (2, 5), (8, 4), (5, 8), (7, 5), (6, 4), (1, 2), (4, 9)]

n_clusters = 3
centers = []
for i in range(n_clusters):
    centers.append(sorted(xy)[i*len(x)//n_clusters])
clusters = [-1]*len(xy)
# centers = [(2, 10), (5, 8), (1, 2)]

print(xy)
print(centers)

def kmeans():
    for i in range(5):
        for j in range(len(xy)):
            point = xy[j]
            min_dist = float('inf')
            for k in range(len(centers)):
                center = centers[k]
                if (((point[0]-center[0])**2 + (point[1]-center[1])**2) < min_dist):
                    min_dist = (point[0]-centers[k][0])**2 + (point[1]-centers[k][1])**2
                    clusters[j] = k
        print(f"Iteration {i+1}: {clusters}, {centers}")
        for j in range(len(centers)):
            points = []
            for k in range(len(xy)):
                if clusters[k] == j:
                    points.append(xy[k])
            if len(points) > 0:
                centers[j] = (sum([points[i][0] for i in range(len(points))])/len(points), sum([points[i][1] for i in range(len(points))])/len(points))

kmeans()