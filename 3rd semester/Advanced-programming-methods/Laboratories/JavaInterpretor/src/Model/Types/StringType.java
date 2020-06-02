package Model.Types;

import Model.Values.StringValue;
import Model.Values.Value;

public class StringType implements Type {

    @Override
    public boolean equals(Object _other ){
        if( _other instanceof BoolType )
            return true;
        else
            return false;
    }

    @Override
    public Value defaultValue() {
        return new StringValue("");
    }

    @Override
    public String toString(){
        return "string";
    }
}
