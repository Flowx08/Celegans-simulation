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
#include <string.h>
#include "Celegans.h"
#include "brain.h"

unsigned int hash_str(char* str)
{
  unsigned int hash = 7;
  int len = strlen(str);
  for (int i = 0; i < len; i++)
    hash = hash * 31 + str[i];
  return hash;
}

#define HASH_TABLE_SIZE 1024
typedef struct hash_table
{
  int size;
  int count;
  char** keys;
  int* values;
} hash_table;

hash_table* hash_table_init(int size)
{
  hash_table* ht = (hash_table*)malloc(sizeof(hash_table));
  ht->size = size;
  ht->count = 0;
  ht->keys = (char**)malloc(sizeof(char*) * size);
  for (int i = 0; i < ht->size; i++)
    ht->keys[i] = NULL;
  ht->values = (int*)malloc(sizeof(int) * size);
  return ht;
}

void hash_table_free(hash_table* ht)
{
  for (int i = 0; i < ht->size; i++)
    if (ht->keys[i] != NULL)
      free(ht->keys[i]);
  free(ht->keys);
  free(ht->values);
  free(ht);
}

void hash_table_insert(hash_table* ht, char* key, int value)
{
  if (!ht || !key) {
    printf("Hash table or key is NULL!\n");
    return;
  }

  int start_index = hash_str(key) % ht->size;
  int index = start_index;
  while (ht->keys[index] != NULL)
  {
    if (strcmp(ht->keys[index], key) == 0)
    {
      ht->values[index] = value;
      return;
    }

    index = (index + 1) % ht->size;

    if (index == start_index) {
      printf("Hash table is full!\n");
      return;
    }
  }
  
  char* key_copy = strdup(key);
  if (!key_copy) {
    printf("Failed to allocate memory for key!\n");
    return;
  }

  ht->keys[index] = key_copy;
  ht->values[index] = value;
  ht->count++;
  
  if (ht->count > ht->size) {
    printf("Hash table count exceeded the size!\n");
    return;
  }
}

int hash_table_get(hash_table* ht, char* key)
{
  int start_index = hash_str(key) % ht->size;
  int index = start_index;
  while (ht->keys[index] != NULL)
  {
    if (strcmp(ht->keys[index], key) == 0)
      return ht->values[index];
    index = (index + 1) % ht->size;

    if (index == start_index)
      return -1;
  }
  return -1;
}

typedef struct NodeId {
  char* name;
  int id;
} NodeId;
NodeId node_ids[500];
int node_ids_count = 0;

typedef struct NodeConnection {
  char* from;
  char* to;
  int weight;
} NodeConnection;
NodeConnection connections[1024 * 10];
int connections_count = 0;
hash_table* node_ids_ht = NULL;

void parse_node_ids(char* filepath) {
  // Read CSV file
  FILE* file = fopen(filepath, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filepath);
    exit(1);
  }
  char line[1024];
  node_ids_count = 0;
  fgets(line, 1024, file); // skip first line
  while (fgets(line, 1024, file)) {
    char* tmp = strdup(line);
    char* name = strsep(&tmp, ",");
    char* id = strsep(&tmp, ",");

    assert(strlen(name) >= 1);
    assert(strlen(id) >= 1);
    node_ids[node_ids_count].name = strdup(name);
    node_ids[node_ids_count].id = atoi(id);
    node_ids_count++;
    assert(node_ids_count < 500);
  }
  fclose(file);
}

void parse_connections(const char* filepath)
{
  // Read CSV file
  FILE* file = fopen(filepath, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filepath);
    exit(1);
  }
  char line[1024];
  connections_count = 0;
  fgets(line, 1024, file); // skip first line
  while (fgets(line, 1024, file)) {
    char* tmp = strdup(line);
    char* from = strsep(&tmp, ",");
    char* to = strsep(&tmp, ",");
    char* weight = strsep(&tmp, ",");
    connections[connections_count].from = strdup(from);
    connections[connections_count].to = strdup(to);
    connections[connections_count].weight = atoi(weight);
    connections_count++;
    assert(connections_count < 1024 * 10);
  }
}


////////////////////////////////////////////////////////////
brain* Celegans_brain_init()
{
  // Load connectome data
  printf("Loading connectome data\n");
  parse_node_ids("./connectome/NodesIds.csv");
  printf("Loaded %d node ids\n", node_ids_count);
  parse_connections("./connectome/CElegansConnectome.csv");
  printf("Loaded %d nodes and %d connections\n", node_ids_count, connections_count);

  // map node names to ids
  if (node_ids_ht != NULL)
    hash_table_free(node_ids_ht);
  printf("Mapping node names to ids\n");
  node_ids_ht = hash_table_init(BRAIN_SIZE * 4);
  for (int i = 0; i < node_ids_count; i++) {
    long id = (int)node_ids[i].id;
    hash_table_insert(node_ids_ht, node_ids[i].name, id);
  }
  printf("node_ids_ht->count = %d\n", node_ids_ht->count);
  printf("Mapped node names to ids\n");
  
  // Wire up neurons
  printf("Wiring up neurons\n");
	brain* b = brain_init();
	brain_makeneurons(b, BRAIN_SIZE);
  printf("Created %d neurons\n", BRAIN_SIZE);
  for (int i = 0; i < connections_count; i++) {
    int from_id = hash_table_get(node_ids_ht, connections[i].from);
    int to_id = hash_table_get(node_ids_ht, connections[i].to);
    if (from_id == -1 || to_id == -1) {
      printf("Failed to find node id for %s or %s\n", connections[i].from, connections[i].to);
    }
    assert(from_id != -1);
    assert(to_id != -1);
    neuron_link(b->neurons[from_id], b->neurons[to_id], connections[i].weight);
  }
  printf("Wired up neurons\n");

	return b;
}

////////////////////////////////////////////////////////////
void Celegans_brain_free(brain* b)
{
	brain_free(b);
  if (node_ids_ht != NULL)
    hash_table_free(node_ids_ht);
}

////////////////////////////////////////////////////////////
void Celegans_brain_update(brain* b)
{
	brain_update(b);	
}

////////////////////////////////////////////////////////////
void Celegans_brain_fire(brain* b, int neuron_id)
{
	neuron_fire(b->neurons[neuron_id]);
}

////////////////////////////////////////////////////////////
int Celegans_brain_fired(brain* b, int neuron_id)
{
	return neuron_fired(b->neurons[neuron_id]);
}

int Celegans_neuron_get_id(char* name)
{
  return (int)hash_table_get(node_ids_ht, name);
}

////////////////////////////////////////////////////////////
void Celegans_brain_givefood(brain* b)
{
  neuron_fire(b->neurons[Celegans_neuron_get_id("ADFL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ADFR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASGR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASGL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASIL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASIR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASJR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASJL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("AWCL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("AWCR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("AWAL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("AWAR")]);
}

////////////////////////////////////////////////////////////
void Celegans_brain_touchnose(brain* b)
{
  neuron_fire(b->neurons[Celegans_neuron_get_id("FLPR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("FLPL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASHL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("ASHR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("IL1VL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("IL1VR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("OLQDL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("OLQDR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("OLQVR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("OLQVL")]);
}

////////////////////////////////////////////////////////////
void Celegans_brain_touchanterior(brain* b)
{
  neuron_fire(b->neurons[Celegans_neuron_get_id("FLPL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("FLPR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("BDUL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("BDUR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("SDQR")]);
}

////////////////////////////////////////////////////////////
void Celegans_brain_touchposterior(brain* b)
{
  neuron_fire(b->neurons[Celegans_neuron_get_id("PVDL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("PVDR")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("PVCL")]);
  neuron_fire(b->neurons[Celegans_neuron_get_id("PVCR")]);
}
