package Model.Values;

import Model.Types.IntType;
import Model.Types.Type;

public class IntValue implements Value {

    private int value;

    public IntValue(){
        this.value = 0;
    }

    public IntValue( int _value ){
        this.value = _value;
    }

    @Override
    public Type getType() {
        return new IntType();
    }

    public String toString(){
        return Integer.toString(this.value);
    }

    @Override
    public Value copyValue() {
        return new IntValue(this.value);
    }

    public boolean equals(Object _other){
        if( _other instanceof IntValue ) {
            IntValue auxiliary = (IntValue) _other;
            return auxiliary.value == this.value;
        }
        else
            return false;
    }

    public int getValue(){
        return this.value;
    }

    @Override
    public Object makeCopy() {
        return new IntValue(this.value);
    }

}
