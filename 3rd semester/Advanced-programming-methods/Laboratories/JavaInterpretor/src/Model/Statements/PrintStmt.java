package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import ADTs.MyIList;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Statements.IStmt;
import Model.Values.Value;

public class PrintStmt implements IStmt {

    Exp expression;

    public PrintStmt(Exp _expression){
        this.expression = _expression;
    }

    @Override
    public String toString(MyIDictionary<String, Value> dict) throws MyException {
        return "print(" + this.expression.toString() + ")";
    }

    public String toString()   {
        return "print(" + this.expression.toString() + ")";
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIHeap<Value> heap = state.getHeap();
        MyIList<Value> list = state.getOut();
        list.addLast(expression.eval(symbolTable,heap));
        return null;
    }
}
