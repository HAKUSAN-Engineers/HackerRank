#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int		dd, mm, yy;
	int		dd_act, mm_act, yy_act;

	scanf("%d %d %d", &dd_act, &mm_act, &yy_act);
	scanf("%d %d %d", &dd, &mm, &yy);
	if (yy > yy_act || (yy == yy_act && mm > mm_act) || (yy == yy_act && mm == mm_act && dd > dd_act)) {
		puts("0");
	} else if (yy < yy_act) {
		puts("10000");
	} else if (mm < mm_act) {
		printf("%d", 500 * (abs(mm - mm_act)));
	} else {
		printf("%d", 15 * (abs(dd - dd_act)));
	}
	return 0;
}
