#include <cstdio>
#include <cstring>

int main(int argc, char *argv[]) {
//  if (argc != 2) {
    //printf("USAGE: ./checker contestant.out\n");
    //return 0;
  //}
  FILE *fin = fopen(argv[3], "r");
  int secret;
  double score;
  fscanf(fin, "%d %lf", &secret, &score);
  if (secret == 32897304) {
    printf("%.10lf\n", score);
  } else {
    printf("0\n");
  }
  return 0;
}
