package ADTs;

public interface MyIList<T> {

    void addFirst(T _elem);

    void addLast(T _elem);

    boolean contains(T _elem);

    T get(int _index);

    T getFirst(int _index);

    T getLast(int _index);

    int indexOf(T _elem);

    int lastIndexOf(T _elem);

    T remove();

    T set(int _index, T _elem);

    int size();

    String toString(); //needed by the ProgramState toString() method
}