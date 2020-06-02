package Tests;

import ADTs.MyDictionary;
import ADTs.MyIDictionary;
import Exceptions.MyException;
import Model.Expressions.*;
import Model.Values.BoolValue;
import Model.Values.IntValue;
import Model.Values.Value;

public class TestExpressions implements ITest {

    @Override
    public void run() {
        MyIDictionary<String, Value> fakeDictionary = new MyDictionary<>();
    /*
        LogicExp testAND1 = new LogicExp(new ValueExp(new BoolValue(true)), new ValueExp(new BoolValue(false)),'&');
        LogicExp testAND2 = new LogicExp(new ValueExp(new BoolValue(false)), new ValueExp(new BoolValue(true)),'&');
        LogicExp testAND3 = new LogicExp(new ValueExp(new BoolValue(false)), new ValueExp(new BoolValue(false)),'&');
        LogicExp testAND4 = new LogicExp(new ValueExp(new BoolValue(true)), new ValueExp(new BoolValue(true)),'&');
        try{
            assert testAND1.eval(fakeDictionary).toString() == "false";
            assert testAND2.eval(fakeDictionary).toString() == "false";
            assert testAND3.eval(fakeDictionary).toString() == "false";
            assert testAND4.eval(fakeDictionary).toString() == "true";
        }catch (MyException e) {
            System.out.println("Assert when testing AND logic expression in TestExpression failed.");
        }

        LogicExp testOR1 = new LogicExp(new ValueExp(new BoolValue(true)), new ValueExp(new BoolValue(false)),'|');
        LogicExp testOR2 = new LogicExp(new ValueExp(new BoolValue(false)), new ValueExp(new BoolValue(true)),'|');
        LogicExp testOR3 = new LogicExp(new ValueExp(new BoolValue(false)), new ValueExp(new BoolValue(false)),'|');
        LogicExp testOR4 = new LogicExp(new ValueExp(new BoolValue(true)), new ValueExp(new BoolValue(true)),'|');
        try{
            assert testOR1.eval(fakeDictionary).toString() == "true";
            assert testOR2.eval(fakeDictionary).toString() == "true";
            assert testOR3.eval(fakeDictionary).toString() == "false";
            assert testOR4.eval(fakeDictionary).toString() == "true";
        }catch (MyException e) {
            System.out.println("Assert when testing OR logic expression in TestExpression failed.");
        }

        ValueExp value1 = new ValueExp(new BoolValue(false));
        ValueExp value2 = new ValueExp(new BoolValue(true));
        ValueExp value3 = new ValueExp(new IntValue(2));
        ValueExp value4 = new ValueExp(new IntValue(231));
        assert value1.toString() == "false";
        assert value2.toString() == "true";
    }*/
}}

