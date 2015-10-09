package uri;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	private enum State {
		START,
		READING_WORD,
		READING_POTENTIAL_SYMBOL,
		READING_SYMBOL,
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
		State state = State.START;
		char ch = 0;
		int nWords = 0;
		int wordLength = 0;
		int totalWordLength = 0;
		int averageWordLength = 0;
		boolean lineEnd = false;
		boolean end = true;
		
		while (true) {
			// Read the fist character of the stream
			ch = (char)bi.read();
			if (ch == (char)-1) {
				break;
			}
			
			// Reset control variables
			state = State.START;
			nWords = 0;
			wordLength = 0;
			totalWordLength = 0;
			lineEnd = false;
			end = false;
			
			// Read the remaining characters of process the input
			while (true) {
				switch (state) {
					case START:
						if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) {
							wordLength = 1;
							state = State.READING_WORD;
						} else if ((ch >= '0') && (ch <= '9')) {
							state = State.READING_SYMBOL;
						} else if (ch == ' ') {
							// Do nothing, just ignore
						} else if (ch == '.') {
							state = State.READING_SYMBOL;
						} else if (ch == '\n') {
							lineEnd = true;
						} else {
							end = true;
						}
						break;
						
					case READING_WORD:
						if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) {
							wordLength++;
						} else if ((ch >= '0') && (ch <= '9')) {
							state = State.READING_SYMBOL;
						} else if (ch == ' ') {
							nWords++;
							totalWordLength += wordLength;
							state = State.START;
						} else if (ch == '.') {
							state = State.READING_POTENTIAL_SYMBOL;
						} else if (ch == '\n') {
							nWords++;
							totalWordLength += wordLength;
							lineEnd = true;
						} else {
							end = true;
						}
						break;
						
					case READING_POTENTIAL_SYMBOL:
						if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) {
							state = State.READING_SYMBOL;
						} else if ((ch >= '0') && (ch <= '9')) {
							state = State.READING_SYMBOL;
						} else if (ch == ' ') {
							nWords++;
							totalWordLength += wordLength;
							state = State.START;
						} else if (ch == '.') {
							state = State.READING_SYMBOL;
						} else if (ch == '\n') {
							nWords++;
							totalWordLength += wordLength;
							lineEnd = true;
						} else {
							end = true;
						}
						break;
						
					case READING_SYMBOL:
						if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))) {
							// Do nothing, just ignore
						} else if ((ch >= '0') && (ch <= '9')) {
							// Do nothing, just ignore
						} else if (ch == ' ') {
							state = State.START;
						} else if (ch == '.') {
							// Do nothing, just ignore
						} else if (ch == '\n') {
							lineEnd = true;
						} else {
							end = true;
						}
						break;
						
					default:
						end = true;
						break;
				}
				if (lineEnd || end) {
					break;
				}
				ch = (char)bi.read();
			}
			
			// Print the output
			if (nWords == 0)
			{
				System.out.print("250\n");
			} else {
				averageWordLength = (totalWordLength / nWords);
				if (averageWordLength <= 3) {
					System.out.print("250\n");
				} else if ((averageWordLength == 4) || (averageWordLength == 5)) {
					System.out.print("500\n");
				} else {
					System.out.print("1000\n");
				}
			}
			
			if (end) {
				break;
			}
		}
	}

}
