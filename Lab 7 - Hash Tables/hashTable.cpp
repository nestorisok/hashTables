#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// update(word) // key
// key = (word) // word = 10, so whatever the ascii value is %
				// H(x) = (sum of ascii value of each charraacter) % HASHSIZE
// a struct is need

// index = 1 (word 1 / freq 1) -> (word 2 / freq 2)
	// intilizing vv
	// word = 0
	// freq = 0
	// intitializing ^^
	// example: index = 100 (word = two / freq = 1) // so far two has appeared 1 time

	// key
	// if (freq.key = 0){
	// insert word[key]
	// size++;
	// else if(freq != 0){
	// freq++;
	// }

	// if (key > HASHSIZE){
	// key = 0;
	// }


	// size++ // unique valuse/words // initally size = 0;

	// size = 0; when there is a unique element, size++
	// prob = 0;
	// num = 0;
	//freq[key] = 0
	// insert word[key]
	// size++;
	// prob++; is the number of times we touched the array


	// update
	// freq[key] != 0
	// freq++
	// prob++;

	//freq != 0
	// word != key word
	// while(freq.key != 
	// word.key != word
	// key = key++;
	// probe++;

	//ex
	// the -> index = 0
	// and -> index = 0
	// so we use a while loop until we find antoher spot
	// we then go to something like index = 4
	// if we get another and it goes to 4 and freq get freq++

	// if (word = word[key])
	// freq++;
	// probe++;
	// if (freq[key = 0]){
	// insert word
	// size++
	// probe++;
	// freq++;
	// 
	// 
	// update[size] = num;
	// 
	// 
	// size = 5;
	// num = 7;
	// update[5] = 7
	// probe = 15
	// cost[5] = 15
	// cost array with size of HASHSIZE = 4001
	// 
	// 
	// cost[0]/update[0]
	// cost[1]/update[1]
	// ... do this for all values
	//

const int HASHSIZE = 4001;


class HashTable{

public:
	int size;
	

	struct Node {
		string word;
		int freq;

	};
	
	Node hashArr[HASHSIZE]{};

	// int probe;	


	void update(string argWord);
	//int size();

};

int hashIndex(string argWord);





int main() {
	int hashArr[HASHSIZE]{};

	
	int key = hashIndex("apple");
	



//	string word(string text);


	return 0;
}

int hashIndex(string argWord) {
	int asciiTot = 0;
	for (int i = 0; i < argWord.size(); i++) {
		asciiTot += argWord[i];
	}
	return asciiTot % HASHSIZE;
}


void HashTable::update(string argWord) {

	int key = hashIndex(argWord);
	
	if (hashArr[key].freq = 0) {
		hashArr[key].word = argWord;
		hashArr[key].freq += 1;
		// left off at 33:30

	}


}
//
//int HashTable::size() {
//	int tot;
//	for (int i = 0; i < HASHSIZE; i++) {
//		if (xx[i] > 0) {
//			tot++;
//		}
//
//	}
//}