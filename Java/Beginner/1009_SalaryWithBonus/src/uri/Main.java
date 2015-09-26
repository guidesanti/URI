package uri;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		DecimalFormat df = new DecimalFormat("0.00");
		reader.readLine();
		double fixedSalary = Double.valueOf(reader.readLine());
		double sales = Double.valueOf(reader.readLine());
		double finalSalary = (fixedSalary + (0.15D * sales));
		System.out.print("TOTAL = R$ " + df.format(finalSalary) + "\n");
	}

}
