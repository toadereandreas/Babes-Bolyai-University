package Model.Statements;

import ADTs.*;
import Exceptions.MyException;
import Model.ProgramState.PrgState;
import Model.Values.Value;

import java.io.BufferedReader;

public class forkStmt implements IStmt {

    private IStmt statement;

    public forkStmt( IStmt _statement){
        this.statement = _statement;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIHeap<Value> heap = state.getHeap();
        MyIDictionary<String, BufferedReader> fileTable = state.getFileTable();
        MyIList<Value> out = state.getOut();


        MyIStack<IStmt> newStack = new MyStack<IStmt>(this.statement);
        MyIDictionary<String, Value> newSymbolTable = (MyIDictionary<String, Value>)symbolTable.makeCopy();

        return new PrgState(newStack, newSymbolTable, out, this.statement, fileTable, heap);
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "fork(" + this.statement.toString() + ')';
    }

    public String toString() {
        return "fork(" + this.statement.toString() + ')';
    }
}
