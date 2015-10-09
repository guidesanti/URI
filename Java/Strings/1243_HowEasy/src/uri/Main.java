package uri;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	private enum State {
		START,
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
		State state = State.START;
		char ch = 0;
		int nWords = 0;
		int wordsLengthSum = 0;
		
		while (true) {
			// Read the fist character of the stream
			ch = (char)bi.read();
			if (ch == -1) {
				break;
			}
			
			// Reset control variables
			state = State.START;
			nWords = 0;
			wordsLengthSum = 0;
			
			// Read the remaining characters of process the input
			while (true) {
				switch (state) {
					case START:
						break;
					default:
						break;
				}
				ch = (char)bi.read();
			}
		}
	}

}
