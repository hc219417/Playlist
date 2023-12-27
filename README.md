# Playlist

`Song.h` is a header file for a class called `Song`. This class has three private variables: the song’s *name*, *release date*, and *artist*. The release date is of type `Date`. Implementation of this class (`Song.cc`) includes overloaded insertion, extraction, ==, and != operators. Two songs are “equal” only if they have the same name, release date, and artist.

You can test this class by writing a main of your own that declares two songs, lets you put the information into both, outputs them to the screen and compares them for equality.

In the main, the application allows the user to:

- Add a new song to the beginning of the list
- View all the songs in the list
- Walk through the list, viewing one song at a time
- Remove a song from the list
- Insert a new song at some spot in the middle of the list, which includes at the back end
- Sort all the songs by their release date or artist
- Find a song using its name

There is also a file backup mechanism that uses the person’s username for the name of the file.

The header file for the container class, `Playlist.h`, makes all this possible. The private variables for the implementation of this class (`Playlist.cc`) consist of a pointer of type `Song` as well as variables for `capacity`, `used`, and `current_index`. The constructor begins by allocating a dynamic array of type `Song` with the capacity to hold five songs (this will save on memory space for those users with fewer favorite songs). When the action of adding an additional song to the list happens check if `used == capacity`, and if it does, a resize operation increases the size of the array by five.

This container also has an internal iterator, which requires the functions

- `start`
- `advance`
- `is_item`
- `current`
- `remove_current`
- `insert`
- `attach`

(`show_all`, `releaseDate_sort`, `artist_sort`, `find_song`, and `is_song` are also implemented)

Because this is a dynamic array, a resize function and the **Big 3** (`destructor`, `copy constructor`, and `assignment operator`) are needed. Also, because we are providing file backup, we have functions for `load` and `save`.

Data files should be formatted as follows:

`// first song name`

`// first song artist`

`// first song release date`

And so on for each song.
