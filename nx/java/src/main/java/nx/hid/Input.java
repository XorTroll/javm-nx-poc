package nx.hid;

public class Input
{
    public static native long getDownInput(long controller);

    public static native long getUpInput(long controller);

    public static native long getHeldInput(long controller);
}