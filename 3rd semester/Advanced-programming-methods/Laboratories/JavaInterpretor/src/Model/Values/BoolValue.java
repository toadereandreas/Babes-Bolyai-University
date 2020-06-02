package Model.Values;

import Model.Types.BoolType;
import Model.Types.Type;

public class BoolValue implements Value {

    private boolean value;

    public BoolValue(){
        this.value = false;
    }

    public BoolValue(boolean _value){
        this.value = _value;
    }

    @Override
    public Type getType() {
        return new BoolType();
    }

    public String toString(){
        return Boolean.toString(this.value);
    }

    @Override
    public Value copyValue() {
        return new BoolValue(this.value);
    }

    public boolean equals(Object _other){
        if( _other instanceof BoolType ) {
            BoolValue auxiliary = (BoolValue) _other;
            return auxiliary.value == this.value;
        }
        else
            return false;
    }

    public boolean getValue(){
        return this.value;
    }

    @Override
    public Object makeCopy() {
        return new BoolValue(this.value);
    }
}
