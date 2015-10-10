package uri;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.text.DecimalFormat;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		double averageGrade = 0.0;
		double percentageAbove = 0.0;
		DecimalFormat df = new DecimalFormat("0.000");
		
		// Read the number of test cases
		int C = readIntegerNumber(input);
		
		for (int i = 0; i < C; i++) {
			averageGrade = 0.0;
			percentageAbove = 0.0;
			
			// Read the number of people in the class
			int N = readIntegerNumber(input);
			
			// Read the final grade for each student and calculate the average grade
			byte grades[] = new byte[N];
			for (int student = 0; student < N; student++) {
				grades[student] = (byte)readIntegerNumber(input);
				averageGrade += grades[student];
			}
			averageGrade /= N;
			
			// Calculate the percentage of students above the average grade
			for (int student = 0; student < N; student++) {
				if (((double)grades[student]) > averageGrade) {
					percentageAbove += 1;
				}
			}
			percentageAbove *= 100.0;
			percentageAbove /= N;
			
			// Write the output
			output.print(df.format(percentageAbove));
			output.print("%\n");
		}
	}
	
	private static int readIntegerNumber(InputStream in) throws IOException {
		int number = 0;
		char ch = 0;
		byte state = 0;
		
		do {
			ch = (char)in.read();
			if (state == 0) {
				if ((ch >= '0') && (ch <= '9')) {
					number = (ch - '0');
					state = 1;
				}
			} else {
				if ((ch >= '0') && (ch <= '9')) {
					number *= 10;
					number += (ch - '0');
				} else {
					break;
				}
			}
		} while ((ch != '\n') || (ch != (char)-1));
		
		return number;
	}

	private static long readLongNumber(InputStream in) throws IOException {
		long number = 0;
		char ch = 0;
		byte state = 0;
		
		do {
			ch = (char)in.read();
			if (state == 0) {
				if ((ch >= '0') && (ch <= '9')) {
					number = (ch - '0');
					state = 1;
				}
			} else {
				if ((ch >= '0') && (ch <= '9')) {
					number *= 10;
					number += (ch - '0');
				} else {
					break;
				}
			}
		} while ((ch != '\n') || (ch != (char)-1));
		
		return number;
	}
	
}
