package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Statements.IStmt;
import Model.Types.IntType;
import Model.Types.StringType;
import Model.Values.IntValue;
import Model.Values.StringValue;
import Model.Values.Value;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class readFile implements IStmt {

    private Exp expression;
    private String variableName;

    public readFile(Exp _expression, String _variableName){
        this.expression = _expression;
        this.variableName = _variableName;
    }

    public String toString(){
        return "readFile(" + this.expression.toString() + ", " + this.variableName.toString() + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        MyIHeap<Value> heap = state.getHeap();
        if( symbolTable.contains(this.variableName) ){
            Value valueVariable = symbolTable.get(this.variableName);
            if( valueVariable.getType() instanceof IntType){
                Value valueFile = this.expression.eval(symbolTable,heap);
                if( valueFile.getType() instanceof StringType ){
                    StringValue valueFileString = (StringValue)valueFile;
                    if( fileTable.contains(valueFileString.getValue())){
                        BufferedReader bufferReader = fileTable.get(valueFileString.getValue());
                        try {
                            String line = bufferReader.readLine();
                            int readValue;
                            if( line == null )
                                readValue = 0;
                            else
                                readValue = Integer.parseInt(line);
                            symbolTable.put(this.variableName,new IntValue(readValue));
                            return null;
                        } catch ( IOException exception){
                            throw new MyException("readFile exception: IOException");
                        }
                    } else throw new MyException("readFile exception: The file " + valueFileString.toString() + " does not exists!");
                } else throw new MyException("readFile exception: The expression " + this.expression.toString() + " is not of type string!");
            } else throw new MyException("readFile exception: The variable " + this.variableName.toString() + " is not of type integer!");
        } else throw new MyException("readFile exception: The variable " + this.variableName.toString() + " is not declared!");
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return null;
    }
}
