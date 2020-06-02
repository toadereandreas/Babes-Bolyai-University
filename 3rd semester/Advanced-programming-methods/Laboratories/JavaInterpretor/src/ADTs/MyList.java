package ADTs;

import java.util.Iterator;
import java.util.LinkedList;

public class MyList<T> implements MyIList<T> {

    LinkedList<T> list;

    public MyList() {
        this.list = new LinkedList<T>();
    }

    @Override
    public void addFirst(T _elem) {
        this.list.addFirst(_elem);

    }

    // Adds an element to tail
    @Override
    public void addLast(T _elem) {
        this.list.addLast(_elem);
    }

    @Override
    public boolean contains(T _elem) {
        return this.list.contains(_elem);
    }

    @Override
    public T get(int _index) {
        return this.list.get(_index);
    }

    @Override
    public T getFirst(int _index) {
        // TODO Auto-generated method stub
        return null;
    }

    @Override
    public T getLast(int _index) {
        return this.list.getLast();
    }

    @Override
    public int indexOf(T _elem) {
        return this.list.indexOf(_elem);
    }

    @Override
    public int lastIndexOf(T _elem) {
        return this.list.lastIndexOf(_elem);
    }

    @Override
    public T remove() {
        //removes the head
        return this.list.remove();
    }

    @Override
    public T set(int _index, T _elem) {
        return this.list.set(_index, _elem);
    }

    @Override
    public int size() {
        return this.list.size();
    }

    @Override
    public String toString()
    {
        String result = "";

        Iterator<T> it = (Iterator<T>)this.list.iterator();
        while (it.hasNext())
            result += it.next().toString() + " ";
        if( result == "" )
            return result;
        else
            return '\n' + result;
    }
}