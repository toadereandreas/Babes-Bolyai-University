package Model.Expressions;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Values.RefValue;
import Model.Values.Value;

public class readHeap implements Exp {

    private Exp expression;

    public readHeap( Exp _expression ){
        this.expression = _expression;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symbolTable, MyIHeap<Value> heap) throws MyException {
        Value value = this.expression.eval(symbolTable,heap);
        if( value instanceof RefValue){
            RefValue valueExp = (RefValue) value;
            Value heapValue = heap.get(valueExp.getAddress());
            if( heapValue == null )
                throw new MyException("readHeap exception: " + this.expression.toString() + " was nout found in the heap table.");
            return heapValue;
        } else throw new MyException("readHeap exception: " + this.expression.toString() + " does not evaluate into a ref value.");
    }

    public String toString(){
        return "readHeap(" + this.expression.toString() + ")";
    }
}
