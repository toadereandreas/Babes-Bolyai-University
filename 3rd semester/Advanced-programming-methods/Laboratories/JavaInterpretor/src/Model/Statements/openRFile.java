package Model.Statements;

import ADTs.MyDictionary;
import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import ADTs.MyStack;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Statements.IStmt;
import Model.Types.StringType;
import Model.Values.StringValue;
import Model.Values.Value;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

public class openRFile implements IStmt {
    private Exp expression;

    public openRFile(Exp _expression){
        this.expression = _expression;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        MyIHeap<Value> heap = state.getHeap();
        Value value = this.expression.eval(symbolTable,heap);
        if( value.getType() instanceof StringType){
            if( fileTable.contains(((StringValue)value).getValue()))
                throw  new MyException("openRFile exception: The file " + this.expression.toString() + " already exists!");
            try {
                Reader reader = new FileReader(((StringValue)(value)).getValue());
                BufferedReader bufferedReader = new BufferedReader(reader);
                fileTable.put(((StringValue)(value)).getValue(), bufferedReader);
                return null;
            }
            catch(IOException e) {
                System.out.println(e.getMessage());
                throw new MyException("openRFile exception: IOException!");

            }
        }else throw new MyException("openRFile exception: Argument" + this.expression.toString() + "for openRFile is not a string!");
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "openRFile(" + this.expression.toString() + ")";
    }

    public String toString() {
        return "openRFile(" + this.expression.toString() + ")";
    }
}
