package Model.Expressions;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Types.BoolType;
import Model.Types.IntType;
import Model.Values.BoolValue;
import Model.Values.Value;

public class LogicExp implements Exp {

    private Exp expression1, expression2;
    private char operand;

    public LogicExp(Exp _expression1, Exp _expression2, char _operand){
        this.expression1 = _expression1;
        this.expression2 = _expression2;
        this.operand = _operand;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symbolTable, MyIHeap<Value> heap) throws MyException {
        Value value1, value2;
        value1 = this.expression1.eval(symbolTable, heap);
        value2 = this.expression2.eval(symbolTable, heap);
        if( value1.getType().equals(new BoolType())) {
            if (value2.getType().equals(new BoolType())) {
                BoolValue boolValue1 = (BoolValue)value1;
                BoolValue boolValue2 = (BoolValue)value2;
                boolean firstOperandValue  = boolValue1.getValue();
                boolean secondOperandValue = boolValue2.getValue();
                if( this.operand == '&' ) return new BoolValue(firstOperandValue && secondOperandValue);
                if( this.operand == '|' ) return new BoolValue(firstOperandValue || secondOperandValue);
                throw new MyException("LogicExp exception: The operand " + this.operand + " is invalid!");
            } else throw new MyException("LogicExp exception: " + this.expression2.toString() + " is not a boolean operand!");
        } else throw new MyException("LogicExp exception: " + this.expression1.toString() + " is not a boolean operand!");
    }

    @Override
    public String toString(){
        return this.expression1.toString() + this.operand + this.expression2.toString();
    }
}
