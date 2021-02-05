public class LightOnCommand implements Command 
{
	Light l;

	public LightOnCommand(Light k) 
	{
		this.l = k;
	}

	public void execute() 
	{
		l.on();
	}
}
