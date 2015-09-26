package uri;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	private static final int MAX_NUMBER_OF_LINES = 100;
	
	private static final int MAX_LINE_LENGTH = 50;
	
	private enum State {
		READ_N,
		FIND_FIRST_NUMBER,
		FIND_FIRST_WORD,
		READ_WORD,
		FIND_NEXT_WORD,
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
		
		int N = 0;
		String text[] = new String[MAX_NUMBER_OF_LINES];
		State state = State.READ_N;
		int biggestLineLength = 0;
		char currentChar = 0;
		boolean firstTestCase = true;
		
		while (true) {
			// Reset control variables
			state = State.FIND_FIRST_NUMBER;
			biggestLineLength = 0;
			N = 0;
			
			// Read the number of lines for this test case
			while (true) {
				boolean endOfLine = false;
				currentChar = (char)bi.read();
				switch (state) {
					case READ_N:
						if ((currentChar >= '0') && (currentChar <= '9')) {
							N *= 10;
							N += (currentChar - '0');
						} else {
							state = State.FIND_FIRST_WORD;
							endOfLine = true;
						}
					break;
					
					case FIND_FIRST_NUMBER:
						if ((currentChar >= '0') && (currentChar <= '9')) {
							N *= 10;
							N += (currentChar - '0');
							state = State.READ_N;
						}
						break;
					
					default:
						break;
				}
				if (endOfLine) {
					break;
				}
			}
			
			// Test the end of input condition
			if (N == 0) {
				break;
			}
			
			if (firstTestCase) {
				firstTestCase = false;
			} else {
				System.out.print('\n');
			}
			
			// Read the N lines of this test case and do the following:
			// - Remove the leading spaces
			// - Remove the trailing spaces
			// - Remove the extra spaces between words
			// - Find the biggest line length
			for (int i = 0; i < N; i++) {
				StringBuilder str = new StringBuilder(MAX_LINE_LENGTH);
				while (true) {
					boolean endOfLine = false;
					currentChar = (char)bi.read();
					switch (state) {
						case FIND_FIRST_WORD:
							if ((currentChar >= 'A') && (currentChar <= 'Z')) {
								str.append(currentChar);
								state = State.READ_WORD;
							}
						break;
						
						case READ_WORD:
							if ((currentChar >= 'A') && (currentChar <= 'Z')) {
								str.append(currentChar);
							} else if (currentChar == ' ') {
								state = State.FIND_NEXT_WORD;
							} else {
								text[i] = str.toString();
								state = State.FIND_FIRST_WORD;
								endOfLine = true;
								if (text[i].length() > biggestLineLength) {
									biggestLineLength = text[i].length();
								}
							}
							break;
							
						case FIND_NEXT_WORD:
							if ((currentChar >= 'A') && (currentChar <= 'Z')) {
								str.append(' ');
								str.append(currentChar);
								state = State.READ_WORD;
							} else if (currentChar == ' ') {
								// Do nothing, just ignore it
							} else {
								text[i] = str.toString();
								state = State.FIND_FIRST_WORD;
								endOfLine = true;
								if (text[i].length() > biggestLineLength) {
									biggestLineLength = text[i].length();
								}
							}
							break;
						
						default:
							break;
					}
					if (endOfLine) {
						break;
					}
				}
			}
			
			// Write the output by adding the correct padding at the left side of each line
			for (int i = 0; i < N; i++) {
				int paddingLength = (biggestLineLength - text[i].length());
				for (int j = 0; j < paddingLength; j++) {
					System.out.print(' ');
				}
				System.out.printf(text[i]);
				System.out.print('\n');
			}
		}
	}
	
}
