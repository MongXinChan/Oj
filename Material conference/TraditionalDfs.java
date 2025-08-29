import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TraditionalDfs {

    private List<List<Integer>> adj;
    private boolean[] visited;

    public TraditionalDfs(List<List<Integer>> graph) {
        this.adj = graph;
        this.visited = new boolean[graph.size()];
    }
    
    public void startDfs(int startNode) {
        dfs(startNode);
    }

    private void dfs(int u) {
        visited[u] = true;
        System.out.println("Visiting node: " + u);

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                dfs(v); // 递归调用
            }
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        graph.add(Arrays.asList(1, 2)); // Node 0
        graph.add(Arrays.asList(0, 3)); // Node 1
        graph.add(Arrays.asList(0, 4)); // Node 2
        graph.add(Arrays.asList(1));    // Node 3
        graph.add(Arrays.asList(2));    // Node 4

        TraditionalDfs traverser = new TraditionalDfs(graph);
        traverser.startDfs(0); // 从节点 0 开始DFS
    }
}