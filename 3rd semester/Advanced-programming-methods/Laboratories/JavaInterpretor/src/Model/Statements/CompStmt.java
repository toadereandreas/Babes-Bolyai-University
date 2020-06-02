package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIStack;
import Exceptions.MyException;
import Model.ProgramState.PrgState;
import Model.Values.Value;

public class CompStmt implements IStmt {
    IStmt first;
    IStmt second;

    public CompStmt(IStmt _first, IStmt _second) {
        this.first = _first;
        this.second = _second;
    }

    @Override
    public String toString(MyIDictionary<String, Value> dict) throws MyException {
        return "" + first.toString() + "; " + second.toString() + " ";
    }

    public String toString() {
        return "" + first.toString() + "; " + second.toString() + " ";
    }

    @Override
    public PrgState execute(PrgState state) throws MyException{
        MyIStack<IStmt> stk = state.getStack();
        stk.push(this.second);
        stk.push(this.first);
        return null;
    }
}