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

/*
$ javac *.java
$ java main
Creating Coffee

Boiling water
Adding Coffee
Pouring into cup
Adding Sugar and Milk

Creating Tea

Boiling water
Adding tea
Pouring into cup
Adding Lemon
*/
