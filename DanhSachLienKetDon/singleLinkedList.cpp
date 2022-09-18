#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *pNext;
};
struct List {
	Node *pHead;
	Node *pTail;
};

void khoiTao(List &l);
bool isEmpty(List l);
Node* getNode(int x);
void addHead(List &l, Node *p);
void addTail(List &l, Node *p);
void addAfter(List &l, Node *q, Node *p);
Node* searchPrevious(List l, Node *q);
void addPrevious(List &l, Node*q, Node *p);
void deleteHead(List &l);
void deleteAfter(List &l, Node *q);
void deleteTail(List &l);
void deleteList(List &l);
void printList(List l);

int main() {
	List l;
	khoiTao(l);
	int n, x;
	cin >> n;
	addHead(l, getNode(2));
	addHead(l, getNode(5));
	addTail(l, getNode(3));
	addTail(l, getNode(6));
	printList(l);
	return 0;
}

void khoiTao(List &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

bool isEmpty(List l) {
	if (l.pHead == NULL) {
		return true;
	}
	return false;
}

Node* getNode(int x) {
	Node *p = new Node;
	p->pNext = NULL;
	p->data = x;
	return p;
}

void addHead(List &l, Node *p) {
	if (isEmpty(l)) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(List &l, Node *p) {
	if (isEmpty(l)) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void addAfter(List &l, Node *q, Node *p) {
	if (isEmpty(l)) {
		addHead(l, p);
	}
	else {
		p->pNext = q->pNext;
		q->pNext = p;
		if (q == l.pTail) {
			l.pTail = p;
		}
	}
}

Node* searchPrevious(List l, Node *q) {
	Node* p = l.pHead;
	if (p == q) {
		return NULL;
	}
	while ((p != NULL) && (p->pNext != q)) {
		p = p->pNext;
	}
	return p;
}

void addPrevious(List &l, Node*q, Node *p) {
	if (isEmpty(l)) {
		addHead(l, p);
	}
	else {
		Node *pTemp = searchPrevious(l, q);
		addAfter(l, pTemp, p);
	}
}

void deleteHead(List &l) {
	if (!isEmpty(l)) {
		Node *p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL) {
			l.pTail = NULL;
		}
	}
}

void deleteAfter(List &l, Node *q) {
	if (q == NULL) {
		deleteHead(l);
	}
	else {
		Node *p;
		p = q->pNext;
		if (p != NULL) {
			if (p == l.pTail) {
				l.pTail = q;
			}
			q->pNext = p->pNext;
			delete p;
		}
	}
}

void deleteTail(List &l) {
	Node *p = l.pTail;
	l.pTail = searchPrevious(l, l.pTail);
	delete p;
}

void deleteList(List &l) {
	while (!isEmpty(l)) {
		deleteHead(l);
	}
}

void printList(List l) {
	for (Node *p = l.pHead; p != NULL; p = p->pNext) {
		cout << p->data << "->";
	}
	cout << endl;
}