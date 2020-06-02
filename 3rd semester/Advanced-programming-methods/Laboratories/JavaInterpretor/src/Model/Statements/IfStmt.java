package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import ADTs.MyIStack;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Values.BoolValue;
import Model.Values.Value;

public class IfStmt implements IStmt {
    Exp expression;
    IStmt thenStatement;
    IStmt elseStatement;

    public IfStmt(Exp _expression, IStmt _thenStatement, IStmt _elseStatement ){
        this.expression = _expression;
        this.thenStatement = _thenStatement;
        this.elseStatement = _elseStatement;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIStack<IStmt> stack = state.getStack();
        MyIHeap<Value> heap = state.getHeap();
        BoolValue condition = (BoolValue)this.expression.eval(symbolTable,heap);

        if(condition.getValue())
            stack.push(this.thenStatement);
        else
            stack.push(this.elseStatement);
        return null;
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "if(" + this.expression.toString() + "){" + this.thenStatement.toString(symbolTable) + "} else{" + this.elseStatement.toString(symbolTable) + "}";
    }

    public String toString() {
        return "if(" + this.expression.toString() + "){" + this.thenStatement.toString() + "} else{" + this.elseStatement.toString() + "}";
    }
}
