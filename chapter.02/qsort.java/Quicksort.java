import java.util.Random;

interface Cmp {
    int cmp(Object x, Object y);
}


// Icmp: Integer compare
class Icmp implements Cmp {
    public int cmp(Object x, Object y) {
        int tmp_x = ((Integer) x).intValue();
        int tmp_y = ((Integer) y).intValue();
        
        if (tmp_x < tmp_y)
            return -1;
        else if (tmp_x == tmp_y)
            return 0;
        else
            return 1;
    }
}


// Scmp: String compare
class Scmp implements Cmp {
    public int cmp(Object x, Object y) {
        String tmp_x = (String) x;
        String tmp_y = (String) y;
        return tmp_x.compareTo(tmp_y);
    }
}


class Quicksort {
    
    // Quicksort.sort: v[left]..v[right]
    static void sort(Object[] v, int left, int right, Cmp cmp) {
        int i, last;
        
        if (left >= right)
            return;
        
        swap(v, left, rand(left, right));
        last = left;
        for (i = left + 1; i <= right; i++) {
            if (cmp.cmp(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }
        
        swap(v, left, last);
        sort(v, left, last - 1, cmp);
        sort(v, last + 1, right, cmp);
    }
    
    // Quicksort.swap: v[i] <-> v[j]
    static void swap(Object[] v, int i, int j) {
        Object tmp;
        tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }
    
    static Random rgen = new Random();
    // Quicksort.rand: [left, right]
    static int rand(int left, int right) {
        return left + rgen.nextInt(right - left + 1);
    }
    
    public static void main(String[] args) {
        Integer[] v = {5, 3, 4, 8, 2, 1, 0, 7, 9};
        for (Integer i : v) {
            System.out.print(i.toString() + " ");
        }
        
        Quicksort.sort(v, 0, v.length - 1, new Icmp());
        
        for (Integer i : v) {
            System.out.print(i.toString() + " ");
        }
    }
}
