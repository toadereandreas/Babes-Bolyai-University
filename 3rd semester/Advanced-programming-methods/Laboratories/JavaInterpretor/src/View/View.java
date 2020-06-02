/*package View;

import java.util.Scanner;

import ADTs.MyDictionary;
import ADTs.MyIDictionary;
import ADTs.MyStack;
import Controller.Controller;
import Exceptions.MyException;
import Model.Statements.*;
import Model.Values.*;
import Model.Types.*;
import Model.Expressions.*;
import Model.ProgramState.PrgState;
import Repository.Repository;
import Tests.ITest;
import Tests.TestExpressions;

public class View {

    static private Controller ctrl = new Controller(new Repository<PrgState>("file1.txt"));

    View()
    {
    }

    public static void main(String[] args) throws MyException
    {
        //inserting in the repository(CONTAINED BY THE CONTROLLER) different ProgramStates
        //hardcoding some examples...


        AssignStmt xasd = new AssignStmt("v",new ArithExp(new ValueExp(new IntValue(1)), new ValueExp(new IntValue(2)),'+'));
        MyIDictionary<String, Value> fakeDictionary = new MyDictionary<>();
        //System.out.println(xasd.toString(fakeDictionary));

        ITest test = new TestExpressions();
        test.run();


        Scanner keyboard = new Scanner(System.in);

        while (true)
        {
            String str = keyboard.nextLine();
            String[] inputs = str.split(" ", -1);
            try
            {
                if (inputs.length == 1 && inputs[0].equals("exit"))
                    break;
                if (inputs.length == 4 && inputs[0].equals("input") && inputs[1].equals("a") && inputs[2].equals("program"))
                {
                    try
                    {
                        int value = Integer.parseInt(inputs[3]);
                        if (value == 0)
                        {
                            IStmt stmt= new CompStmt(new VarDeclStmt("v",new IntType()),
                                    new CompStmt(new AssignStmt("v",new ValueExp(new IntValue(2))), new PrintStmt(new VarExp("v"))));
                            MyStack<IStmt> stack = new MyStack<IStmt>(stmt);
                            PrgState prg = new PrgState(stack);
                            ctrl.addProgramState(prg);
                        }
                        else if (value == 1)
                        {
                            IStmt stmt = new CompStmt( new VarDeclStmt("a",new IntType()), new CompStmt(new VarDeclStmt("b",new IntType()),
                                    new CompStmt(new AssignStmt("a", new ArithExp('+',new ValueExp(new IntValue(2)),new
                                            ArithExp('*',new ValueExp(new IntValue(3)), new ValueExp(new IntValue(5))))),
                                            new CompStmt(new AssignStmt("b",new ArithExp('+',new VarExp("a"), new
                                                    ValueExp(new IntValue(1)))), new PrintStmt(new VarExp("b"))))));
                            MyStack<IStmt> stack = new MyStack<IStmt>(stmt);
                            PrgState prg = new PrgState(stack);
                            ctrl.addProgramState(prg);
                        }
                        else if (value == 2)
                        {
                            IStmt stmt = new CompStmt(new VarDeclStmt("a",new BoolType()),
                                    new CompStmt(new VarDeclStmt("v", new IntType()),
                                            new CompStmt(new AssignStmt("a", new ValueExp(new BoolValue(true))),
                                                    new CompStmt(new IfStmt(new VarExp("a"),new AssignStmt("v",new ValueExp(new
                                                            IntValue(2))), new AssignStmt("v", new ValueExp(new IntValue(3)))), new PrintStmt(new
                                                            VarExp("v"))))));
                            MyStack<IStmt> stack = new MyStack<IStmt>(stmt);
                            PrgState prg = new PrgState(stack);
                            ctrl.addProgramState(prg);
                        }
                        else if (value == 3)
                        {
                            IStmt stmt5 = new CompStmt(new VarDeclStmt("varf", new StringType()), new CompStmt(new AssignStmt("varf", new ValueExp(new StringValue("test.in"))),
                                    new CompStmt(new openRFile(new VarExp("varf")),
                                            new CompStmt(new VarDeclStmt("varc", new IntType()),
                                                    new CompStmt(new readFile(new VarExp("varf"), "varc"),
                                                            new CompStmt(new PrintStmt(new VarExp("varc")),
                                                                    new CompStmt(new readFile(new VarExp("varf"), "varc"),
                                                                            new CompStmt(new PrintStmt(new VarExp("varc")),
                                                                                    new PrintStmt(new VarExp("varc"))))))))));
                            MyStack<IStmt> stack = new MyStack<IStmt>(stmt5);
                            PrgState prg = new PrgState(stack);
                            ctrl.addProgramState(prg);
                        }
                        else
                            throw new MyException("Inputed invalid program!\n");

                    }
                    catch (NumberFormatException e)
                    {
                        System.out.println(e.toString());
                        continue;
                    }
                }
                else if (inputs.length == 3 && inputs[0].equals("one") && inputs[1].equals("step") && inputs[2].equals("evaluation"))
                {
                    ctrl.oneStep(0, true);
                }
                else if (inputs.length == 2 && inputs[0].equals("complete") && inputs[1].equals("evaluation"))
                {
                    ctrl.allStep(0, true);
                }
                else
                    throw new MyException("Invalid input!\n");
            }
            catch (MyException e)
            {
                System.out.println(e.toString());
                continue;
            }
        }
    }
}*/
package View;

import ADTs.MyStack;
import Commands.*;
import Controller.Controller;
import Exceptions.MyException;
import Model.Expressions.*;
import Model.Statements.*;
import Model.ProgramState.*;
import Repository.Repository;
import Model.Types.*;
import Model.Values.*;

public class View {

    public static void main(String[] args)
    {
        //hardcoding the first example...
        IStmt stmt1= new CompStmt(new VarDeclStmt("v",new IntType()),
                new CompStmt(new AssignStmt("v",new ValueExp(new IntValue(2))), new PrintStmt(new VarExp("v"))));
        MyStack<IStmt> stack1 = new MyStack<IStmt>(stmt1);
        PrgState prg1 = new PrgState(stack1);
        Controller ctrl1 = new Controller(new Repository<PrgState>("file1.txt"));
        try
        {
            ctrl1.addProgramState(prg1);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        //example 2
        IStmt stmt2= new CompStmt( new VarDeclStmt("a",new IntType()), new CompStmt(new VarDeclStmt("b",new IntType()),
                new CompStmt(new AssignStmt("a", new ArithmeticExp('+',new ValueExp(new IntValue(2)),new
                        ArithmeticExp('*',new ValueExp(new IntValue(3)), new ValueExp(new IntValue(5))))),
                        new CompStmt(new AssignStmt("b",new ArithmeticExp('+',new VarExp("a"), new
                                ValueExp(new IntValue(1)))), new PrintStmt(new VarExp("b"))))));
        MyStack<IStmt> stack2 = new MyStack<IStmt>(stmt2);
        PrgState prg2 = new PrgState(stack2);
        Controller ctrl2 = new Controller(new Repository<PrgState>("file2.txt"));
        try
        {
            ctrl2.addProgramState(prg2);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        //example 3
        IStmt stmt3= new CompStmt(new VarDeclStmt("a",new BoolType()),
                new CompStmt(new VarDeclStmt("v", new IntType()),
                        new CompStmt(new AssignStmt("a", new ValueExp(new BoolValue(true))),
                                new CompStmt(new IfStmt(new VarExp("a"),new AssignStmt("v",new ValueExp(new
                                        IntValue(2))), new AssignStmt("v", new ValueExp(new IntValue(3)))), new PrintStmt(new
                                        VarExp("v"))))));
        MyStack<IStmt> stack3 = new MyStack<IStmt>(stmt3);
        PrgState prg3 = new PrgState(stack3);
        Controller ctrl3 = new Controller(new Repository<PrgState>("file3.txt"));
        try
        {
            ctrl3.addProgramState(prg3);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        //example 4
        IStmt stmt4= new CompStmt(new VarDeclStmt("a",new BoolType()),
                new CompStmt(new VarDeclStmt("v", new IntType()),
                        new CompStmt(new AssignStmt("a", new ValueExp(new BoolValue(true))),
                                new CompStmt(new IfStmt(new RelationalExp(new ValueExp(new IntValue(4)), new ValueExp(new IntValue(4)), ">="),
                                        new AssignStmt("v",new ValueExp(new
                                                IntValue(2))), new AssignStmt("v", new ValueExp(new IntValue(3)))), new PrintStmt(new
                                        VarExp("v"))))));
        MyStack<IStmt> stack4 = new MyStack<IStmt>(stmt4);
        PrgState prg4 = new PrgState(stack4);
        Controller ctrl4 = new Controller(new Repository<PrgState>("file4.txt"));
        try
        {
            ctrl4.addProgramState(prg4);
        }
        catch (MyException e)
        {}

        //example5
        IStmt stmt5 = new CompStmt(new VarDeclStmt("varf", new StringType()), new CompStmt(new AssignStmt("varf", new ValueExp(new StringValue("test.in"))),
                new CompStmt(new openRFile(new VarExp("varf")),
                        new CompStmt(new VarDeclStmt("varc", new IntType()),
                                new CompStmt(new readFile(new VarExp("varf"), "varc"),
                                        new CompStmt(new PrintStmt(new VarExp("varc")),
                                                new CompStmt(new readFile(new VarExp("varf"), "varc"),
                                                        new CompStmt(new PrintStmt(new VarExp("varc")),
                                                                new closeRFile(new VarExp("varf"))))))))));


        MyStack<IStmt> stack5 = new MyStack<IStmt>(stmt5);
        PrgState prg5 = new PrgState(stack5);
        Controller ctrl5 = new Controller(new Repository<PrgState>("file5.txt"));
        try
        {
            ctrl5.addProgramState(prg5);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        IStmt stmt6 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())),
                new CompStmt(new newStmt("v", new ValueExp(new IntValue(3))), new newStmt("v", new ValueExp(new IntValue(5)))));

        //example6
        MyStack<IStmt> stack6 = new MyStack<IStmt>(stmt6);
        PrgState prg6 = new PrgState(stack6);
        Controller ctrl6 = new Controller(new Repository<PrgState>("file6.txt"));
        try
        {
            ctrl6.addProgramState(prg6);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        //example7
        IStmt stmt7 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())),
                new CompStmt(new newStmt("v", new ValueExp(new IntValue(20))),
                        new CompStmt(new PrintStmt(new readHeap(new VarExp("v"))),
                                new CompStmt(new writeHeap("v", new ValueExp(new IntValue(30))),
                                        new PrintStmt(new ArithmeticExp('+', new readHeap(new VarExp("v")), new ValueExp(new IntValue(5))))))));
        MyStack<IStmt> stack7 = new MyStack<IStmt>(stmt7);
        PrgState prg7 = new PrgState(stack7);
        Controller ctrl7 = new Controller(new Repository<PrgState>("file7.txt"));
        try
        {
            ctrl7.addProgramState(prg7);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        //example8
        IStmt stmt8 = new CompStmt(new VarDeclStmt("v", new RefType(new IntType())),
                new CompStmt(new newStmt("v", new ValueExp(new IntValue(20))),
                        new CompStmt(new VarDeclStmt("a", new RefType(new RefType(new IntType()))),
                                new CompStmt(new newStmt("a", new VarExp("v")),
                                        new CompStmt(new newStmt("v", new ValueExp(new IntValue(30))),
                                                new CompStmt(new PrintStmt(new readHeap(new readHeap(new VarExp("a")))),new NopStmt()))))));

        MyStack<IStmt> stack8 = new MyStack<IStmt>(stmt8);
        PrgState prg8 = new PrgState(stack8);
        Controller ctrl8 = new Controller(new Repository<PrgState>("file8.txt"));
        try
        {
            ctrl8.addProgramState(prg8);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        //example9
        IStmt stmt9 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(4))),
                        new CompStmt(new WhileStmt(new RelationalExp(new VarExp("v"), new ValueExp(new IntValue(0)), ">"),
                                new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithmeticExp('-', new VarExp("v"), new ValueExp(new IntValue(1)))))),
                                new PrintStmt(new VarExp("v")))));
        MyStack<IStmt> stack9 = new MyStack<IStmt>(stmt9);
        PrgState prg9 = new PrgState(stack9);
        Controller ctrl9 = new Controller(new Repository<PrgState>("file9.txt"));
        try
        {
            ctrl9.addProgramState(prg9);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        // example 10
        IStmt stmt10 = new CompStmt(new VarDeclStmt("i", new IntType()),new forStmt(new AssignStmt("i", new ValueExp(new IntValue(0))), new RelationalExp(new VarExp("i"),new ValueExp(new IntValue(3)),"<"),
                new PrintStmt(new VarExp("i")),new AssignStmt("i", new ArithmeticExp('+', new VarExp("i"), new ValueExp(new IntValue(1))))));
        MyStack<IStmt> stack10 = new MyStack<IStmt>(stmt10);
        PrgState prg10 = new PrgState(stack10);
        Controller ctrl10 = new Controller(new Repository<PrgState>("file10.txt"));
        try{
            ctrl10.addProgramState(prg10);
        }
        catch(MyException e){
            System.out.println(e.toString());
        }

        //example 11
        IStmt stmt11 = new CompStmt(new VarDeclStmt("v", new IntType()),
                new CompStmt(new VarDeclStmt("a", new RefType(new IntType())),
                        new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(10))),
                                new CompStmt(new newStmt("a", new ValueExp(new IntValue(22))),
                                        new CompStmt(new forkStmt(new CompStmt(new writeHeap("a", new ValueExp(new IntValue(30))),
                                                new CompStmt(new AssignStmt("v", new ValueExp(new IntValue(32))),
                                                        new CompStmt(new PrintStmt(new VarExp("v")),
                                                                new PrintStmt(new readHeap(new VarExp("a"))))))),
                                                new CompStmt(new PrintStmt(new VarExp("v")),
                                                        new PrintStmt(new readHeap(new VarExp("a")))))))));

        MyStack<IStmt> stack11 = new MyStack<IStmt>(stmt11);
        PrgState prg11 = new PrgState(stack11);
        Controller ctrl11 = new Controller(new Repository<PrgState>("file11.txt"));
        try
        {
            ctrl11.addProgramState(prg11);
        }
        catch (MyException e)
        {
            System.out.println(e.toString());
        }

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1","Run 1st example",ctrl1));
        menu.addCommand(new RunExample("2","Run 2nd example",ctrl2));
        menu.addCommand(new RunExample("3","Run 3rd example",ctrl3));
        menu.addCommand(new RunExample("4","Run 4th example",ctrl4));
        menu.addCommand(new RunExample("5","Run 5th example",ctrl5));
        menu.addCommand(new RunExample("6","Run 6th example",ctrl6));
        menu.addCommand(new RunExample("7","Run 7th example",ctrl7));
        menu.addCommand(new RunExample("8","Run 8th example",ctrl8));
        menu.addCommand(new RunExample("9","Run 9th example",ctrl9));
        menu.addCommand(new RunExample("10","Run 10th example",ctrl10));
        menu.addCommand(new RunExample("11","Run 11th example",ctrl11));
        menu.show();
    }

}