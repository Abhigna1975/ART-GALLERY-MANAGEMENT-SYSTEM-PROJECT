#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent an artwork
struct Artwork {
    string title;
    string artist;
    string medium;
    double price;
    bool sold;
};

// Function to add a new artwork
void addArtwork(vector<Artwork>& artworks) {
    Artwork newArtwork;
    cout << "Enter Artwork title: ";
    getline(cin >> ws, newArtwork.title);
    cout << "Enter Artist name: ";
    getline(cin >> ws, newArtwork.artist);
    cout << "Enter Medium: ";
    getline(cin >> ws, newArtwork.medium);
    cout << "Enter Price: $";
    cin >> newArtwork.price;
    newArtwork.sold = false;
    artworks.push_back(newArtwork);
}

// Function to view all artworks
void viewArtworks(const vector<Artwork>& artworks) {
    if (artworks.empty()) {
        cout << "No artworks to display." << endl;
        return;
    }
    cout << "Artworks:" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << setw(20) << "Title" << setw(20) << "Artist" << setw(20) << "Medium" << setw(10) << "Price" << setw(12) << "Sold" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (const auto& artwork : artworks) {
        cout << setw(20) << artwork.title << setw(20) << artwork.artist << setw(20) << artwork.medium << setw(10) << "$" << artwork.price << setw(12) << (artwork.sold ? "Yes" : "No") << endl;
    }
    cout << "-------------------------------------------------------" << endl;
}

// Function to mark an artwork as sold
void markArtworkSold(vector<Artwork>& artworks) {
    if (artworks.empty()) {
        cout << "No artworks available to mark as sold." << endl;
        return;
    }
    int index;
    cout << "Enter index of artwork to mark as sold: ";
    cin >> index;
    if (index >= 0 && index < artworks.size()) {
        artworks[index].sold = true;
        cout << "Artwork marked as sold." << endl;
    }
    else {
        cout << "Invalid index." << endl;
    }
}

// Function to delete an artwork
void deleteArtwork(vector<Artwork>& artworks) {
    if (artworks.empty()) {
        cout << "No artworks available to delete." << endl;
        return;
    }
    int index;
    cout << "Enter index of artwork to delete: ";
    cin >> index;
    if (index >= 0 && index < artworks.size()) {
        artworks.erase(artworks.begin() + index);
        cout << "Artwork was deleted." << endl;
    }
    else {
        cout << "Invalid index." << endl;
    }
}

// Function to save artworks to a file
void saveArtworksToFile(const vector<Artwork>& artworks, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& artwork : artworks) {
            outFile << artwork.title << "," << artwork.artist << "," << artwork.medium << "," << artwork.price << "," << (artwork.sold ? "1" : "0") << endl;
        }
        cout << "Artworks saved to " << filename << endl;
    }
    else {
        cout << "Error: Unable to open file " << filename << " for writing." << endl;
    }
}

// Function to load artworks from a file
void loadArtworksFromFile(vector<Artwork>& artworks, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        artworks.clear();
        string line;
        while (getline(inFile, line)) {
            Artwork artwork;
            size_t commaPos = line.find(',');
            artwork.title = line.substr(0, commaPos);
            line.erase(0, commaPos + 1);

            commaPos = line.find(',');
            artwork.artist = line.substr(0, commaPos);
            line.erase(0, commaPos + 1);

            commaPos = line.find(',');
            artwork.medium = line.substr(0, commaPos);
            line.erase(0, commaPos + 1);

            commaPos = line.find(',');
            artwork.price = stod(line.substr(0, commaPos));
            line.erase(0, commaPos + 1);

            artwork.sold = (line == "1");

            artworks.push_back(artwork);
        }
        cout << "Artworks loaded from " << filename << endl;
    }
    else {
        cout << "Error: Unable to open file " << filename << " for reading. Creating new file." << endl;
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Error: Unable to create file." << endl;
        }
    }
}

int main() {
    vector<Artwork> artworks;
    string filename = "artworks.txt";
    loadArtworksFromFile(artworks, filename);

    int choice;
    do {
        cout << "\nArt Gallery Management System" << endl;
        cout << "1. Add Artwork" << endl;
        cout << "2. View Artworks" << endl;
        cout << "3. Mark Artwork as Sold" << endl;
        cout << "4. Delete Artwork" << endl;
        cout << "5. Save Artworks" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addArtwork(artworks);
            break;
        case 2:
            viewArtworks(artworks);
            break;
        case 3:
            markArtworkSold(artworks);
            break;
        case 4:
            deleteArtwork(artworks);
            break;
        case 5:
            saveArtworksToFile(artworks, filename);
            break;
        case 6:
            cout << "Exiting program. Saving artworks..." << endl;
            saveArtworksToFile(artworks, filename);
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    return 0;
}
