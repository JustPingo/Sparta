#pragma once
// This file is part of Sparta
// Licensed under GNU General Public License (GPL)
// Check out: https://www.gnu.org/licenses/gpl.html

#include "config.h"

typedef struct {
	NeuronColumn* from,
	NeuronColumn* to,
	int weight[ROWS],
	int currentValue
} Neuron;

typedef struct {
	Neuron elements[ROWS]
} NeuronColumn;

typedef struct {
	NeuronColumn columns[COLUMNS],
	int currentColumn;
} Brain;

void generateBrain(Brain* brain);
void clearBrain(Brain* brain);
void mutateBrain(Brain* brain, int mutationAmount);
void breedBrains(Brain* mother, Brain* father, Brain* child);
void freeBrain(Brain* brain);
void processNeuronColumn(NeuronColumn* col);
void processInputNeuronColumn(NeuronColumn* col, int interface[ROWS]);
void processOutputNeuronColumn(NeuronColumn* col, int interface[ROWS]);
void processBrain(Brain* brain, InputValues* in, OutputValues* out);