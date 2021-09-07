#include <stdio.h>

float convert(float fahr);

/* print Fahrenheit-Celsius table
	  for fahr = 0, 20, ..., 300 */
int main() {
	  int fahr;
	  float celsius;
	  int lower, upper, step;
	
	  lower = 0;	/* lower limit of temperature table */
	  upper = 300;	/* upper limit */
	  step = 20;	/* step size */

	  fahr = lower;
	  while (fahr <= upper) {
		  celsius = convert((float)fahr);
		  printf("%d\t%f\n", fahr, celsius);
		  fahr = fahr + step;
	  }
	  return(0);
}

float convert(float fahr) {
	return 5 * (fahr-32) / 9;
}
