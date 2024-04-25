import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int totalNodes = scanner.nextInt();
            if (totalNodes == 0) {
                System.out.println(totalNodes);
                return;
            }
            int nonLeafNodesCount = scanner.nextInt();
            if (nonLeafNodesCount == 0) {
                System.out.println(totalNodes);
                return;
            }
            scanner.nextLine();
            String[] lines = new String[nonLeafNodesCount];
            for (int i = 0; i < nonLeafNodesCount; i++) {
                lines[i] = scanner.nextLine();
            }

            Map<String, Node> tree = new HashMap<>();
            createTree(tree, lines);
            List<Integer> leafCounts = countLeafNodes(tree);
            printList(leafCounts);
        } catch (NumberFormatException e) {
            System.err.println("Error parsing input");
        }
    }

    private static void createTree(Map<String, Node> tree, String[] lines) {
        for (String line : lines) {
            String[] parts = line.split("\\s+");
            String id = parts[0];
            Node node = tree.getOrDefault(id, new Node(id));
            int numChildren = Integer.parseInt(parts[1]);
            for (int i = 0; i < numChildren; i++) {
                String childId = parts[i + 2];
                Node child = tree.getOrDefault(childId, new Node(childId));
                node.appendChild(child);
                tree.put(childId, child);
            }
            tree.put(id, node);
        }
    }

    private static List<Integer> countLeafNodes(Map<String, Node> tree) {
        List<Integer> counts = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(tree.get("01"));
        while (!queue.isEmpty()) {
            int size = queue.size();
            int count = 0;
            for (int i = 0; i < size; i++) {
                Node current = queue.poll();
                if (current.children.isEmpty()) {
                    count++;
                } else {
                    queue.addAll(current.children);
                }
            }
            counts.add(count);
        }
        return counts;
    }

    private static void printList(List<Integer> counts) {
        for (int i = 0; i < counts.size(); i++) {
            if (i == counts.size() - 1) {
                System.out.println(counts.get(i));
            } else {
                System.out.print(counts.get(i) + " ");
            }
        }
    }

    static class Node {
        String id;
        List<Node> children = new ArrayList<>();

        public Node(String id) {
            this.id = id;
        }

        public void appendChild(Node node) {
            this.children.add(node);
        }
    }
}
