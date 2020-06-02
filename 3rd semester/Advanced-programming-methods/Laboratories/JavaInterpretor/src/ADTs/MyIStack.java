package ADTs;

import Exceptions.MyException;
import Model.Values.Value;

public interface MyIStack<T> {

    T pop();

    void push(T _value);

    boolean isEmpty();

    int search(T _element);

    T peek();

    String toString(MyIDictionary<String, Value> _symbolTable) throws MyException;
}
