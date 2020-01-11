package javmnx.helloworld;

import nx.console.ConsoleManager;
import nx.applet.AppletManager;
import nx.hid.Input;

public class Main
{
    public static long ControllerAuto = 10;
    public static long KeyPlus = 1024;

    public static void main(String[] args)
    {
        ConsoleManager.init();

        System.out.println("Hello World, from Java!");

        while(AppletManager.mainLoop())
        {
            // Auto = 10
            long keys = Input.getDownInput(ControllerAuto);
            if((keys & KeyPlus) != 0)
            {
                break;
            }
            
            ConsoleManager.update();
        }

        ConsoleManager.exit();
    }
}