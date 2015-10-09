package uri;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
		String line = null;
		String lineSplit[] = null;
		int grandPrix[][] = new int[100][];
		int scoringSystems[][] = new int[10][];
		int rank[] = null;
		int G = 0;
		int P = 0;
		int S = 0;
		int winnerPoints = 0;

		while (true) {
			// Read G and P
			line = bi.readLine();
			lineSplit = line.split(" ");
			G = Integer.valueOf(lineSplit[0]);
			P = Integer.valueOf(lineSplit[1]);
			
			if ((G == 0) && (P == 0)) {
				break;
			}
			
			rank = new int[P];
			winnerPoints = 0;
			
			// Read each Grand Prix result
			for (int i = 0; i < G; i++) {
				line = bi.readLine();
				lineSplit = line.split(" ");
				grandPrix[i] = new int[P];
				for (int j = 0; j < P; j++) {
					grandPrix[i][j] = (Integer.valueOf(lineSplit[j]) - 1);
				}
			}
			
			// Read the number of scoring system (S)
			line = bi.readLine();
			S = Integer.valueOf(line);
			
			// Read each scoring system
			for (int i = 0; i < S; i++) {
				line = bi.readLine();
				lineSplit = line.split(" ");
				int K = Integer.valueOf(lineSplit[0]);
				scoringSystems[i] = new int[K];
				for (int j = 0; j < K; j++) {
					scoringSystems[i][j] = Integer.valueOf(lineSplit[j + 1]);
				}
			}
			
			// Find the winner for each scoring system
			for (int ss = 0; ss < S; ss++) {
				winnerPoints = 0;
				for (int gp = 0; gp < G; gp++) {
					for (int pilot = 0; pilot < P; pilot++) {
						int pilotPosition = grandPrix[gp][pilot];
						if (pilotPosition < scoringSystems[ss].length) {
							rank[pilot] += scoringSystems[ss][pilotPosition];
							if (winnerPoints < rank[pilot]) {
								winnerPoints = rank[pilot];
							}
						}
					}
				}
				
				boolean first = true;
				for (int t = 0; t < rank.length; t++) {
					if (rank[t] == winnerPoints) {
						if (first) {
							first = false;
						} else {
							System.out.print(" ");
						}
						System.out.print(t + 1);
					}
					rank[t] = 0;
				}
				System.out.print('\n');
			}
		}
	}

}
