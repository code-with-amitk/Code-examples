public class GarageDoorClosedCommand implements Command
{
	GarageDoor g;

	public GarageDoorClosedCommand (GarageDoor o)
	{
		this.g = o;
	}

	public void execute ()
	{
		g.closed();
	}
}
