function res = Batch()
res = 0
figure; hold on; axis equal;
plot([2 2],[1 1], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([2 2],[3 3], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([2 2],[1 3], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([5 5],[2 2], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([1 1],[2 2], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([5 1],[2 2], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([1 1],[2 2], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot(1 + 10 * cos(0:0.001 : 2 * pi), 2 + 10 * sin(0:0.001 : 2 * pi), 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
