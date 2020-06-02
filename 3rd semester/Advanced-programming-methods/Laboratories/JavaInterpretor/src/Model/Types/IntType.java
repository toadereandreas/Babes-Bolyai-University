package Model.Types;

import Model.Values.IntValue;
import Model.Values.Value;

public class IntType implements Type {

    @Override
    public boolean equals( Object _other){
        if( _other instanceof IntType)
            return true;
        else
            return false;
    }

    @Override
    public Value defaultValue(){
        return new IntValue(0);
    }

    @Override
    public String toString(){
        return "int";
    }
}
