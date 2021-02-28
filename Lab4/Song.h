#pragma once
#include<string>
#include<iostream>
using namespace std;
class Song {
public:
	Song(string t = "", string s = "") : title{ t }, singer{ s }{ }
	
	friend ostream &operator<<(ostream &out, const Song & s) {
		out << "Title: " << s.getTitle() << "\nArtist: " << s.getSinger() << endl;
		return out;
	}

	 bool operator==(const Song &rhs) {
		if ((rhs.title == title) && (rhs.singer == singer))
			return true;
		else
			return false;
	}
	string getTitle() const { return title; }
	string getSinger() const { return singer; }
	void setTitle(string t) { title = t; }
	void setSinger(string s) { singer = s; }
	Song &operator=(const Song &s) {
		title = s.title;
		singer = s.singer;
		return *this;
	}
private:
	string title;
	string singer;
};
