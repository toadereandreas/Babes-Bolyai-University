package Model.Expressions;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import Exceptions.MyException;
import Model.Types.IntType;
import Model.Values.BoolValue;
import Model.Values.IntValue;
import Model.Values.Value;

public class RelationalExp implements Exp {

    private Exp expression1, expression2;
    private String operand;

    public RelationalExp( Exp _expression1, Exp _expression2, String _operand ){
        this.expression1 = _expression1;
        this.expression2 = _expression2;
        this.operand = _operand;
    }

    @Override
    public Value eval(MyIDictionary<String, Value> symbolTable, MyIHeap<Value> heap) throws MyException {
            Value value1 = this.expression1.eval(symbolTable, heap);
            Value value2 = this.expression2.eval(symbolTable, heap);

            if( value1.getType().equals(new IntType())){
                if( value2.getType().equals(new IntType())) {
                    int intValue1 = ((IntValue) value1).getValue();
                    int intValue2 = ((IntValue) value2).getValue();
                    if( operand.equals("==")) return new BoolValue(intValue1==intValue2);
                    if( operand.equals("!=")) return new BoolValue(intValue1!=intValue2);
                    if( operand.equals("<=")) return new BoolValue(intValue1<=intValue2);
                    if( operand.equals(">=")) return new BoolValue(intValue1>=intValue2);
                    if( operand.equals("<"))  return new BoolValue(intValue1<intValue2);
                    if( operand.equals(">"))  return new BoolValue(intValue1>intValue2);
                    throw new MyException("RelationalExp exception:" + this.operand + " is an invalid operand.");
                }
                else throw new MyException("RelationalExp exception: " + this.expression2.toString() + " does not evaluate to an integer.");
            }
            else throw new MyException("RelationalExp exception: " + this.expression1.toString() + " does not evaluate to an integer.");
    }

    public String toString(){
        return this.expression1.toString() + this.operand + this.expression2.toString();
    }
}
