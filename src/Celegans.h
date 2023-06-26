/* =============================================================
The MIT License (MIT)

Copyright (c) 2015 Carlo Meroni

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights
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
///	HEADER
////////////////////////////////////////////////////////////
#ifndef C_ELEGANS_H
#define C_ELEGANS_H

#define BRAIN_SIZE 397
#define NEURON_START 0
#define NEURON_END 300
#define MUSCLE_LEFT_START 300
#define MUSCLE_LEFT_END 347
#define MUSCLE_RIGHT_START 347
#define MUSCLE_RIGHT_END 395

//Brain forward declaration
typedef struct brain brain;

////////////////////////////////////////////////////////////
/// \brief	Create a C. elegans brain	
///
////////////////////////////////////////////////////////////
extern brain* Celegans_brain_init();

////////////////////////////////////////////////////////////
/// \brief	Destroy a C. elegans brain	
///
////////////////////////////////////////////////////////////
extern void Celegans_brain_free(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Update the brain states	
///
////////////////////////////////////////////////////////////
extern void Celegans_brain_update(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Tell a neuron to fire by passing the neuron id	
///
////////////////////////////////////////////////////////////
extern void Celegans_brain_fire(brain* b, int neuron_id);

////////////////////////////////////////////////////////////
/// \brief	Check if a neuron have just fired	
///
////////////////////////////////////////////////////////////
extern int Celegans_brain_fired(brain* b, int neuron_id);

////////////////////////////////////////////////////////////
/// \brief	Get the neuron id from the neuron name
///
////////////////////////////////////////////////////////////
extern int Celegans_neuron_get_id(char* name);

////////////////////////////////////////////////////////////
/// \brief	Give food 	
///
////////////////////////////////////////////////////////////
extern void Celegans_brain_givefood(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Touch the worm nose	
///
////////////////////////////////////////////////////////////
extern void Celegans_brain_touchnose(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Anterior touch
///
////////////////////////////////////////////////////////////
extern void Celegans_brain_touchanterior(brain* b);

////////////////////////////////////////////////////////////
/// \brief	Posterior touch
///
////////////////////////////////////////////////////////////
extern void Celegans_brain_touchposterior(brain* b);

#endif //C_ELEGANS_H
