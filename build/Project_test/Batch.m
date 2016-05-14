function res = Batch()
res = 0
figure; hold on; axis equal;
plot([5.10102 5.10102],[5 5], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot(5.10102 + 10 * cos(0:0.001 : 2 * pi), 5 + 10 * sin(0:0.001 : 2 * pi), 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([10 10],[10 10], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot(10 + 3 * cos(0:0.001 : 2 * pi), 10 + 3 * sin(0:0.001 : 2 * pi), 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([15 15],[15 15], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot(15 + 3 * cos(0:0.001 : 2 * pi), 15 + 3 * sin(0:0.001 : 2 * pi), 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
