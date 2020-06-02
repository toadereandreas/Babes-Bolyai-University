package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Types.RefType;
import Model.Values.RefValue;
import Model.Values.Value;

public class newStmt implements IStmt {

    private String name;
    private Exp expression;

    public newStmt(String _name, Exp _expression) {
        this.name = _name;
        this.expression = _expression;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIHeap<Value> heap = state.getHeap();
        Value value = symbolTable.get(this.name);
        if( value instanceof RefValue ){
            RefValue refValue = (RefValue) value;
            Value expValue = this.expression.eval(symbolTable,heap);
            if( refValue.getLocationType().equals(expValue.getType())){
                int newAddress = heap.generateNextPosition();
                refValue.setAddress(newAddress);
                heap.explicitPut(newAddress, expValue.copyValue());
                return null;
            } else throw new MyException("newStmt exception: " + this.name + " and " + expValue.toString() + " are not of the same type.");
        } else throw new MyException("newStmt exception: " + this.name + " is " + value.toString() + ", not a reference type.");
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "new(" + this.name.toString() + "," + this.expression.toString() + ")";
    }

    public String toString() {
        return "new(" + this.name.toString() + "," + this.expression.toString() + ")";
    }
}
