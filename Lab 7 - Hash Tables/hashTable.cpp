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
	int size = 0;
	int probe = 0;
	int num = 0;

	int updateArr[HASHSIZE]{0};
	int costArr[HASHSIZE]{0};

	struct Node {
		string word;
		int freq = 0;

	};
	
	Node hashArr[HASHSIZE]{};

	// int probe;	


	void update(string argWord);
	void printVal();
	//int incProbe();
	//int incSize();
	//int size();

};

int hashIndex(string argWord);





int main() {


	HashTable myTable;

	string myWord;
	ifstream myFile;
	myFile.open("RomeoAndJuliet.txt");
	while (myFile >> myWord) {
		cout << myWord << endl;
		myTable.update(myWord);
		
	}

	//for (int i = 0; i < 36,678; i++) {
	//	myFile >> myWord;
	//	//cout << myWord << endl;
	//	cout << myWord << endl;
	//	myTable.update(myWord);
	//	
	//}
	
	myTable.printVal();


//	string word(string text);


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


void HashTable::update(string argWord) {

	int key = hashIndex(argWord);

	//int updateArr[HASHSIZE]{};
	//int costArr[HASHSIZE]{};
	
	if (hashArr[key].freq == 0) { // Simply: If the freq is 0 then nothing there, so input
		hashArr[key].word = argWord;
		hashArr[key].freq++;
		size++; // might change
		probe++; // How many times we accessed the array
		num++; // Keeps track of number of times update has been done for .word
		// left off at 33:30

	}
	else if (hashArr[key].freq != 0 && hashArr[key].word == argWord) { // If the frequency is not 0, but is the same word, just inc freq

		hashArr[key].freq++; // Updates the frequency of give word
		probe++; // How many times we accessed the array

	}
	else { // linear probeing condition
		while (hashArr[key].freq != 0 && hashArr[key].word != argWord) { // While, the array[index] is filled and not the same word, keep increasing index
			key++;
			probe++;

			 // goes to next index
			 // How many times we accessed the array

		}
		if (hashArr[key].word == argWord) { // Once we have gotten out the while loop, if it is the same word, just inc freq
			hashArr[key].freq++;

		}
		else {                             // Otherwise, inc freq and input word
			hashArr[key].freq++;
			hashArr[key].word = argWord;
			size++; // Increases when there is another word added to hash table
			probe++; // How many times we accessed the array
			num++; // Keeps track of number of times update has been done for .word
		}
	}

	updateArr[key] = num;
	costArr[key] = probe;
	// cout << size << endl;
	// cout << "Unique Words: " << size;
	// cout << "Expected Probes: " << costArr[key] / updateArr[key] << endl;

	//ratio = costArr[key] / updateArr[key];
}

void HashTable::printVal() { // JUST NEED TO FIX THIS

	cout << "Unique Words: " << size << endl;;
	cout << "Average Probes: ";
	for (int i = 1; i <= HASHSIZE; i++) {
		cout << costArr[i] / updateArr[i] << ", ";
	}
	cout << "\b\b" << endl;
}



/*


void HashTable::update(string argWord) {

	int key = hashIndex(argWord);

	//int updateArr[HASHSIZE]{};
	//int costArr[HASHSIZE]{};

	if (hashArr[key].freq == 0) { // Simply: If the freq is 0 then nothing there, so input
		hashArr[key].word = argWord;
		hashArr[key].freq++;
		size++; // might change
		probe++; // How many times we accessed the array
		num++; // Keeps track of number of times update has been done for .word
		// left off at 33:30

	}
	else if (hashArr[key].freq != 0 && hashArr[key].word == argWord) { // If the frequency is not 0, but is the same word, just inc freq

		hashArr[key].freq++; // Updates the frequency of give word
		probe++; // How many times we accessed the array

	}
	else { // linear probeing condition
		while (hashArr[key].freq != 0 && hashArr[key].word != argWord) { // While, the array[index] is filled and not the same word, keep increasing index
			key++;
			probe++;

			 // goes to next index
			 // How many times we accessed the array

		}
		if (hashArr[key].word == argWord) { // Once we have gotten out the while loop, if it is the same word, just inc freq
			hashArr[key].freq++;

		}
		else {                             // Otherwise, inc freq and input word
			hashArr[key].freq++;
			hashArr[key].word = argWord;
			size++; // Increases when there is another word added to hash table
			probe++; // How many times we accessed the array
			num++; // Keeps track of number of times update has been done for .word
		}
	}

	updateArr[key] = num;
	costArr[key] = probe;
	cout << size << endl;
	// cout << "Unique Words: " << size;
	// cout << "Expected Probes: " << costArr[key] / updateArr[key] << endl;

	//ratio = costArr[key] / updateArr[key];
}

*/