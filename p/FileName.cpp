#include <iostream>
#include <vector>
#include <string>

class ArtPiece {
public:
    std::string title;
    std::string artist;
    std::string medium;
    double price;

    ArtPiece(const std::string& title, const std::string& artist, const std::string& medium, double price)
        : title(title), artist(artist), medium(medium), price(price) {}
};

class ArtGallery {
private:
    std::vector<ArtPiece> artPieces;

public:
    void addArtPiece(const ArtPiece& artPiece) {
        artPieces.push_back(artPiece);
    }

    void displayArtPieces() {
        for (const auto& artPiece : artPieces) {
            std::cout << "Title: " << artPiece.title << std::endl;
            std::cout << "Artist: " << artPiece.artist << std::endl;
            std::cout << "Medium: " << artPiece.medium << std::endl;
            std::cout << "Price: $" << artPiece.price << std::endl;
            std::cout << std::endl;
        }
    }
};

int main() {
    ArtGallery gallery;

    // Add art pieces to the gallery
    std::string title, artist, medium;
    double price;

    std::cout << "Enter the details of art piece 1:" << std::endl;
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Artist: ";
    std::getline(std::cin, artist);
    std::cout << "Medium: ";
    std::getline(std::cin, medium);
    std::cout << "Price: $";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ArtPiece artPiece1(title, artist, medium, price);

    std::cout << "Enter the details of art piece 2:" << std::endl;
    std::cout << "Title: ";
    std::getline(std::cin, title);
    std::cout << "Artist: ";
    std::getline(std::cin, artist);
    std::cout << "Medium: ";
    std::getline(std::cin, medium);
    std::cout << "Price: $";
    std::cin >> price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ArtPiece artPiece2(title, artist, medium, price);

    int numArtPieces;
    std::cout << "Enter the number of art pieces you want to insert: ";
    std::cin >> numArtPieces;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numArtPieces; i++) {
        std::cout << "Enter the details of art piece " << i + 1 << ":" << std::endl;
        std::cout << "Title: ";
        std::getline(std::cin, title);
        std::cout << "Artist: ";
        std::getline(std::cin, artist);
        std::cout << "Medium: ";
        std::getline(std::cin, medium);
        std::cout << "Price: $";
        std::cin >> price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        ArtPiece artPiece(title, artist, medium, price);
        gallery.addArtPiece(artPiece);
    }

    // Display all art pieces in the gallery
    gallery.displayArtPieces();

    return 0;
}
