#include<iostream>

using namespace std;

class Node {
	int score;
	Node* next;
	Node* previous;
public:
	void setScore(int score) {
		this->score = score;
	}
	void setNext(Node* next) {
		this->next = next;
	}
	void setPrevious(Node* previous) {
		this->previous = previous;
	}
	Node* getNext() {
		return (this->next);
	}
	Node* getPrevious() {
		return (this->previous);
	}
	int getScore() {
		return (this->score);
	}
};

class ScoresList {
	Node* headPtr, * tailPtr;
	Node* previousNode, * nextNode;
public:
	ScoresList() {
		headPtr = tailPtr = NULL;
	}
	~ScoresList() {
		Node* n = headPtr;
		while (n != NULL) {
			delete n;
			n = n->getNext();
		}
	}
	void insertAtHead(int score) {
		if (headPtr == NULL) {
			Node* newNode = new Node;
			newNode->setScore(score);
			newNode->setNext(NULL);
			newNode->setPrevious(NULL);
			headPtr = newNode;
			tailPtr = newNode;
		}
		else {
			Node* newNode = new Node;
			newNode->setScore(score);
			newNode->setNext(headPtr);
			headPtr->setPrevious(newNode);
			newNode->setPrevious(NULL);
			headPtr = newNode;
		}
	}
	void insertAtTail(int score) {
		if (headPtr == NULL) {
			Node* newNode = new Node;
			newNode->setScore(score);
			newNode->setNext(NULL);
			newNode->setPrevious(NULL);
			headPtr = newNode;
			tailPtr = newNode;
		}
		else {
			Node* newNode = new Node();
			newNode->setScore(score);
			newNode->setPrevious(tailPtr);
			newNode->setNext(NULL);
			tailPtr->setNext(newNode);
			tailPtr = newNode;
		}
	}
	//void deleteAllOccurences(int score) {
	//	Node* n = headPtr;
	//	int deleteCounter = 0;
	//	while (n != NULL) {
	//		if (n->getScore() == score) {

	//			if (n->getPrevious() == NULL) {
	//				headPtr = n->getNext();
	//			}				//delete n->getPrevious();
	//	 	}
	//	}
	//	if (deleteCounter == 0) {
	//		cout << score << " not found in the list." << endl;
	//	}
	//}


	//void deleteAllOccurences(int score) {
	//	Node* n = headPtr;
	//	
	//}


	void deleteAllOccurrences(int score) {
		if (headPtr == NULL) {
			cout << "The list is empty. No nodes to delete." << endl;
			return;
		}

		Node* n = headPtr;
		bool found = false;

		while (n != NULL) {
			if (n->getScore() == score) {
				found = true;
				Node* deletion = n; 
				n = n->getNext();     

				if (deletion->getPrevious() != NULL) {
					deletion->getPrevious()->setNext(deletion->getNext());
				}
				else {
					headPtr = deletion->getNext();
				}

				if (deletion->getNext() != NULL) {
					deletion->getNext()->setPrevious(deletion->getPrevious());
				}
				else {
					tailPtr = deletion->getPrevious();
				}

				if (headPtr == NULL) {
					tailPtr = NULL;
				}

				delete deletion;
			}
			else {
				n = n->getNext(); 
			}
		}

		if (!found) {
			cout << score << "Score not found in any match." << endl;
		}
	}



	void displayHighestAndLowest() {
		cout << "displayHighestAndLowest()\n\n";

		if (headPtr == NULL) {
			cout << "No matches recorded yet. \n";
			return;
		}

		int minScore = 1000000000;
		int maxScore = 0;
		Node* n = headPtr;
		while (n != NULL) {
			if (n->getScore() < minScore) {
				minScore = n->getScore();
			}
			if (n->getScore() > maxScore) {
				maxScore = n->getScore();
			}
			n = n->getNext();
		}
		cout << "Highest score is: " << maxScore << endl;
		cout << "Lowest score is: " << minScore << endl;
	}
	void displayScores() {
		cout << "displayScores()\n\n";
		Node* n = headPtr;
		do {
			cout << "Element: " << n->getScore() << endl;
			n = n->getNext();
		} while (n != NULL);
	}
	void displayReverse() {
		cout << "displayReverse()\n\n";
		Node* n = tailPtr;
		do {
			cout << "Element: " << n->getScore() << endl;
			n = n->getPrevious();
		} while (n != NULL);
	}
};

int main() {
	ScoresList* List = new ScoresList();
	List->insertAtHead(232);
	List->insertAtHead(134);
	List->insertAtHead(287);
	List->insertAtTail(355);
	List->insertAtHead(185);
	List->insertAtTail(232);
	List->insertAtHead(210);
	List->insertAtTail(345);
	List->insertAtHead(134);
	List->displayScores();
	cout << endl;
	List->displayReverse();
	cout << endl;
	List->displayHighestAndLowest();
	List->deleteAllOccurrences(232); 
	cout << endl; 
	List->displayScores(); 
	cout << endl; 
	List->displayReverse(); 
	cout << endl; 
	List->displayHighestAndLowest();
	cout << endl;
	List->deleteAllOccurrences(134);
	cout << endl;
	List->displayScores();
	cout << endl;
	List->displayReverse();
	cout << endl;
	List->displayHighestAndLowest();
	cout << endl;
	List->deleteAllOccurrences(355);
	cout << endl;
	List->displayScores();
	cout << endl;
	List->displayReverse();
	cout << endl;
	List->displayHighestAndLowest();
	return 0;
}

