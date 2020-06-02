package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import ADTs.MyIStack;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Values.Value;

public class AssignStmt implements IStmt {

    String id;
    Exp expression;

    public AssignStmt(String _id, Exp _expression){
        this.id = _id;
        this.expression = _expression;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIHeap<Value> heap = state.getHeap();
        Value newValue = this.expression.eval(symbolTable,heap);

        if(symbolTable.contains(this.id)){
            Value oldValue = symbolTable.get(this.id);
            //if( newValue.getType().equals(oldValue.getType()) ){ <- does not work this way for string. e.g.  IStmt stmt5 = new CompStmt(new VarDeclStmt("filevar", new StringType()),new AssignStmt("filevar", new ValueExp(new StringValue("test.in"))));
            if( newValue.getType().toString().equals(oldValue.getType().toString())){
                symbolTable.put(this.id, newValue);
            } else throw new MyException("AssignStmt exception: Variable " +  this.id.toString() + " is assigned wrong value type: " + newValue.getType().toString() + "!");

        } else throw new MyException("AssignStmt exception: Variable " + this.id.toString() + " used but not defined!");

        return null;
    }

    @Override
    public String toString(MyIDictionary<String, Value> dict) throws MyException {
        return id + " = " + this.expression.toString();
    }

    public String toString() {
        return id + " = " + this.expression.toString();
    }
}