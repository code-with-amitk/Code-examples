/*
 All RemoteControl commands implements Command interface, which consists execute() method. Remote invokes these actions by calling execute() method.

UNDO BUTTON:
- Purpose of undo: It works like this: say the Living Room Light is off and you press the on button on the remote. Obviously the light turns on. Now if you press the undo button then the last action will be reversed – in this case the light will turn off.

- If we want to add a undo button on remote control, we will place a method undo in Command class.
public interface Command {
	public void execute();
 	public void undo();
}

And override in Light or Garage class.
public class LightOnCommand implements Command {
	...
	public void undo() {
		light.off();
	}
}	
*/

public interface Command {
	public void execute();
}
