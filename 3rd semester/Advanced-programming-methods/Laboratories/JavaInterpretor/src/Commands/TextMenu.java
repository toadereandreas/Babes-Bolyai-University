package Commands;

import java.util.Collection;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.Scanner;
import ADTs.MyDictionary;
import ADTs.MyIDictionary;

public class TextMenu {

    private MyIDictionary<String, Command> commands;

    public TextMenu() {
        this.commands = new MyDictionary<String, Command>();
    }

    public void addCommand(Command c) {
        this.commands.put(c.getKey(), c);
    }

    private void printMenu()
    {
        Iterator<String> iterator = this.commands.keys().iterator();
        while (iterator.hasNext()) {
            String key = iterator.next();
            Command command = this.commands.get(key);
            String line = String.format("%4s : %s", key, command.getDescription());
            System.out.println(line);
        }
    }

    public void show(){
        @SuppressWarnings("resource")
        Scanner scanner=new Scanner(System.in);
        while(true){
            this.printMenu();
            System.out.printf("Input the option: ");
            String key = scanner.nextLine();
            Command command = commands.get(key);
            if(command==null) {
                System.out.println("Invalid ooption.");
                continue;
            }
            command.execute();
        }
    }

}