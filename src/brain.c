/* =============================================================
The MIT License (MIT)

Copyright (c) 2015 Carlo Meroni

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
================================================================= */

////////////////////////////////////////////////////////////
///	INCLUDES
////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "brain.h"



////////////////////////////////////////////////////////////
///	CONSTANTS
////////////////////////////////////////////////////////////
#define RANDF() (double)rand() / RAND_MAX
#define NEURON_THRESHOLD 30



////////////////////////////////////////////////////////////
///	NEURON
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
neuron* neuron_init(brain* b, long id)
{
	neuron* n = (neuron*)malloc(sizeof(neuron));
	n->b = b;
	n->id = id;
	n->links = (long*)malloc(sizeof(long) * 2);
	n->weights = (int*)malloc(sizeof(int) * 2);
	n->links_capacity = 2;
	n->links_count = 0;
	n->state = 0;
	n->nextstate = 0;
	n->fired = 0;
	return n;
}

////////////////////////////////////////////////////////////
void neuron_free(neuron* n)
{
	if (n->links) free(n->links);
	if (n->weights) free(n->weights);
	free(n);
}

////////////////////////////////////////////////////////////
void neuron_link(neuron* n, neuron* other, int weight)
{
	if (n->links_count >= n->links_capacity) {
		n->links_capacity*=2;
		n->links = (long*)realloc(n->links, sizeof(long) * n->links_capacity);
		n->weights = (int*)realloc(n->weights, sizeof(int) * n->links_capacity);
	}

	n->links[n->links_count] = other->id;
	n->weights[n->links_count] = weight;
	n->links_count++;
}

////////////////////////////////////////////////////////////
void neuron_unlink(neuron* n, long other_id)
{
	int found = 0;
	for (int i = 0; i < n->links_count-1; i++) {
		if (n->links[i] == other_id) found = 1;
		if (found) {
			n->links[i] = n->links[i+1];
			n->weights[i] = n->weights[i+1];
		}
	}
	if (found) n->links_count--;
}

////////////////////////////////////////////////////////////
void neuron_update(neuron* n)
{
	//Fire
	if (n->state >= NEURON_THRESHOLD)
	{
		//Send weights to other neurons
		for (int i = 0; i < n->links_count; i++)
			n->b->neurons[n->links[i]]->nextstate += n->weights[i];
		n->nextstate = 0;	
		n->state = 0;
		n->fired = 1;
	}
	else
	{
		n->fired = 0;
	}

	//Update state
	n->state += n->nextstate;
	n->nextstate = 0;
}

////////////////////////////////////////////////////////////
void neuron_fire(neuron* n)
{
	n->state = NEURON_THRESHOLD;
}

////////////////////////////////////////////////////////////
int neuron_fired(neuron* n)
{
	return n->fired;
}


////////////////////////////////////////////////////////////
///	BRAIN
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
brain* brain_init()
{
	brain* b = (brain*)malloc(sizeof(brain));
	b->neurons = NULL;
	b->neurons_count = 0;
	return b;
}

////////////////////////////////////////////////////////////
void brain_free(brain* b)
{
	if (b->neurons) {
		for (int i = 0; i < b->neurons_count; i++)
			neuron_free(b->neurons[i]);
		free(b->neurons);
		b->neurons = NULL;
	}
	free(b);
	b = NULL;
}

////////////////////////////////////////////////////////////
void brain_makeneurons(brain* b, int neurons_count)
{
	//Free old neurons
	if (b->neurons) {
		for (int i = 0; i < b->neurons_count; i++)
			neuron_free(b->neurons[i]);
		free(b->neurons);
		b->neurons = NULL;
	}
	
	//Make new neurons
	b->neurons = (neuron**)malloc(sizeof(neuron*) * neurons_count);
	b->neurons_count = neurons_count;
	for (int i = 0; i < b->neurons_count; i++)
		b->neurons[i] = neuron_init(b, i);
}

////////////////////////////////////////////////////////////
void brain_update(brain* b)
{
	//Update all neurons
	for (int i = 0; i < b->neurons_count; i++)
		neuron_update(b->neurons[i]);
}
