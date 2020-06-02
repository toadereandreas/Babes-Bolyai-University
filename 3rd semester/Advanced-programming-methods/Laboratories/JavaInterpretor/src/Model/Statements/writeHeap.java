package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Types.RefType;
import Model.Values.RefValue;
import Model.Values.Value;

public class writeHeap implements IStmt {

    private String name;
    private Exp expression;

    public writeHeap( String _name, Exp _expression ){
        this.name = _name;
        this.expression = _expression;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIHeap<Value> heap = state.getHeap();
        Value value = symbolTable.get(this.name);
        if( value == null )
            throw new MyException("writeHeap exception: " + this.name.toString() + " is not found in the symbol table.");
        if( value instanceof RefValue ){
            RefValue refValue = (RefValue) value;
            Value expValue = this.expression.eval(symbolTable,heap);
            if( refValue.getLocationType().equals(expValue.getType())){
                int address = refValue.getAddress();
                heap.explicitPut(address, expValue.copyValue());
                return null;
            } else throw new MyException("writeHeap exception: " + this.name.toString() + " and " + expValue.toString() + " do not have compatible types.");
        } else throw new MyException("writeHeap exception: " + value.toString() + " is not of type ref type.");
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "writeHeap(" + this.name.toString() + ", " + this.expression.toString() + ")";
    }

    public String toString() {
        return "writeHeap(" + this.name.toString() + ", " + this.expression.toString() + ")";
    }
}
