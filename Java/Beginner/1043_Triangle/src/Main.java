import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public final class Main {

	public static void main(String[] args) throws IOException {
		// Create the reader and writer to the default input and output
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		
		float a;
		float b;
		float c;
		
		// Read the input
		String line = reader.readLine();
		String[] split = line.split(" ");
		a = new Float(split[0]);
		b = new Float(split[1]);
		c = new Float(split[2]);

		if (((a + b) > c) && ((b + c) > a) && ((c + a) > b))
		{
			writer.write(String.format("Perimetro = %2.1f\n", (a + b + c)));
		}
		else
		{
			writer.write(String.format("Area = %2.1f\n", (((a + b) * c) / 2)));
		}
		
		writer.flush();
		reader.close();
		writer.close();
	}

}
