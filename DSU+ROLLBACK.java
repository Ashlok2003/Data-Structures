import java.util.*;
class DSU{
    Map<Integer, Integer> size;
    Map<Integer, Integer> rank;
    Map<Integer, Integer> parent;
    Stack<Integer[]> history;

    public DSU(){
        size = new HashMap<>();
        rank = new HashMap<>();
        parent = new HashMap<>();
        history =  new Stack<>();

    }
    public int findUParent(int x){
        if(!parent.containsKey(x)){
            parent.put(x, x);
            rank.put(x, 0);
            size.put(x, 1);
            return x;
        }
        if(parent.get(x) != x)
            parent.put(x, findUParent(parent.get(x)));

        return parent.get(x);
    }

    public void UnionByRank(int u, int v){
        int rootX = findUParent(u);
        int rootY = findUParent(v);

        if(rootX == rootY)
            return;

        if(rank.get(rootX) < rank.get(rootY)){
            parent.put(rootX, rootY);
            size.put(rootY, size.get(rootY) + size.get(rootX));
        }
        else if(rank.get(rootX) > rank.get(rootY)){
            parent.put(rootY, rootX);
            size.put(rootX, size.get(rootX) + size.get(rootY));
        }
        else{
            parent.put(rootX, rootY);
            rank.put(rootX, rank.get(rootX) + 1);
            size.put(rootX, size.get(rootX) + size.get(rootY));
        }
    }
    public void UnionBySize(int u, int v){
        int rootX = findUParent(u);
        int rootY = findUParent(v);
        if(rootX == rootY)
            return;

        if(size.get(rootX) < size.get(rootY)){
            parent.put(rootX, rootY);
            size.put(rootY, size.get(rootX) + size.get(rootY));
        }
        else{
            parent.put(rootY, rootX);
            size.put(rootX, size.get(rootX) + size.get(rootY));
            if(size.get(rootX).equals(size.get(rootY)))
                rank.put(rootX, rank.get(rootX) + 1);
        }
    }
    public boolean rollback(){
        // Rolling back to go one step before som union operations :)
        if(history.isEmpty())
            return false;

        Integer[] lastOperation = history.pop();
        int element = lastOperation[0];
        int previousSize  = lastOperation[1];
        size.put(element, previousSize);
        parent.put(element, element);

        return true;
    }
}
