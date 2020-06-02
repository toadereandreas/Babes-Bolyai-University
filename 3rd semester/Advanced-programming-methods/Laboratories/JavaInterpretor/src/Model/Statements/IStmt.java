package Model.Statements;

import ADTs.MyIDictionary;
import Exceptions.MyException;
import Model.ProgramState.PrgState;
import Model.Values.Value;

public interface IStmt {

    PrgState execute(PrgState state) throws MyException;

    String toString(MyIDictionary<String, Value> symbolTable) throws MyException;
}
