#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int HASHSIZE = 4001;


class HashTable{

public:
	int size;

	int* updatePtr;
	int* costPtr;

	struct Node {
		string word;
		int freq = 0;

	};
	
	Node hashArr[HASHSIZE]{};


	HashTable();
	~HashTable() {
		delete updatePtr;
		delete costPtr;
	}
	void update(string argWord);
	void printVal();


};

int hashIndex(string argWord);





int main() {

	HashTable myTable;

	string myWord;
	ifstream myFile;
	myFile.open("RomeoAndJuliet.txt");
	while (myFile >> myWord) {
		//cout << myWord << endl;
		myTable.update(myWord);
		
	}
	
	myTable.printVal();


	return 0;
}






int hashIndex(string argWord) {
	int asciiTot = 0;
	for (int i = 0; i < argWord.length(); i++) {
		asciiTot = asciiTot + (int)argWord[i];
	}

	int index = asciiTot % HASHSIZE;
	return index;
}

HashTable::HashTable() {
	updatePtr = new int[HASHSIZE] {0};
	costPtr = new int[HASHSIZE] {0};

	size = 0;
}


void HashTable::update(string argWord) {

	int key = hashIndex(argWord);
	int num = 0;
	int probes = 0;
	
	if (hashArr[key].freq == 0) { // Simply: If the freq is 0 then nothing there, so input
		hashArr[key].word = argWord;
		hashArr[key].freq++;
		size++; // might change
		probes++; // How many times we accessed the array
		num++; // Keeps track of number of times update has been done for .word

			
	}
	else if (hashArr[key].freq != 0 && hashArr[key].word == argWord) { // If the frequency is not 0, but is the same word, just inc freq

		hashArr[key].freq++; // Updates the frequency of give word
		probes++; // How many times we accessed the array

	}
	else { // linear probeing condition
		while (hashArr[key].freq != 0 && hashArr[key].word != argWord) { // While, the array[index] is filled and not the same word, keep increasing index
			key++;
			probes++;

			 // goes to next index
			 // How many times we accessed the array

		}
		if (hashArr[key].word == argWord) { // Once we have gotten out the while loop, if it is the same word, just inc freq
			hashArr[key].freq++;
			probes++;
		}
		else {                             // Otherwise, inc freq and input word
			hashArr[key].freq++;
			hashArr[key].word = argWord;
			size++; // Increases when there is another word added to hash table
			probes++; // How many times we accessed the array
			num++; // Keeps track of number of times update has been done for .word

			
		}
	}

	updatePtr[key] = num;
	costPtr[key] = probes;
	//cout << "Word: " << hashArr[key].word << " | UpdatePtr: " << updatePtr[key] << " | costPtr:" << costPtr[key] << endl;

}

void HashTable::printVal() {

	cout << "Unique Words: " << size << endl;;
	cout << "Average Probes: ";
	for (int i = 1; i <= HASHSIZE; i++) {

		if (updatePtr[i] != 0) {
			double ratio = costPtr[i] / updatePtr[i];
			cout  << fixed << setprecision(2) << ratio << ", ";
		}

	}
	cout << "\b\b" << endl;
}

/***************** Notes *******************/

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
