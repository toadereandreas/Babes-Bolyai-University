package Model.Types;

import Model.Values.BoolValue;
import Model.Values.Value;

public class BoolType implements Type {

    @Override
    public boolean equals(Object _other) {
        if( _other instanceof BoolType )
            return true;
        else
            return false;
    }

    @Override
    public Value defaultValue() {
        return new BoolValue(false);
    }

    @Override
    public String toString(){
        return "bool";
    }
}
