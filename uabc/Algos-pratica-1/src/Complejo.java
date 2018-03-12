public class Complejo {
	//Variables inicializdoes
	double x = 0;
	double y = 0;
	double r = 0;
	double theta = 0;
	//Constructor
	public Complejo(double a, double b) {
		x = a;
		y = b;
		r = Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
		theta = Math.toDegrees(Math.atan(y/x));
	}
	//impresion de un numero complejo
	public void printComplex() {
		System.out.println(x + " + " + y + "i");
	}
	
	public void printPolar() {
		System.out.println("r: " + r);
		System.out.println("theta: " + theta);
	}

}
