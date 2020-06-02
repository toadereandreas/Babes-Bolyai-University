package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Types.StringType;
import Model.Values.StringValue;
import Model.Values.Value;

import java.io.BufferedReader;
import java.io.IOException;

public class closeRFile implements IStmt {

    Exp expression;

    public closeRFile(Exp _expression){
        this.expression = _expression;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        MyIHeap<Value> heap = state.getHeap();
        Value value = this.expression.eval(symbolTable,heap);
        if(value.getType() instanceof StringType){
            StringValue fileStringValue = (StringValue) value;
            if( fileTable.contains(fileStringValue.getValue())){
                BufferedReader bufferedReader = fileTable.get(fileStringValue.getValue());
                try{
                    bufferedReader.close();
                    fileTable.remove(fileStringValue.getValue());
                    return null;
                } catch (IOException e) { throw new MyException("closeRFile exception: IOException.");}
            } else throw new MyException("closeRFile exception: " + this.expression.toString() + " is not in file table.");
        } else throw new MyException("closeRFile exception: " + this.expression.toString() + " is not a string.");
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "closeRFile(" + this.expression.toString() + ")";
    }

    public String toString() {
        return "closeRFile(" + this.expression.toString() + ")";
    }
}
