function res = test8()
res = 0
figure; hold on; axis equal;
plot([1 1],[1 1], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([5 5],[1 1], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([1 5],[1 1], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([4.99999 4.99999],[1.00001 1.00001], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([4.99159 4.99159],[11 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([4.99999 4.99159],[1.00001 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([0.999997 0.999997],[0.99999 0.99999], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([4.99158 4.99158],[11 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([0.999997 4.99158],[0.99999 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([5 5],[0.999991 0.999991], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([13 13],[1 1], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([5 13],[0.999991 1], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([4.99159 4.99159],[11 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([12.9916 12.9916],[11 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([4.99159 12.9916],[11 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([12.9916 12.9916],[11 11], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([13 13],[1.00001 1.00001], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([12.9916 13],[11 1.00001], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot([3.2 3.2],[3 3], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)
plot(3.2 + 0.5 * cos(0:0.001 : 2 * pi), 3 + 0.5 * sin(0:0.001 : 2 * pi), 'LineWidth', 2, 'Marker', '.', 'MarkerSize', 10)