package Model.Expressions;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Values.Value;

public interface Exp {
    Value eval(MyIDictionary<String, Value> symbolTable, MyIHeap<Value> heap) throws MyException;

    String toString();
}