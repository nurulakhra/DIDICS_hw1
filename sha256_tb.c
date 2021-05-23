#include <stdio.h>
#include <math.h>
#include "sha256.h"

int main() {
 FILE *fp;
 SHA256_CTX *ctx;
 uchar data[64] = "This is a test"; // Input
 uchar hash[64];                   // Output

 fp = fopen("out.dat", "w");
 sha256_top(data, hash);           // Calling sha256_top function

 int i;
 for(i=0; i<32; i++){
  if(hash[i] < 16)fprintf(fp, "0"); // Regulate the length of byte size
  fprintf(fp, "%x", hash[i]);
 }
 fprintf(fp, "\n"); fclose(fp);

 printf("Comparing results against golden output\n");
 if(system("diff -w out.dat out.gold.dat")){
  fprintf(stdout, "--------------------------------------------------\n");
  fprintf(stdout, "FAIL: Output does not match with the golden output\n");
  fprintf(stdout, "--------------------------------------------------\n");
  return 1;
 } else {
  fprintf(stdout, "-----------------------------------------------\n");
  fprintf(stdout, "PASS: The output matches with the golden output\n");
  fprintf(stdout, "-----------------------------------------------\n");
  return 0;
 }
}
