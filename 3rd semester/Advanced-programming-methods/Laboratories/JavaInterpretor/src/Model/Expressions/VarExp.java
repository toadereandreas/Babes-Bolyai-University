package Model.Expressions;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Values.Value;

public class VarExp implements Exp {

    String id;

    public VarExp(String _id){
        this.id = _id;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symbolTable, MyIHeap<Value> heap) throws MyException {
        if( symbolTable.contains(this.id))
            return symbolTable.get(this.id);
        else throw new MyException("VarExp exception: The variable " + this.id + " is used, but not declared!");
    }

    @Override
    public String toString(){
        return this.id;
    }
}
