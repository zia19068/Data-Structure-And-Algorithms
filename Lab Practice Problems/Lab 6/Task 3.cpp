/*Task # 03:
A file system stores folders inside folders. Each folder can contain files and/or subfolders.
 A file has a fixed size in KB.
 A folder’s total size is the sum of all its files plus the sizes of its subfolders.
Task to do:
Write a recursive function getFolderSize() that takes a folder structure and returns its total size.
(Hint: Use recursion to keep entering subfolders until all files are counted.)*/
#include <iostream>
using namespace std;

struct Folder {
    int file1;
    int file2;
    Folder* sub1;
    Folder* sub2;
};

int getFolderSize(Folder* f) {
    if (f == NULL) {
        return 0;
    }

    int currentFolderFiles = f->file1 + f->file2;
    int subFolderSize1 = getFolderSize(f->sub1);
    int subFolderSize2 = getFolderSize(f->sub2);
    return currentFolderFiles + subFolderSize1 + subFolderSize2;
}

int main() {
    Folder images = {500, 200, NULL, NULL};
    Folder docs = {100, 50, NULL, NULL};
    Folder root = {50, 20, &images, &docs};
    int total;
    cout << "SIMPLE RECURSIVE FILE SYSTEM" << endl;
    total = getFolderSize(&root);
    cout << "Total Root Folder Size: " << total << " KB" << endl;
    return 0;
}
