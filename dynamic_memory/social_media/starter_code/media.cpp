#include <iostream>
#include <string>

class SocialMediaPost {
  private:
    std::string text;      // content of the post
    unsigned int numLikes; // number of numLikes 
    int* likedBy;          // ids of those who liked the post

  public:
    // default constructor
    SocialMediaPost(const std::string& s = "") : text{std::string{s}}, numLikes{0}, likedBy{nullptr} {}

    // copy constructor
    SocialMediaPost(const SocialMediaPost& source) : text{source.text}, numLikes{source.numLikes}, likedBy{nullptr} {
        if(source.numLikes != 0) {
            likedBy = new int[source.numLikes];
            for(unsigned int i=0; i<source.numLikes; ++i) {
                likedBy[i] = source.likedBy[i];
            }
        }
    }

    // destructor
    ~SocialMediaPost() {
        //TODO: clean up memory
    }

    // copy assignment operator
    SocialMediaPost& operator=(const SocialMediaPost& source) {
        //TODO: implement, being careful with handling memory       
        
        return *this;
    }

    // getter methods
    std::string getText() const {
        return text;
    }

    unsigned int getNumLikes() const {
        return numLikes;
    }

    int getLike(int index) const {
        return likedBy[index];
    }

    // someone likes the post!
    void addLike(int personId) {
        // only add if not already in list
        // TODO: implement!
    }
};

// output operator
std::ostream& operator<<(std::ostream& os, const SocialMediaPost& post) {
    os << "\tText: \"" << post.getText() << "\"\n";
    os << "\t" << post.getNumLikes() << " likes\n";
    if(post.getNumLikes() > 0) {
        os << "\tpeople who liked this post:";
        for(unsigned int i=0; i<post.getNumLikes(); ++i) {
            os << " " << post.getLike(i);
        }
        os << std::endl;
    }
    return os;
}

int main() {
    // create a social media post, have several people like it
    SocialMediaPost post("The best day ever!");
    post.addLike(5);
    post.addLike(2);
    post.addLike(4);
    post.addLike(2);
    std::cout << "My post:\n" << post << std::endl;

    // create another social media post, no one likes it yet
    SocialMediaPost post2("Another great day.");
    std::cout << "Another post:\n" << post2 << std::endl;

    // copy one post to another
    post2 = post;
    std::cout << "Set this post to the original one. It is now:\n" << post2 << std::endl;

    return 0;
}
