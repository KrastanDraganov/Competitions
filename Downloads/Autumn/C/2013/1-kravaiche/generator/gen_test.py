import random;
import sys;
nullModAllowed = False; # is it allowed a[i] % c == 0
nullModPrefixAllowed = False; # is (a[1] + a[2] + ... a[i]) %c == 0 allowed
noPairIsAnswer = True;

def gen_test(c, n, maxInput, minInput):
	print c, n;
	random.seed();
	s = 0;
	mods = [0]*c 
	for i in range(n):
		while(True):
			temp = random.randint(1, maxInput + 1);
			if (temp < minInput):
				continue;
			elif (temp%c == 0 and not nullModAllowed ):
				continue;
			elif ((s + temp) % n == 0 and not nullModPrefixAllowed):
				continue;
			elif (mods[(c + c - temp % c)%c] > 0 and noPairIsAnswer):
				continue;
			else:
				break;
		if(mods[(c + c - temp % c)%c] > 0):
			print >> sys.stderr, "There as an answer of only 2 numbers! This test is weak! Don't use it :P"
		
		mods[temp % c] += 1; 
		s = (s + temp) % n;
		print temp, 
	print ;
	print >> sys.stderr, "Success";

if __name__ == '__main__':
	gen_test(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]), int(sys.argv[4]));
