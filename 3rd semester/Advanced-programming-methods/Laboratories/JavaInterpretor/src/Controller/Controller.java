package Controller;

import ADTs.MyIDictionary;
import ADTs.MyIHeap;
import ADTs.MyIStack;
import Exceptions.MyException;
import Model.ProgramState.PrgState;
import Model.Statements.IStmt;
import Model.Values.RefValue;
import Model.Values.Value;
import Repository.IRepository;

import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {

    private IRepository<PrgState> repository;
    private ExecutorService executor;

    public Controller(IRepository<PrgState> _repository)
    {
        this.repository = _repository;
        this.executor = Executors.newFixedThreadPool(16);
    }

    public PrgState executeStep(PrgState _programState) throws MyException
    {
        MyIStack<IStmt> stack = _programState.getStack();
        if (stack.isEmpty())
            throw new MyException("Controller exception: Empty Execution Stack!");
        IStmt nextInstruction = (IStmt)stack.pop();
        nextInstruction.execute(_programState);
        return _programState;
    }

    public void oneStepForAllPrg(List<PrgState> prgList)
    {
        List<Callable<PrgState>> callList = prgList.stream()
                .map((PrgState p) -> (Callable<PrgState>)(() -> {return p.oneStep();}))
                .collect(Collectors.toList());


        List<PrgState> newPrgList = null;
        try
        {
            newPrgList = this.executor.invokeAll(callList). stream()
                    .map(future -> {
                        try {
                            return future.get();
                        } catch (InterruptedException e) { System.out.printf("Controller exception: Interrupted exception.");
                        } catch (ExecutionException e) { e.printStackTrace(System.out);}
                        return null;
                    })
                    .filter(p -> p!=null)
                    .collect(Collectors.toList());
        }
        catch (InterruptedException e) {System.out.printf("Controller exception: interrpted exception.");}

        prgList.addAll(newPrgList); //add the new created threads to the list of existing threads

        this.repository.setPrgList(prgList);

        prgList.forEach(prg ->{ try { this.repository.logPrgStateExec(prg); } catch (MyException e) {} });

    }

    public void allStep() throws MyException
    {
        this.executor = Executors.newFixedThreadPool(16);
        List<PrgState> prgList=removeCompletedPrg(this.repository.getPrgList());

        while (prgList.size() > 0)
        {
            List<Integer> symTableAddress = new LinkedList<Integer>();
            for (int index = 0; index < prgList.size(); ++index)
            {
                List<Integer> auxTableAddress = this.getAddressFromSymbolTable( prgList.get(index).getSymbolTable());
                symTableAddress.addAll(auxTableAddress);
            }
            //The Heap is common to all of the Program States, so we can use prgList.get(0).getHeap().
            List<Integer> heapAddress = this.getAddressFromHeap(prgList.get(0).getHeap());
            prgList.get(0).getHeap().addEntrySet(this.safeGarbageCollector(symTableAddress, heapAddress, prgList.get(0).getHeap()));

            oneStepForAllPrg(prgList);
            prgList=removeCompletedPrg(this.repository.getPrgList());
        }
        this.executor.shutdownNow();
        this.repository.setPrgList(prgList);
    }

    /*
    public void allStep(int _index) throws MyException
    {
        PrgState _programState = this.repository.getElement(_index);
        while (!(_programState.getStack().isEmpty())) {
            executeStep(_programState);
            List<Integer> symbolTableAddress = this.getAddressFromSymbolTable( _programState.getSymbolTable());
            List<Integer> heapAddress = this.getAddressFromHeap(_programState.getHeap());
            _programState.getHeap().addEntrySet(this.safeGarbageCollector(symbolTableAddress, heapAddress, _programState.getHeap()));
            this.repository.logPrgStateExec();
        }
        System.out.println(this.repository.getElement(_index).getOut().toString());
    }*/

    /*
    public void oneStep(int _index) throws MyException
    {
        PrgState _programState = this.repository.getElement(_index);
        if (!(_programState.getStack().isEmpty())) {
            executeStep(_programState);
            this.repository.logPrgStateExec();
        }
        System.out.println(this.repository.getElement(_index).getOut().toString());
    }*/

    /*
    public void allStep(int _index, boolean _displayFlag) throws MyException
    {
        PrgState _programState = this.repository.getElement(_index);
        while (!(_programState.getStack().isEmpty()))
        {
            executeStep(_programState);
            List<Integer> symbolTableAddress = this.getAddressFromSymbolTable( _programState.getSymbolTable());
            Iterator<Integer> it = symbolTableAddress.iterator();
            List<Integer> heapAddress = this.getAddressFromHeap(_programState.getHeap());
            _programState.getHeap().addEntrySet(this.safeGarbageCollector(symbolTableAddress, heapAddress, _programState.getHeap()));
            this.repository.logPrgStateExec();
            if (_displayFlag)
                System.out.println(_programState.toString());
        }

        if (!_displayFlag) //we display only the final output
            System.out.println(this.repository.getElement(_index).getOut().toString());
    }*/

    /*
    public void oneStep(int _index, boolean _displayFlag) throws MyException
    {
        PrgState _programState = this.repository.getElement(_index);
        if (!(_programState.getStack().isEmpty()))
        {
            executeStep(_programState);
            this.repository.logPrgStateExec();
            if (_displayFlag)
                System.out.println(_programState.toString());
        }
    }*/

    public void addProgramState(PrgState _programState) throws MyException
    {
        if (this.repository.getLength() > 0)
            this.repository.remove(0);
        this.repository.add(_programState);
    }

    public List<Integer> getAddressFromSymbolTable(MyIDictionary<String, Value> symTable)
    {
        return symTable.elements().stream()
                .filter(v-> v instanceof RefValue)
                .map(v-> {RefValue v1 = (RefValue)v; return v1.getAddress();})
                .collect(Collectors.toList());
    }

    public List<Integer> getAddressFromHeap(MyIHeap<Value> heap)
    {

        return heap.elements().stream()
                .filter(v-> v instanceof RefValue)
                .map(v-> {RefValue v1 = (RefValue)v; return v1.getAddress();})
                .collect(Collectors.toList());
    }

    public Map<Integer, Value> safeGarbageCollector(Collection<Integer> symbolTableAddress, Collection<Integer> heapAddress, MyIHeap<Value> heap)
    {
        Map<Integer, Value> heapContent =  heap.entrySet();
        return heapContent.entrySet().stream()
                .filter(e->symbolTableAddress.contains(e.getKey()) || heapAddress.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public List<PrgState> removeCompletedPrg(List<PrgState> inPrgList) {
        return inPrgList.stream()
                .filter(p -> p.isNotCompleted())
                .collect(Collectors.toList());
    }
}