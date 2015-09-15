package uri;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
		
		while (true) {
			String line = bi.readLine();
			int N = Integer.valueOf(line);
			
			if (N == 0) {
				break;
			}
			
			while (true) {
				line = bi.readLine();
				
				String[] lineSplit = line.split(" ");
				
				if (lineSplit[0].equals("0")) {
					break;
				}
				
				Stack<Integer> trainB = new Stack<Integer>();
				for (int i = 0; i < lineSplit.length; i++) {
					trainB.push(Integer.valueOf(lineSplit[i]));
				}
				
				Stack<Integer> station = new Stack<Integer>();
				int curr = N;
				int el = 0;
				boolean result = true;
				
				while (curr > 0) {
					if (!trainB.isEmpty() && !station.isEmpty()) {
						el = trainB.peek();
						if (el == curr) {
							curr--;
							trainB.pop();
						} else {
							el = station.peek();
							if (el == curr) {
								curr--;
								station.pop();
							} else {
								station.push(trainB.pop());
							}
						}
					} else if (!trainB.isEmpty() && station.isEmpty()) {
						el = trainB.pop();
						if (el == curr) {
							curr--;
						} else {
							station.push(el);
						}
					} else if (trainB.isEmpty() && !station.isEmpty()) {
						el = station.pop();
						if (el == curr) {
							curr--;
						} else {
							result = false;
							break;
						}
					} else if (trainB.isEmpty() && station.isEmpty()) {
						break;
					}
				}
				
				if (result) {
					System.out.print("Yes\n");
				} else {
					System.out.print("No\n");
				}
			}
			
			System.out.print("\n");
		}
	}

}
