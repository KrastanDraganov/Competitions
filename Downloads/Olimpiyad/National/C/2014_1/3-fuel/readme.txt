1 test - 12 test 
	N <= 2'000
	Q <= 10'000
	fuel_slow - 100% test cases
	fuel - 100% test cases
	fuel_wrong - 91% test cases

13 test - 25 test 
	3'000 <= N <= 5'000
	100'000 <= Q <= 200'000
	fuel_slow - 0% test cases
	fuel - 100% test cases
	fuel_wrong - 84% test cases

1 test - 25 test 
	10 <= N <= 5'000
	10 <= Q <= 200'000
	fuel_slow - 48% test cases
	fuel - 100% test cases
	fuel_wrong - 88% test cases

Time Complexity:
	fuel - O( QlogQ + N*N ) 
	fuel_slow - O( Q*N )
	fuel_wrong - O( QlogQ + N*N ) // using int type instead of long
