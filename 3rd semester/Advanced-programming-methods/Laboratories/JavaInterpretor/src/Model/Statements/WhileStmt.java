package Model.Statements;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import ADTs.MyIStack;
import Exceptions.MyException;
import Model.Expressions.Exp;
import Model.ProgramState.PrgState;
import Model.Types.BoolType;
import Model.Values.BoolValue;
import Model.Values.Value;

public class WhileStmt implements IStmt {

    private Exp expression;
    private IStmt statement;

    public WhileStmt( Exp _expression, IStmt _statement ){
        this.expression = _expression;
        this.statement = _statement;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIStack<IStmt> executionStack = state.getStack();
        MyIHeap<Value> heap = state.getHeap();
        Value value = this.expression.eval(symbolTable,heap);
        if( value.getType() instanceof BoolType ){
            BoolValue expressionValue = (BoolValue) value;
            if( expressionValue.getValue()){
                executionStack.push(this);
                executionStack.push(this.statement);
            }
            return null;
        } else throw new MyException("WhileStmt exception: " + this.expression.toString() + " is not a boolean expression.");
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "while(" + this.expression.toString() + "){" + this.statement.toString(symbolTable) + "}";
    }

    public String toString() {
        return "while(" + this.expression.toString() + "){" + this.statement.toString() + "}";
    }
}
