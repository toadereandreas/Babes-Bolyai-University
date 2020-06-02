package Model.Expressions;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Types.IntType;
import Model.Values.IntValue;
import Model.Values.Value;

public class ArithmeticExp implements Exp {

    private Exp expression1, expression2;
    private char operand;

    public ArithmeticExp( Exp _expression1, Exp _expression2, char _operand){
        this.expression1 = _expression1;
        this.expression2 = _expression2;
        this.operand = _operand;
    }

    public ArithmeticExp( char _operand, Exp _expression1, Exp _expression2){
        this.expression1 = _expression1;
        this.expression2 = _expression2;
        this.operand = _operand;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symbolTable, MyIHeap<Value> heap) throws MyException {
        Value value1, value2;
        value1 = this.expression1.eval(symbolTable, heap);
        value2 = this.expression2.eval(symbolTable, heap);
        if( value1.getType().equals(new IntType())){
            if( value2.getType().equals(new IntType())){
                IntValue intValue1 = (IntValue)value1;
                IntValue intValue2 = (IntValue)value2;
                int firstOperandValue  = intValue1.getValue();
                int secondOperandValue = intValue2.getValue();
                if( this.operand == '+' ) return new IntValue(firstOperandValue + secondOperandValue);
                if( this.operand == '-' ) return new IntValue(firstOperandValue - secondOperandValue);
                if( this.operand == '*' ) return new IntValue(firstOperandValue * secondOperandValue);
                if( this.operand == '/' ){
                    if( secondOperandValue == 0 )
                        throw new MyException("ArithExp exception: The second operand " + this.expression2.toString() + " is equal to 0!");
                    else
                        return new IntValue(firstOperandValue / secondOperandValue);
                }
                throw new MyException("ArithExp exception: The operand " + this.operand + " is invalid!");
            } else throw new MyException("ArithExp exception: " + this.expression2.toString() + " is not an integer operand!");
        } else throw new MyException("ArithExp exception: " + this.expression1.toString() +  " is not an integer operand!");
    }

    @Override
    public String toString(){
        return this.expression1.toString() + this.operand + this.expression2.toString();
    }
}
