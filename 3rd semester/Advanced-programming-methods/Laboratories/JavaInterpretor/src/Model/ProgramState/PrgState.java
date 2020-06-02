package Model.ProgramState;

import ADTs.*;
import Exceptions.MyException;
import Model.Statements.IStmt;
import Model.Values.Value;

import java.io.BufferedReader;

public class PrgState{

    private MyIStack<IStmt> executionStack;
    private MyIDictionary<String, Value> symbolTable;
    private MyIList<Value> out;
    private IStmt originalProgram;
    private MyIDictionary<String, BufferedReader> fileTable;
    private MyIHeap<Value> heap;
    private static int id = 0;
    private int currentId;

    public static synchronized int addId(){
        id += 1;
        return id;
    }

    public PrgState(MyIStack<IStmt> _stack, MyIDictionary<String,Value> _symbolTable, MyIList<Value> _out, IStmt _program, MyIDictionary<String, BufferedReader> _fileTable, MyIHeap<Value> _heap){
        this.executionStack = _stack;
        this.symbolTable = _symbolTable;
        this.out = _out;
        this.originalProgram = _program;
        this.fileTable = _fileTable;
        this.heap = _heap;
        this.currentId = addId();
    }

    public PrgState(MyIStack<IStmt> _stack, MyIDictionary<String,Value> _symbolTable, MyIList<Value> _out, MyIDictionary<String, BufferedReader> _fileTable, MyIHeap<Value> _heap){
        this.executionStack = _stack;
        this.symbolTable = _symbolTable;
        this.out = _out;
        this.originalProgram = this.executionStack.peek();
        this.fileTable = _fileTable;
        this.heap = _heap;
        this.currentId = addId();
    }

    public PrgState(MyIStack<IStmt> stack)
    {
        this.executionStack = stack;
        this.symbolTable = new MyDictionary<String, Value>();
        this.out = new MyList<Value>();
        this.originalProgram = this.executionStack.peek();
        this.fileTable = new MyDictionary<String, BufferedReader>();
        this.heap = new MyHeap<Value>();
        this.currentId = addId();
    }

    public IStmt getProgram(){
        return this.originalProgram;
    }

    public MyIStack<IStmt> getStack(){
        return this.executionStack;
    }

    public MyIList<Value> getOut(){
        return this.out;
    }

    public MyIDictionary<String, Value> getSymbolTable() {
        return this.symbolTable;
    }

    public MyIHeap<Value> getHeap() { return this.heap;}

    public MyIDictionary<String, BufferedReader> getFileTable() {
        return this.fileTable;
    }

    public void setExecutionStack(MyIStack<IStmt> _executionStack){
        this.executionStack = _executionStack;
    }

    public void setSymbolTable(MyIDictionary<String, Value> _symbolTable){
        this.symbolTable = _symbolTable;
    }

    public void setOut(MyIList<Value> _out){
        this.out = _out;
    }

    public void setProgram(IStmt _program){
        this.originalProgram = _program;
    }

    public void setFileTable(MyIDictionary<String, BufferedReader> _fileTable){
        this.fileTable = _fileTable;
    }

    public void setHeap(MyIHeap<Value> _heap ) { this.heap = _heap;}

    public String toString()
    {
        String result = "Program with id:" + Integer.toString(this.currentId) + "\nExecution stack:";

        try {
            result += this.executionStack.toString(this.symbolTable);
            result += "Symbol table:\n" + this.symbolTable.toString();
            result += "Output:" + this.out.toString();
            result += "\nFile table:\n" + this.fileTable.toString();
            result += "Heap:" + this.heap.toString();
            result += "\n=====================";
        } catch (MyException e){
            System.out.println(e);
        }
        return result;
    }

    public boolean isNotCompleted()
    {
        if (this.executionStack.isEmpty())
            return false;
        return true;
    }

    public PrgState oneStep() throws MyException
    {
        if (this.executionStack.isEmpty())
            throw new MyException("PrgState exception: Empty execution stack");
        IStmt nextInstruction = (IStmt)this.executionStack.pop();
        return nextInstruction.execute(this);
    }

}
