public class StarbuzzCoffee {
	public static void main(String args[]) {
		Beverage ObjEspresso = new Espresso();
		System.out.println(ObjEspresso.getDescription()
		+ " $" + ObjEspresso.cost());

		Beverage ObjDarkRoast = new DarkRoast();
		Beverage ObjMocha1 = new Mocha(ObjDarkRoast);
		Beverage ObjMocha2 = new Mocha(ObjMocha1);
		Beverage ObjWhip = new Whip(ObjMocha2);
		System.out.println(ObjWhip.getDescription()
				+ " $" + ObjWhip.cost());
	}
}
