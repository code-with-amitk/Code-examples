/* hashtableExample.c

Hash table stores Student data (Key:Value)
(1,20)  (2,70)  (42,80)  (4,25)  (12,44)  (13,78)  (14,32) (17,11)  (37,97)

Then We can generalize this Algo for bigger data
*/

#include<stdio.h>
#include<stdlib.h>	//malloc
#define SIZE 20

typedef struct dataitem{
	int key;
	int data;
}DATA;

DATA *hashTable[SIZE];	//This is pointer of structs pointing to structures

int hashFunction (int key) {
	return key%SIZE;
}

void insert (int data, int key) {
	int hashIndex;
	DATA *item = (DATA *) malloc (sizeof(DATA));
	item->key = key;
	item->data = data;

	hashIndex = hashFunction (key);

	//Find Location of this Struct in HashtTable, Where it needs to be placed
	while (hashTable[hashIndex] != NULL){
		//Hash Collision. Find new place
		++hashIndex;
	}
	hashTable[hashIndex] = item;
}

int search (int key){
	//We need to find Index of HashTable Only
	int hashIndex = hashFunction(key);
	while (hashTable[hashIndex] != NULL) {
		if (hashTable[hashIndex]->key == key) {
			return hashTable[hashIndex]->data;
		}
		++hashIndex;
		hashIndex %= SIZE;
	}
}

void main() {
	insert (1,20);	//(data,key)
	insert(2, 70);
	insert(42, 80);
	insert(4, 25);
	insert(12, 44);
	insert(14, 32);
	insert(17, 11);
	insert(13, 78);
	insert(37, 97);

	printf ("\nWe searched Data on Key=32 and found(%d)\n",search(32));
}
/*Output
 * 14
 */
