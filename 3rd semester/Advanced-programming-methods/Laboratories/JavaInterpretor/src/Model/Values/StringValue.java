package Model.Values;

import Exceptions.MyException;
import Model.Types.StringType;
import Model.Types.Type;

public class StringValue implements Value {

    private String value;

    public StringValue(){
        this.value = "";
    }

    public StringValue(String _value){
        this.value = _value;
    }

    public String getValue(){
        return this.value;
    }

    @Override
    public Type getType() {
        return new StringType();
    }

    @Override
    public boolean equals(Object _other){
        if( _other instanceof StringValue ){
            StringValue auxiliary = (StringValue) _other;
            return auxiliary.value.equals(this.value);
        }
        else
            return false;
    }

    public String toString(){
        return "'" + this.value.toString() + "'";
    }

    @Override
    public Value copyValue() {
        return new StringValue(this.value);
    }

    @Override
    public Object makeCopy() {
        return new StringValue(this.value);
    }
}
