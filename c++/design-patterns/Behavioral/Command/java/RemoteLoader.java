/*
RemoteLoader creates a number of Command Objects that are loaded into the slots of the Remote Control. Each command objec t encapsulates a request of a home automation device.
*/
public class RemoteLoader {
	public static void main(String[] args) {

		//Slot0=light
                Light l = new Light();
                LightOnCommand lon = new LightOnCommand(l);
                LightOnCommand lof = new LightOnCommand(l);

		//slot1=Garage Control
                GarageDoor d = new GarageDoor();
                GarageDoorOpenCommand gdo = new GarageDoorOpenCommand(d);
                GarageDoorClosedCommand gdc = new GarageDoorClosedCommand(d);

		RemoteControl rc = new RemoteControl();
                rc.setCommand(0, lon, lof);
                rc.setCommand(1, gdo, gdc);

		rc.onButtonWasPushed(0);	//Light on
		rc.onButtonWasPushed(1);	//Garage Door open
		rc.offButtonWasPushed(0);	//Light off
		rc.offButtonWasPushed(1);	//Garage Door closed
	}
}
/*
Output:
# javac *.java

# java RemoteLoader
Light on
Garage Door open
Light on
Garage Door Closed
*/
