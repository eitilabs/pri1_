#include <stdio.h>
#include <math.h>

	float arrayMax(float[], int);
	float arrayMin(float[], int);

	int main() {
		
		/*
		 * Użytkownik podaje liczbę próbek N i pulsację omega
		 * generacja sygnału wejściowego
		 * generacja sygnału wyjściowego
		 * fukncje arrayMin i arrayMax i ich uzycie do znalezienia minimalnego i maksymalnego sygnalu wyjscia
		 * policzenie amplitudy sygnalu wyjsciowego i jej wydrukowanie na ekran
		 * 
		 * 
		*/
		
		
		
		int N;
		float omega;
		
		int n, i;
		
		int Ma = 10;
		
		float input[2000];
		float output[2000];
		
		float outputMin, outputMax;
		
		float amplitude;
		
		float b[11] = {

			0,
			-0.007856,
			-0.040171,
			-0.103315,
			-0.170762,
			0.800475,
			-0.170762,
			-0.103315,
			-0.040171,
			-0.007856,
			0	
			
		};
		
		printf("Wprowadz wartosc pulsacji: ");
		
		scanf("%f", &omega);
		
		printf("Wprowadz ilosc probek ");
		
		while (1) {
			
			scanf("%d", &N);
			
			if (N >= 2000) {
				
				printf("Liczba probek musi byc mniejsza od 2000. Wprowadz ponownie ilosc probek: ");
				
			}
			else if (N < 20 * 3.14 / omega) {
				
				printf("Nieprawidlowa wartosc N, warunek zadania nie zostal spelniony. Wprowadz ponownie liczbe probek: ");
				
			}
			/*
			else if (N < 1) {
				printf("Liczba probek musi byc wieksza od 0");
			}*/
			
			else {
				
				break;
				
			}
			
		}
		
		
		
		//cannot be larger than 2000
		
		
		

		

		printf("Input:\n");
		
		for (n = 0; n < N; n++) {
			
			input[n] = cos(omega * n);
			
			printf("%f\n", input[n]);
			
		}
		
		printf("Output:\n");
		
		for (n = 0; n < N; n++) {
			
			output[n] = 0;
			
			for (i =0; i <= Ma; i++) {
				
				output[n] += b[i] * input[n - i];
				
			}
			
			printf("%f\n", output[n]);
			
			
		}
		
		outputMin = arrayMin(output, N);
		outputMax = arrayMax(output, N);
		
		//printf("Output max: %f\n", outputMax);
		//printf("Output min: %f\n", outputMin);
		
		amplitude = 0.5 * (outputMax - outputMin);
		
		printf("Amplituda sygnalu wyjsciowego wynosi: %f\n", amplitude);
		
		
		
	
		return 0;
		
		
		
	}
	
float arrayMin(float arr[], int sz) {
	
	float minVal = arr[0];
	
	int n = 0;
	
	for (n = 1; n < sz; n++) {
		
		if (arr[n] < minVal)
			minVal = arr[n];
		
	}
	
	return minVal;
	
}

float arrayMax(float arr[], int sz) {
	
	float maxVal = arr[0];
	
	int n = 0;
	
	for (n = 1; n < sz; n++) {
		
		if (arr[n] > maxVal)
			maxVal = arr[n];
		
	}
	
	return maxVal;
	
}


