class Node {
    Node[] links = new Node[26];
    boolean flag = false;

    public Node() {

    }

    public boolean containskey(char ch) {
        return (this.links[ch - 'a'] != null);
    }

    public Node get(char ch) {
        return this.links[ch - 'a'];
    }

    void put(char ch, Node node) {
        this.links[ch - 'a'] = node;
    }

    void setEnd() {
        this.flag = true;
    }

    boolean isEnd() {
        return this.flag;
    }

}

public class TRIE {
    public static Node root;

    // Initializing the TRIE data structure :)
    public TRIE() {
        root = new Node();
    }

    // Time complexity : O(N) =>(N = length of the word :)
    void insert(String word) {
        Node node = root;

        for (int i = 0; i < word.length(); ++i) {
            if (node.containskey(word.charAt(i))) {
                node.put(word.charAt(i), new Node());
            }
            // moving (heading) toward the reference trie ==>
            node = node.get(word.charAt(i));
        }
        node.setEnd();
    }

    // Time complexity : O(N)
    public boolean search(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!node.containskey(word.charAt(i)))
                return false;

            node = node.get(word.charAt(i));
        }

        return node.isEnd();
    }

    // Time complexity : O(N)
    public boolean startsWith(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!node.containskey(word.charAt(i)))
                return false;

            node = node.get(word.charAt(i));
        }
        return true;
    }
}
