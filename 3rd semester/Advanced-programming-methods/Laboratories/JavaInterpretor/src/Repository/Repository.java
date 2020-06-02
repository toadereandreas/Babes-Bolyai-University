package Repository;

import Exceptions.MyException;
import Model.ProgramState.PrgState;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Vector;

public class Repository<T> implements IRepository<T> {

    private List<T> elements;
    private String filePath;
    // private int maximumLength;
    // private int counter;

    public Repository(String _filePath){
        //this.counter = 0;
        //this.maximumLength = 1000;
        this.elements = new Vector<T>();
        this.filePath = _filePath;
        try
        {
            //before we begin the program, we create the file and EMPTY it of possible previous content
            PrintWriter writer = new PrintWriter(this.filePath);
            writer.print("");
            writer.close();
        }
        catch (IOException e) {
        }
    }

    @Override
    public int getLength() {
        //return this.counter;
        return this.elements.size();
    }

    @Override
    public void add(T _element) throws MyException {
        /* if( this.counter < 1000 ){
            for( int index = 0; index <= this.counter; ++index){
                if( _element.equals(this.elements[index]))
                    return;
            }
            this.elements[this.counter] = _element;
            this.counter = this.counter + 1;
        } else throw new MyException("Repository exception: The repository is full.");*/
        this.elements.add(_element);
    }

    @Override
    public void remove(T _element) {
        /* for (int index = 0; index <= this.counter; index++)
        {
            if (_element.equals(this.elements[index]))
            {
                this.elements[index] = this.elements[this.counter - 1];
                this.counter--;
                return;
            }
        }*/
        for( int index = 0; index < this.elements.size(); ++index ) {
            if( this.elements.equals(this.elements.get(index))){
                this.elements.remove(index);
                return;
            }
        }
    }

    @Override
    public void remove(int _index) throws MyException {
        /* if (this.counter > 0 && _index <= this.counter - 1) {
            this.elements[_index] = this.elements[this.counter - 1];
            this.counter--;
            return;
        }
        else throw new MyException("Repository exception: Deleting from an invalid position from repository.\n");*/
        if( _index < this.elements.size() ){
            this.elements.remove(_index);
        } else throw new MyException("Repository exception: Deleting from an invalid position from repository.\n");
    }

    @Override
    public void update(T _element) {
        /* for (int index = 0; index <= this.counter; index++) {
            if (_element.equals(this.elements[index])) {
                this.elements[index] = _element;
                return;
            }
        }*/
        for( int index = 0; index < this.elements.size(); ++index ){
            if( this.elements.equals(this.elements.get(index))){
                this.elements.add(index,_element);
            }
        }
    }

    @Override
    public T getElement(int _position) throws MyException {
        /*if (_position >= this.counter)
            throw new MyException("Repository exception: Invalid position.\n");
        final T result = (T)this.elements[_position];
        return result;*/
        if( _position < this.elements.size()) {
            return this.getElement(_position);
        } else throw new MyException("Repository exception: Invalid position.\n");
    }

    /*
    @Override
    public PrgState getCrtPrg() {
        if (this.counter == 0)
            return null;
        return (PrgState) this.elements[this.counter - 1];
    }*/

    @Override
    public void logPrgStateExec(PrgState _prgState) throws MyException {
        try
        {
            PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.filePath, true)));
            logFile.write(_prgState.toString() + "\n\n");
            logFile.close();
        }
        catch (IOException e)
        {throw new MyException("I/O Exception!");}
    }

    @Override
    public List<T> getPrgList() {
        return this.elements;
    }

    @Override
    public void setPrgList(List<T> _prgList) {
        this.elements = _prgList;
    }

    /* It was used before implementing concurrent programming
    @Override
    public void logPrgStateExec() throws MyException{
        try{
            PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.filePath,true)));
            if( this.elements[0] instanceof PrgState){
                PrgState programState = (PrgState)this.elements[0];
                logFile.write(programState.toString());
            }
            logFile.close();
        } catch( IOException exception){
            throw new MyException("Repository exception: IOException in logPrgStateExec.");
        }
    }*/
}
