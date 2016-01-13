// This file is part of Sparta
// Licensed under GNU General Public License (GPL)
// Check out: https://www.gnu.org/licenses/gpl.html

#include "utils.h"
#include <stdlib.h>

int random(int to) {
	return rand() % to;
}

int random(int from, int to) {
	return from + random(to - from);
}

int sum(int values[], int amount) {
	int result;
	for (int i = 0; i < amount; i++) {
		result += values[i];
	}
	return result;
}