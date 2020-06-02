package Model.Statements;

import ADTs.MyIDictionary;
import Exceptions.MyException;
import Model.ProgramState.PrgState;
import Model.Types.IntType;
import Model.Types.Type;
import Model.Values.BoolValue;
import Model.Values.IntValue;
import Model.Values.Value;

public class VarDeclStmt implements IStmt {
    String id;
    Type type;

    public VarDeclStmt( String _id, Type _type){
        this.id = _id;
        this.type = _type;
    }

    public String getId(){ return this.id; };

    @Override
    public PrgState execute(PrgState state) throws MyException {
        MyIDictionary<String, Value> symbolTable = state.getSymbolTable();
        if( symbolTable.contains(this.id))
             throw new MyException("VarDeclStmt exception: The variable" + this.id + "already exists!");
        else{
            /*
            IntValue defaultInt = new IntValue();
            BoolValue defaultBool = new BoolValue();
            if(this.type.equals(new IntType()))
                symbolTable.put(this.id,defaultInt);
            else
                symbolTable.put(this.id,defaultBool);
            return state;
             */
            symbolTable.put(this.id,this.type.defaultValue());
            return null;
        }
    }

    @Override
    public String toString(MyIDictionary<String, Value> symbolTable) throws MyException {
        return this.type.toString() + " " + this.id;
    }

    public String toString() {
        return this.type.toString() + " " + this.id;
    }
}
