public class main{
	public static void main(String[] args) {
		System.out.println("Creating Coffee\n");
		Coffee c = new Coffee();
		c.prepareRecipe();

		System.out.println("\nCreating Tea\n");
		Tea t = new Tea();
		t.prepareRecipe();
	}
}
