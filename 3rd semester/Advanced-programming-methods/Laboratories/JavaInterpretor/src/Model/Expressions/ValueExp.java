package Model.Expressions;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Values.Value;

public class ValueExp implements Exp {

    private Value value;

    public ValueExp(Value _value){
        this.value = _value;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symbolTable, MyIHeap<Value> heap) throws MyException {
        return this.value;
    }

    @Override
    public String toString(){
        return this.value.toString();
    }
}
