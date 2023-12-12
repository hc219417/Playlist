/**
 *   @file: Song.cc
 * @author: Hannah Culver
 *   @date: February 7, 2022
 *  @brief: implementation file for the Song class
 */

#include <iostream>
#include "Song.h"
#include "date.h"
using namespace std;

Song::Song(){
    name = "N/A";
    artist = "N/A";
    release = Date();
}

string Song::get_name()const{
    return name;
}

string Song::get_artist()const{
    return artist;
}

Date Song::get_release()const{
    return release;
}

bool Song::operator == (const Song& other)const{
    return name == other.name && release == other.release && artist == other.artist;
}

bool Song::operator != (const Song& other)const{
    return name != other.name || release != other.release || artist != other.artist;
}

void Song::input(std::istream& ins){
    if(&ins == &cin){ //read from the keyboard
        cout << "Please enter the name of the song: ";
        while(ins.peek() == '\n' || ins.peek() == '\r')
	    {
		    ins.ignore();
	    }
	    getline(ins,name);
        cout << "Please enter the artist: ";
        while(ins.peek() == '\n' || ins.peek() == '\r')
	    {
		    ins.ignore();
	    }
	    getline(ins,artist);
        cout << "Please enter the release date: ";
        ins >> release;
    }
    else{ //read from a file
        while(ins.peek() == '\n' || ins.peek() == '\r')
	    {
		    ins.ignore();
	    }
	    getline(ins,name);
        while(ins.peek() == '\n' || ins.peek() == '\r')
	    {
		    ins.ignore();
	    }
	    getline(ins,artist);
        ins >> release;
    }
}

void Song::output(std::ostream& outs)const{
    outs << "*************************" << endl;
    outs << "Song: " << name << endl;
    outs << "Artist: " << artist << endl;
    outs << "Release Date: " << release << endl;
    outs << "*************************" << endl;
}

istream& operator >> (std::istream& ins, Song& s){
    s.input(ins);
    return ins;
}

ostream& operator << (std::ostream& outs, const Song& s){
    s.output(outs);
    return outs;
}