// This file is part of Sparta
// Licensed under GNU General Public License (GPL)
// Check out: https://www.gnu.org/licenses/gpl.html

#include <stdlib.h>
#include "brain.h"
#include "utils.h"

void generateBrain(Brain* brain) { // Gives birth to a new brain in the slot "brain"
	for (int i = 0; i < COLUMNS; i++) {
		for (int k = 0; k < ROWS; k++) {
			for (int j = 0; j < ROWS; j++) 
				brain.columns[i].elements[k].weight[j] = random(MAXWEIGHT + 1);

			if (i != 0) brain.columns[i].elements[k].from = &(brain.columns[i-1]);
			if (i != (ROWS - 1)) brain.columns[i].elements[k].from = &(brain.columns[i+1]);

			brain.columns[i].elements[k].currentValue = 0;
		}
	}

	brain.currentColumn = 0;
}

void clearBrain(Brain* brain) { // Resets the brain "brain" to original state
	for (int i = 0; i < COLUMNS; i++) {
		for (int k = 0; k < ROWS; k++) {
			brain.columns[i].elements[k].currentValue = 0;
		}
	}
}

void mutateBrain(Brain* brain, int mutationAmount) { // Performs "mutationAmount" mutations on Brain object "brain"
	int c, r;
	for (int i = 0; i < mutationAmount; i++) {
		c = random(COLUMNS);
		r = random(ROWS);
		for (int k = 0; k < ROWS; k++) {
			brain.columns[c].elements[r].weight[k] = random(MAXWEIGHT + 1); // Could do the mutation on only one weight, needs testing
		}
	}
}

void breedBrains(Brain* mother, Brain* father, Brain* child) { // Breeds two brains "mother" and "father" in a new brain "child"
	for (int i = 0; i < COLUMNS; i++) {
		for (int k = 0; k < ROWS; k++) {
			for (int j = 0; j < ROWS; j++) 
				child.columns[i].elements[k].weight[j] = (((bool) random(2)) ? father.columns[i].elements[k].weight[j] : mother.columns[i].elements[k].weight[j]);

			if (i != 0) child.columns[i].elements[k].from = &(child.columns[i-1]);
			if (i != (ROWS - 1)) child.columns[i].elements[k].from = &(child.columns[i+1]);

			child.columns[i].elements[k].currentValue = 0;
		}
	}

	child.currentColumn = 0;
}

void freeBain(Brain* brain) { // Destroys and free the brain "brain" from memory, this is more of an in-case function if free(brain) happens to not be enough
	free(brain);
}

void processNeuronColumn(NeuronColumn* col) { // Processes a middle NeuronColumn "col"
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < ROWS; k++) {
			col.elements[i].currentValue += col.elements[i].from.elements[k].currentValue * col.elements[i].weight[k];
		}
		col.elements[i].currentValue /= ROWS;
	}
}

void processInputNeuronColumn(NeuronColumn* col, int interface[ROWS]) { // Processes an input NeuronColumn "col" with values from "interface"
	for (int i = 0; i < ROWS; i++) {
		col.elements[i].currentValue += interface[i] * col.elements[i].weight[i];
		col.elements[i].currentValue /= ROWS;
	}
}

void processOutputNeuronColumn(NeuronColumn* col, int interface[ROWS]) { // Processes an output NeuronColumn "col" and outputs to "interface"
	for (int i = 0; i < ROWS; i++) {
		for (int k = 0; k < ROWS; k++) {
			col.elements[i].currentValue += col.elements[i].from.elements[k].currentValue * col.elements[i].weight[k];
		}
		col.elements[i].currentValue /= ROWS;
		interface[i] = col.elements[i].currentValue;
	}
}

void processBrain(Brain* brain, int interface[ROWS]) { // Performs a brain cycle on brain "brain" with "interface" as input values and outputs in it
	for (int i = 0; i < COLUMNS; i++) {
		if (i == 0) processInputNeuronColumn(&(brain.columns[i]), interface);
		else if (i == COLUMNS-1) processOutputNeuronColumn(&(brain.columns[i]), interface);
		else processNeuronColumn(&(brain.columns[i]));
	}
}