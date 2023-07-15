class MyCircularDeque { 
	 vector<int> v;
	 int l;
	 int front=-1,back=-1;
public:
	MyCircularDeque(int k) {
		v.resize(k);
		l=k;
	}

	bool insertFront(int value) {
		if(isFull()) return false;
		if(isEmpty())  front=back=0;
		else 
			front=(front-1+l)%l;
		v[front]=value;
		return true;
	}

	bool insertLast(int value) {
		if(isFull()) return false;
		if(isEmpty()) front=back=0;
		else
			back=(back+1)%l;
		v[back]=value;
		return true;
	}

	bool deleteFront() {
		if(isEmpty()) return false;
		else if(front==back) front=back=-1;
		else front=(front+1)%l;
		return true;
	}

	bool deleteLast() {
		if(isEmpty()) return false;
		if(front==back) front=back=-1;
		else back=(back-1+l)%l;
		return true;
	}

	int getFront() {
		if(isEmpty()) return -1;
		return v[front];
	}

	int getRear() {
		if(isEmpty()) return -1;
		return v[back];
	}

	bool isEmpty() {
		if(front==-1 &&  back==-1)
			return true;
		return false;
	}

	bool isFull() {
		if((back+1)%l==front) return true;
		return false;
	}
};