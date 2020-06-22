/*
        remote control(5 slots)
        ----------
        | =     = |//Light on,off
        | -     - |//GarageDoor open,closed
        | +     + |
        | #     # |
        | @     @ |
        -----------
RemoteControl manages a set of command objects(one per button). When a button is pressed corresponding ButtonWasPush() method is called, whic invokes execute() from command.
*/
public class RemoteControl
{
	Command[] onCom;
	Command[] offCom;

	public RemoteControl() {

		onCom = new Command[5];
		offCom = new Command[5];

		Command noCom = new NoCommand();

		for (int i = 0; i < 5; i++) {
			onCom[i] = noCom;
			offCom[i] = noCom;
		}
	}

	public void setCommand(int i, Command on, Command off) 
	{
		onCom[i] = on;	
		offCom[i] = off;
	}

	public void onButtonWasPushed(int i) {
		onCom[i].execute();
	}

	public void offButtonWasPushed(int i) 
	{
		offCom[i].execute();
	}	
}
