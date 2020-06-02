package Model.Types;

import Model.Values.Value;

public interface Type {

    boolean equals(Object _other);

    Value defaultValue();

    String toString();
}