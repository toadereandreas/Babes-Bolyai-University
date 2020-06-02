package Model.Values;

import Model.Types.RefType;
import Model.Types.Type;

public class RefValue implements Value {

    private int address;
    private Type locationType;

    public RefValue( int _address, Type _locationType ){
        this.address = _address;
        this.locationType = _locationType;
    }

    public int getAddress(){
        return this.address;
    }

    public void setAddress(int _address) { this.address = _address;}

    public Type getLocationType(){
        return this.locationType;
    }

    @Override
    public Type getType() {
        return new RefType(this.locationType);
    }

    public boolean equals(Object _other){
        if( _other instanceof RefValue ){
            RefValue auxOther = (RefValue) _other;
            return auxOther.address == this.address;
        }
        else
            return false;
    }

    public String toString(){
        return "(" + Integer.toString(this.address) + ", " + this.locationType.toString() + ')';
    }

    public Value copyValue(){
        return new RefValue(this.address,this.locationType);
    }

    @Override
    public Object makeCopy() {
        return new RefValue(this.address, this.locationType);
    }
}
