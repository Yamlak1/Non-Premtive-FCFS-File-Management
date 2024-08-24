
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdio>
#include <dirent.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

bool fileExists(const string& filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

void listFilesAndDirectories() {
    system("ls");
}

void createNewFile(const string& filename, const string& extension) {
    string fullFilename = filename + extension;
    ofstream file(fullFilename);
    if (file.is_open()) {
        cout << "File Created Successfully" << endl;
    }
    file.close();
}

void deleteFile(const string& filename) {
    if (fileExists(filename)) {
        remove(filename.c_str());
        cout << "Successfully Deleted." << endl;
    } else {
        cout << "File Does not Exist..Try again" << endl;
    }
}

void renameFile(const string& oldName, const string& newName) {
    if (fileExists(oldName)) {
        rename(oldName.c_str(), newName.c_str());
        cout << "Successfully Renamed. Now Your File Exists with " << newName << " Name" << endl;
    } else {
        cout << oldName << " does not exist..Try again with correct filename." << endl;
    }
}

void editFileContent(const string& filename) {
    if (fileExists(filename)) {
        string command = "nano " + filename;
        system(command.c_str());
    } else {
        cout << filename << " File does not exist..Try again." << endl;
    }
}

void searchFile(const string& filename) {
    if (fileExists(filename)) {
        string command = "find /home -name " + filename;
        system(command.c_str());
    } else {
        cout << "File Does not Exist..Try again." << endl;
    }
}

void showFileDetails(const string& filename) {
    if (fileExists(filename)) {
        string command = "stat " + filename;
        system(command.c_str());
    } else {
        cout << filename << " File does not exist..Try again." << endl;
    }
}

void viewFileContent(const string& filename) {
    if (fileExists(filename)) {
        string command = "cat " + filename;
        system(command.c_str());
    } else {
        cout << filename << " does not exist" << endl;
    }
}

void sortFileContent(const string& filename) {
    if (fileExists(filename)) {
        string command = "sort " + filename;
        system(command.c_str());
    } else {
        cout << filename << " File does not exist..Try again." << endl;
    }
}

void listDirectories() {
    system("ls -d */");
}

void listFilesWithExtension(const string& extension) {
    string command = "ls *." + extension;
    system(command.c_str());
}

void totalDirectories() {
    system("echo */ | wc -w");
}

void totalFiles() {
    system("ls -l | grep -v 'total' | grep -v '^d' | wc -l");
}

void sortFiles() {
    system("ls | sort");
}

