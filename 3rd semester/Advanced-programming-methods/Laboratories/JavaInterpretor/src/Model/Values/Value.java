package Model.Values;
import Model.Types.Type;

public interface Value {

    Type getType();

    boolean equals(Object other);

    String toString();

    Value copyValue();

    public Object makeCopy();
}
