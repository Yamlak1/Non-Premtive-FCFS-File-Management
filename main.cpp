#include <iostream>
#include <string>
#include <queue>
#include<utility>


// Declare the functions from test.cpp
void listFilesAndDirectories();
void createNewFile(const std::string& filename, const std::string& extension);
void deleteFile(const std::string& filename);
void renameFile(const std::string& oldName, const std::string& newName);
void editFileContent(const std::string& filename);
void searchFile(const std::string& filename);
void showFileDetails(const std::string& filename);
void viewFileContent(const std::string& filename);
void sortFileContent(const std::string& filename);
void listDirectories();
void listFilesWithExtension(const std::string& extension);
void totalDirectories();
void totalFiles();
void sortFiles();

using namespace std;

struct Command {
    int choice;
    string filename;
    string extension;
    string oldName;
    string newName;
};

int main() {

    typedef pair<int, vector<string>> Command;
    queue<Command> commandQueue;

    int choice;
    while (true) {
        cout << "=========================================================================\n";
        cout << "-----------------------File Management Project---------------------------\n";
        cout << "=========================================================================\n";
        cout << "Welcome, The Main Menu is given below:\n";
        cout << "1- List all Files and Directories\n";
        cout << "2- Create New Files\n";
        cout << "3- Delete Existing Files\n";
        cout << "4- Rename Files\n";
        cout << "5- Edit File Content\n";
        cout << "6- Search Files\n";
        cout << "7- Details of Particular File\n";
        cout << "8- View Content of File\n";
        cout << "9- Sort File Content\n";
        cout << "10- List only Directories(Folders)\n";
        cout << "11- List Files of Particular Extension\n";
        cout << "12- Count Number of Directories\n";
        cout << "13- Count Number of Files\n";
        cout << "14- Sort Files in a Directory\n";
        cout << "0- Exit\n";
        cout << "\nWhat action do you want to perform?\nEnter 0-14: ";
        cin >> choice;

        vector <string> params;
        switch (choice) {
            case 1:
            case 10:
            case 12:
            case 13:
            case 14:
                commandQueue.push(make_pair(choice,params));
                break;
            case 2:{
                string filename, extension;
                cout<< "Enter file nmae: ";
                cin >> filename;
                cout<< "Enter fiile extension (eg: .txt): ";
                cin>>extension;
                params.push_back(filename);
                params.push_back(extension);
                commandQueue.push(make_pair(choice,params));
                break;
            }
            case 3:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9: {
                string filename;
                cout<< "Enter file name (with extension): ";
                cin>>filename;
                params.push_back(filename);
                commandQueue.push(make_pair(choice, params));
                break;
            }
            case 4:{
                 string oldName, newName;
                cout << "Enter the old file name (with extension): ";
                cin >> oldName;
                cout << "Enter the new file name: ";
                cin >> newName;
                params.push_back(oldName);
                params.push_back(newName);
                commandQueue.push(make_pair(choice, params));
                break;
            }
            case 11: {
                string extension;
                cout<<"Enter the file extension (eg: .txt) to list files: ";
                cin>> extension;
                params.push_back(extension);
                commandQueue.push(make_pair(choice,params));
                break;
            }
            case 0:
              cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        while (!commandQueue.empty()){
            Command cmd = commandQueue.front();
            commandQueue.pop();

            switch(cmd.first){
                case 1:
                    listFilesAndDirectories();
                    break;
                case 2:
                    createNewFile(cmd.second[0], cmd.second[1]);
                    break;
                case 3:
                    deleteFile(cmd.second[0]);
                    break;
                case 4:
                    renameFile(cmd.second[0], cmd.second[1]);
                    break;
                case 5:
                    editFileContent(cmd.second[0]);
                    break;
                case 6:
                    searchFile(cmd.second[0]);
                    break;
                case 7:
                    showFileDetails(cmd.second[0]);
                    break;
                case 8:
                    viewFileContent(cmd.second[0]);
                    break;
                case 9:
                    sortFileContent(cmd.second[0]);
                    break;
                case 10:
                    listDirectories();
                    break;
                case 11:
                    listFilesWithExtension(cmd.second[0]);
                    break;
                case 12:
                    totalDirectories();
                    break;
                case 13:
                    totalFiles();
                    break;
                case 14:
                    sortFiles();
                    break;
            }
        }
    }

    return 0;
}
