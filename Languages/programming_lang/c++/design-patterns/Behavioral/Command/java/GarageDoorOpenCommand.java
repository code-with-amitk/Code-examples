public class GarageDoorOpenCommand implements Command
{
	GarageDoor g;

	public GarageDoorOpenCommand (GarageDoor o)
	{
		this.g = o;
	}

	public void execute ()
	{
		g.open();
	}
}
