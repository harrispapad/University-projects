import java.io.*;
import java.util.*;

public class Grid {
    static class Node {
        int x, y;
        List<String> path;

        Node(int x, int y, List<String> path) {
            this.x = x;
            this.y = y;
            this.path = new ArrayList<>(path);
        }
    }
    private static final int[] dx = {-1, 1, 0, 0, -1, -1, 1, 1};
    private static final int[] dy = {0, 0, -1, 1, -1, 1, -1, 1};

    private static final String[] directions = {"N", "S", "W", "E", "NW", "NE", "SW", "SE"};

    /**
     * @param args
     */
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File(args[0]));
            int N = sc.nextInt();
            int[][] grid = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }
            String result = solve(grid, N);
            System.out.println(result);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * @param grid
     * @param N
     * @return
     */
    private static String solve(int[][] grid, int N) {
        boolean[][] visited = new boolean[N][N];
        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(0, 0, new ArrayList<>()));
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            if (current.x == N - 1 && current.y == N - 1) {
                return output(current.path);
            }

            for (int i = 0; i < 8; i++) {
                int newx = current.x + dx[i];
                int newy = current.y + dy[i];
                if (valid(newx, newy, N, grid, visited, grid[current.x][current.y])) {
                    visited[newx][newy] = true;
                    List<String> newPath = new ArrayList<>(current.path);
                    newPath.add(directions[i]);
                    queue.add(new Node(newx, newy, newPath));
                }
            }
        }

        return "IMPOSSIBLE";
    }

    private static boolean valid(int x, int y, int N, int[][] grid, boolean[][] visited, int currentCars) {
        return x >= 0 && y >= 0 && x < N && y < N && !visited[x][y] && grid[x][y] < currentCars;
    }

    private static String output(List<String> path) {
        return path.isEmpty() ? "IMPOSSIBLE" : path.toString();
    }
}

