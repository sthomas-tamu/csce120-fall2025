#include <iostream>
#include <string>
#include <vector>

class Song {
    std::string title;
    std::string artist;
    std::string genre;
    unsigned int duration; // in seconds

  public:
    Song() : title(""), artist(""), genre(""), duration(0) {}
    Song(std::string t, std::string a, std::string g, unsigned int d) : title(t), artist(a), genre(g), duration(d) {}
    ~Song() {}

    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getGenre() const { return genre; }
    unsigned int getDuration() const { return duration; }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << s.getTitle() << " by " << s.getArtist() << " [" << s.getGenre() << "] (" << s.getDuration() << "s)";
    return os;
}

void displayPlaylist(std::string label, const std::vector<Song*>& playlist) {
    std::cout << label << ":" << std::endl;
    for(unsigned int i=0; i<playlist.size(); ++i) {
        std::cout << "\t" << *(playlist.at(i)) << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // create a list of songs on the heap
    Song* song1 = new Song("Bohemian Rhapsody", "Queen", "Rock", 354);
    Song* song2 = new Song("Imagine", "John Lennon", "Rock", 183);
    Song* song3 = new Song("Billie Jean", "Michael Jackson", "Pop", 294);
    Song* song4 = new Song("Hotel California", "Eagles", "Rock", 391);

    // add them to the complete playlist
    std::vector<Song*> complete;
    complete.push_back(song1);
    complete.push_back(song2);
    complete.push_back(song3);
    complete.push_back(song4);

    // add only rock songs to a new playlist
    std::vector<Song*> rock;
    for(unsigned int i=0; i<complete.size(); ++i) {
        if(complete.at(i)->getGenre() == "Rock") {
            rock.push_back(complete.at(i));
        }
    }

    // add not rock songs to a new playlist
    std::vector<Song*> not_rock;
    for(unsigned int i=0; i<complete.size(); ++i) {
        if(complete.at(i)->getGenre() != "Rock") {
            not_rock.push_back(complete.at(i));
        }
    }

    // print each playlist
    displayPlaylist("Complete List", complete);
    displayPlaylist("Rock List", rock);
    displayPlaylist("Not Rock List", not_rock);

    // release memory of complete list
    for(unsigned int i=0; i<complete.size(); ++i) {
        delete complete.at(i);
        complete.at(i) = nullptr;
    }

    return 0;
}
