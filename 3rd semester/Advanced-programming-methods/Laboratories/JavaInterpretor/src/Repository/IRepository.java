package Repository;

import Exceptions.MyException;
import Model.ProgramState.PrgState;

import java.util.List;

public interface IRepository<T> {

    public int getLength();

    public void add(T _element) throws MyException;

    public void remove(T _element);

    public void remove(int _index) throws MyException;

    public void update(T _element);

    public T getElement(int _position) throws MyException;

    // PrgState getCrtPrg();

    // public void logPrgStateExec( ) throws MyException;

    public void logPrgStateExec(PrgState _prgState) throws MyException;

    public List<T> getPrgList();

    public void setPrgList(List<T> _prgList);
}
