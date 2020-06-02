package Model.Types;

import Model.Values.RefValue;
import Model.Values.Value;

public class RefType implements Type {

    private Type inner;

    public RefType(Type _inner){
        this.inner = _inner;
    }

    public Type getInner(){
        return this.inner;
    }

    public boolean equals(Object _other){
        if( _other instanceof RefType )
            return this.inner.equals(((RefType) _other).getInner());
        else
            return false;
    }

    public String toString(){
        return "Ref(" + this.inner.toString() + ")";
    }

    @Override
    public Value defaultValue() {
        return new RefValue(0,this.inner);
    }
}
