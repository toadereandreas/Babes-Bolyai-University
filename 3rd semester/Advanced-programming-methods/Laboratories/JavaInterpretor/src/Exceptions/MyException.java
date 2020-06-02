package Exceptions;

public class MyException extends Exception {

    public MyException() {}

    public MyException( String _message ){
        super(_message);
    }
}