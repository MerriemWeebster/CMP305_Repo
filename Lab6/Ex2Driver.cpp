#include <iostream>
#include <queue>
using namespace std;
 class Family
{
public:	
	Family(int ide=0, int eld=0, int kid=0) {
		noOfElders = eld;
		noOfKids = kid;
		id = ide;
	}
	
	Family(const Family &a) {
		noOfKids = a.noOfKids;
		noOfElders = a.noOfElders;
		id = a.id;
	}
	
	Family operator=(Family const &a) {
		this->id = a.id;
		this->noOfElders = a.noOfElders;
		this->noOfKids = a.noOfKids;
		return *this;

	}
	int getnoOfkids() const  {
		return noOfKids;
	}
	int getnoOfElders() const {
		return noOfElders;
	}
	int getid() const {
		return id;
	}
	void setnoOfKids(int x) {
		noOfKids = x;
	}
	void setnoOfElders(int x) {
		noOfElders = x;
	}
	void setid(int x) {
		id = x;
	}
		
	friend ostream & operator<<(ostream & out, const Family & a)
	{
		out << "The id of the travelers are: " << a.id << endl;
		out << "The number of elders are: " << a.noOfElders << endl;
		out << "The number of kids are: " << a.noOfKids << endl;
		return out;
	}

	friend istream &operator >> (istream &in, Family &a) {
		in >> a.id;
		in >> a.noOfElders;
		in >> a.noOfKids;

		return in;
	}

private:
	int id, noOfElders, noOfKids;
};

queue<Family> KidsQueue(queue<Family> &a, queue<Family> &b) 
{
	queue<Family> tmpA = a, tmpB = b, newA, newB, c;
	while (!tmpA.empty() && !tmpB.empty()) 
	{
		if(!tmpA.empty())
		{
			Family fObj = tmpA.front();

			if(fObj.getnoOfkids() >= 3)
				c.push(fObj);
			else
				newA.push(fObj);

			tmpA.pop();
		}

		if(!tmpB.empty())
		{
			Family fObj = tmpB.front();

			if(fObj.getnoOfkids() >= 3)
				c.push(fObj);
			else
				newB.push(fObj);

			tmpB.pop();
		}
	}
            
    a = newA;
	b = newB;

	return c;
}

queue <Family> ReOrganize(queue<Family>& a, queue<Family>& b)
{
    
}
//print Queue
ostream &operator<<(ostream &out, const queue<Family> &q) {
	queue<Family> tmp = q;
	while (!tmp.empty()) {
		cout << tmp.front() << endl;
		tmp.pop();
	}

	return out;
}


int main() {
	queue <Family> counter1;
	queue <Family> counter2;
	queue <Family> counter3;
	
	counter1.push(Family(100, 2, 3));
	counter1.push(Family(200, 2));
	counter1.push(Family(400, 1));
	counter1.push(Family(402, 1,4));
	//counter1.push(Family(789, 2));
	
	counter2.push(Family(300, 2, 1));
	counter2.push(Family(500, 1, 3));
	counter2.push(Family(405, 3, 2));
	counter2.push(Family(309, 1, 3));
	counter2.push(Family(567, 2));
	

    /*counter3 = KidsQueue(counter1, counter2);
    
    cout << "Counter 3 has: " << endl << counter3;
    cout << "Counter 1 after modification has: \n" << counter1;
    cout << "Counter 2 after modification has: " << endl << counter2;

*/
	counter3 = ReOrganize(counter1, counter2);

	cout << "Counter 1 has: " << endl << counter1;
	cout << "Counter 2 after modification has: \n" << counter2;
	cout << "Counter 3 after modification has: " << endl << counter3;
	
	
	return 0;
}






