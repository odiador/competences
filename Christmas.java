import java.util.Scanner;

public class Christmas {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Radios y distancia entre centros
        double r1 = sc.nextInt();  // Radio del primer círculo
        double r2 = sc.nextInt();  // Radio del segundo círculo


        // Calcular el coseno del ángulo usando el teorema del coseno
        double cosTheta = (Math.pow(r1, 2) + Math.pow(r1, 2) - Math.pow(r2, 2)) / (2 * r1 * r1);

        // Asegurarse que el valor esté entre -1 y 1
        cosTheta = Math.max(-1, Math.min(1, cosTheta));

        // Obtener el ángulo en radianes
        double theta = Math.acos(cosTheta);

        // Fracción del perímetro (ángulo en relación a 2π)
        double fractionOfPerimeter = (2 * theta) / (2 * Math.PI);

        // Convertir a porcentaje
        double percentageOfPerimeter = 1 - fractionOfPerimeter;

        // Imprimir el resultado
        System.out.println(percentageOfPerimeter);
    }
}

