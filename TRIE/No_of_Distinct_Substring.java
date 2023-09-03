
class Node {
    Node[] links = new Node[26];
    boolean flag = false;

    public Node() {
    }

    public boolean containsKey(char ch) {
        return this.links[ch - 'a'] != null;
    }

    public void put(char ch, Node node) {
        this.links[ch - 'a'] = node;
    }

    public Node get(char ch) {
        return this.links[ch - 'a'];
    }

    public void setEnd() {
        this.flag = true;
    }

    public boolean isEnd() {
        return this.flag;
    }
}

public class solution {

    public static int countDistinctSubstrings(String s) {
        int count = 0;
        Node root = new Node();

        for (int i = 0; i < s.length(); ++i) {
            Node node = root;
            for (int j = i; j < s.length(); ++j) {
                if (!node.containsKey(s.charAt(j))) {
                    count++;
                    node.put(s.charAt(j), new Node());
                }
                node = node.get(s.charAt(j));
            }
        }
        return count + 1;
    }
}
