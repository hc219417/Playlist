/**
 *   @file: Playlist.cc
 * @author: Hannah Culver
 *   @date: February 7, 2022
 *  @brief: implementation file for the Playlist class
 */

#include "Playlist.h"
using namespace std;

Playlist::Playlist(){
    data = new Song[5];
    used = 0;
    capacity = 5;
    current_index = 0;
}

Playlist::~Playlist(){
    delete []data;
}

Playlist::Playlist(const Playlist& other){
    used = other.used;
    capacity = other.capacity;
    data = new Song[capacity];
    for(int i = 0; i < used; i++){
        data[i] = other.data[i];
    }
}

void Playlist::operator = (const Playlist& other){
    if(this == &other){
        return;
    }
    delete []data;
    used = other.used;
    capacity = other.capacity;
    data = new Song[capacity];
    for(int i = 0; i < used; i++){
        data[i] = other.data[i];
    }
}

void Playlist::start(){
    current_index = 0;
}

void Playlist::advance(){
    if(used == capacity){
        resize();
    }
    current_index++;
}

bool Playlist::is_item()const{
    return current_index < used;
}

Song Playlist::current()const{
    return data[current_index];
}

void Playlist::remove_current(){
    for(int i = current_index; i < used - 1; i++){
        data[i] = data[i + 1];
    }
    used--;
}

void Playlist::insert(const Song& s){
    if(used == capacity) resize();
    used++;
    if(!is_item()){
        for(int i = used - 1; i > 0; i--){
            data[i] = data[i - 1];
        }
        data[current_index] = s;
    }
    else{
        for(int i = used - 1; i > current_index; i--){
            data[i] = data[i - 1];
        }
        data[current_index] = s;
    }
}

void Playlist::attach(const Song& s){
    if(used == capacity) resize();
    used++;
    if(!is_item()){
        data[used] = s;
    }
    else{
        for(int i = used - 1; i > current_index + 1; i--){
            data[i] = data[i - 1];
        }
        data[current_index + 1] = s;
    }
}
        
void Playlist::show_all(std::ostream& outs)const{
    for(int i = 0; i < used; i++){
		outs << "*************************" << endl;
        outs << "Song: " << data[i].get_name() << endl;
        outs << "Artist: " << data[i].get_artist() << endl;
        outs << "Release Date: " << data[i].get_release() << endl;
        outs << "*************************" << endl;
	}
}

void Playlist::releaseDate_sort(){
    int i, j, smallsp;
	Song tmp;
	for(i = 0; i < used - 1; i++)
	{
		smallsp = i;
		for(j = i + 1; j < used; j++)
		{
			if(data[j].get_release() < data[smallsp].get_release()) //comparing release dates using selection sort
			{
				smallsp = j;
			}
		}
		tmp = data[i];
		data[i] = data[smallsp];
		data[smallsp] = tmp;
	}
}

void Playlist::artist_sort(){
    int i, j, smallsp;
	Song tmp;
	for(i = 0; i < used - 1; i++)
	{
		smallsp = i;
		for(j = i + 1; j < used; j++)
		{
			if(data[j].get_artist() < data[smallsp].get_artist()) //comparing artists using selection sort
			{
				smallsp = j;
			}
		}
		tmp = data[i];
		data[i] = data[smallsp];
		data[smallsp] = tmp;
	}
}

Song Playlist::find_song(const std::string& name)const{
    for(int i = 0; i < used; i++){
        if(data[i].get_name() == name){
            return data[i];
        }
    }
    cout << "Error: song not found" << endl;
    return Song();
}

bool Playlist::is_song(const Song& s) const{
    bool found = false;
    for(int i = 0; i < used; i++){
        if(data[i] == s){
            found = true;
        }
    }
    return found;
}

void Playlist::load(std::istream& ins){
    while(!ins.eof()){
        if(used == capacity) resize();
        ins >> data[used];
        while(ins.peek() == '\n' || ins.peek() == '\r')
 		{
 			ins.ignore(); //clear out last leftover newline
 		}
 		used++;
    }
}

void Playlist::save(std::ostream& outs)const{
    for(int i = 0; i < used; i++){
        outs << data[i].get_name() << endl;
        outs << data[i].get_artist() << endl;
        outs << data[i].get_release() << endl;
    }
}

void Playlist::resize(){
    Song* tmp;
    tmp = new Song[capacity + 5];
    for(int i = 0; i < used; i++){
        tmp[i] = data[i];
    }
    delete []data;
    data = tmp;
    capacity += 5;
}