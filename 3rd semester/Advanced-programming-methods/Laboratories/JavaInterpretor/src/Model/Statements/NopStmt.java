package Model.Statements;

import ADTs.MyIDictionary;
import Exceptions.MyException;
import Model.ProgramState.PrgState;
import Model.Values.Value;

public class NopStmt implements IStmt {

    public NopStmt(){}

    @Override
    public PrgState execute(PrgState state) throws MyException {
        return null;
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "NOP";
    }

    public String toString() {
        return "NOP";
    }
}
