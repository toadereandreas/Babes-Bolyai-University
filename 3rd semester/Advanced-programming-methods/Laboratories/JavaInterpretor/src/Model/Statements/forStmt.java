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

public class forStmt implements IStmt {

    private IStmt initialize;
    private Exp expression;
    private IStmt statement;
    private IStmt step;
    private VarDeclStmt copy_initialize;

    public forStmt( IStmt _initialize, Exp _expression, IStmt _statement, IStmt _step ){
        this.initialize = _initialize;
        this.expression = _expression;
        this.statement = _statement;
        this.step = _step;
    }

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        MyIStack<IStmt> executionStack = state.getStack();
        MyIHeap<Value> heap = state.getHeap();

        if( this.initialize instanceof NopStmt) {
            Value value = this.expression.eval(symbolTable, heap);
            if (value.getType() instanceof BoolType) {
                BoolValue boolValue = (BoolValue) value;
                if (boolValue.getValue()) {
                    executionStack.push(this);
                    executionStack.push(this.step);
                    executionStack.push(this.statement);
                }
            } else throw new MyException("forStmt: " + this.expression.toString() + "is not a boolean expression.");
        }
        else{
            IStmt initializeStmt = this.initialize;
            this.initialize = new NopStmt();
            executionStack.push(this);
            executionStack.push(initializeStmt);
        }
        return null;
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return "for(" + this.initialize.toString() + "; " + this.expression.toString() + "; " + this.step.toString(symbolTable) + "){" + this.statement.toString(symbolTable) + "}";
    }
}
