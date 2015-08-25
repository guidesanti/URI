import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Stack;


public final class Main {

	public static void main(String[] args) throws IOException {
		// Create the reader and writer to the default input and output
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		
		ArrayList<String> output = new ArrayList<String>();
		
		while (true)
		{
			int size = (new Integer(reader.readLine())).intValue();
			if (size == 0)
			{
				break;
			}
			while (true)
			{
				String line = reader.readLine();
				String[] split = line.split(" ");
				if (split[0].equals("0"))
				{
					break;
				}
				Stack<Integer> stackA = new Stack<Integer>();
				Stack<Integer> stackB = new Stack<Integer>();
				Stack<Integer> stackC = new Stack<Integer>();
				// swap the values at the left and right indices
				/*for (int left = 0, right = split.length - 1; left < right; left++, right--) {
			        String temp = split[left];
			        split[left]  = split[right];
			        split[right] = temp;
			    }*/
				for (int i = 0; i < size; i++)
				{
					stackB.push(new Integer(split[i]));
				}
				
				boolean fail = false;
				int aux = 0;
				for (int i = 1; i <= size; i++)
				{
					aux = 0;
					if (!stackC.isEmpty() && (stackC.peek() == i))
					{
						stackA.push(stackC.pop());
					}
					else
					{
						if (!stackB.isEmpty())
						{
							boolean found = false;
							while (!stackB.isEmpty())
							{
								aux = stackB.pop();
								if (aux == i)
								{
									stackA.push(aux);
									found = true;
									break;
								}
								else
								{
									stackC.push(aux);
								}
							}
							if (!found)
							{
								fail = true;
								break;
							}
						}
						else
						{
							fail = true;
						}
					}
					if (fail)
					{
						break;
					}
				}
				if (!stackB.isEmpty() || !stackC.isEmpty())
				{
					fail = true;
				}
				
				if (fail)
				{
					output.add("No\n");
				}
				else
				{
					output.add("Yes\n");
				}
			}
			output.add("\n");
		}
		
		for (int i = 0; i < output.size(); i++)
		{
			writer.write(output.get(i));
		}

		writer.flush();
		reader.close();
		writer.close();
	}

}
