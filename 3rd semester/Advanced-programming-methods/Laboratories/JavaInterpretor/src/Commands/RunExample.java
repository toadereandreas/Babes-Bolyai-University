package Commands;

import Controller.Controller;
import Exceptions.MyException;

public class RunExample extends Command {

    private Controller ctrl;

    public RunExample(String key_, String description_, Controller ctrl_) {
        super(key_, description_);
        this.ctrl = ctrl_;
    }

    @Override
    public void execute() {
        try {
            ctrl.allStep();
        }
        catch (MyException e) {
            System.out.println(e.toString());
        }
    }

}