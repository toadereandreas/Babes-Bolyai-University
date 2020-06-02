package ADTs;

import Exceptions.MyException;
import Model.Statements.IStmt;
import Model.Values.Value;

import java.util.Iterator;
import java.util.Stack;

public class MyStack<T> implements MyIStack<T> {

    private Stack<T> stack;

    MyStack(){
        this.stack = new Stack<T>();
    }

    public MyStack(T _initialElement){
        this.stack = new Stack<T>();
        this.stack.push(_initialElement);
    }

    @Override
    public T pop() {
        return this.stack.pop();
    }

    @Override
    public void push(T _value) {
        this.stack.push(_value);
    }

    @Override
    public boolean isEmpty() {
        return this.stack.empty();
    }

    @Override
    public int search(T _element) {
        return this.stack.search(_element);
    }

    @Override
    public T peek() {
        return this.stack.peek();
    }

    @Override
    public String toString(MyIDictionary<String, Value> _symbolTable) throws MyException {
        String result = "";
        String[] tokens;

        Iterator<T> it = (Iterator<T>)this.stack.iterator();
        while(it.hasNext())
        {
            T elem = it.next();
            result += ((IStmt)elem).toString(_symbolTable) + "\n";
        }

        tokens = result.split("\n");
        result = "";
        for (int index = tokens.length - 1; index >= 0; --index)
            result += tokens[index] + "\n";

        return result;
    }
}
