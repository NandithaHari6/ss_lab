#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct File {
    char name[MAX_NAME_LENGTH];
    int size;
};

struct Directory {
    char name[MAX_NAME_LENGTH];
    struct File* files;
    int fileCount;
    struct Directory* subDirectories;
    int subDirectoryCount;
};

struct File createFile(const char* name, int size) {
    struct File newFile;
    strcpy(newFile.name, name);
    newFile.size = size;
    return newFile;
}

struct Directory createDirectory(const char* name) {
    struct Directory newDirectory;
    strcpy(newDirectory.name, name);
    newDirectory.files = NULL;
    newDirectory.fileCount = 0;
    newDirectory.subDirectories = NULL;
    newDirectory.subDirectoryCount = 0;
    return newDirectory;
}

void addFileToDirectory(struct File file, struct Directory* directory) {
    directory->fileCount++;
    directory->files = (struct File*)realloc(directory->files, directory->fileCount * sizeof(struct File));
    directory->files[directory->fileCount - 1] = file;
}

void addSubDirectory(struct Directory subDirectory, struct Directory* parentDirectory) {
    parentDirectory->subDirectoryCount++;
    parentDirectory->subDirectories = (struct Directory*)realloc(parentDirectory->subDirectories, parentDirectory->subDirectoryCount * sizeof(struct Directory));
    parentDirectory->subDirectories[parentDirectory->subDirectoryCount - 1] = subDirectory;
}

void listDirectoryContents(struct Directory directory) {
    printf("Contents of Directory '%s':\n", directory.name);
    for (int i = 0; i < directory.fileCount; i++) {
        printf("File: %s, Size: %d bytes\n", directory.files[i].name, directory.files[i].size);
    }
    for (int i = 0; i < directory.subDirectoryCount; i++) {
        printf("Subdirectory: %s\n", directory.subDirectories[i].name);
    }
}

void deleteFileFromDirectory(const char* fileName, struct Directory* directory) {
    for (int i = 0; i < directory->fileCount; i++) {
        if (strcmp(directory->files[i].name, fileName) == 0) {
            for (int j = i; j < directory->fileCount - 1; j++) {
                directory->files[j] = directory->files[j + 1];
            }
            directory->fileCount--;
            directory->files = (struct File*)realloc(directory->files, directory->fileCount * sizeof(struct File));
            printf("File '%s' deleted from directory '%s'\n", fileName, directory->name);
            return;
        }
    }
    printf("File '%s' not found in directory '%s'\n", fileName, directory->name);
}

void deleteSubDirectory(const char* subDirName, struct Directory* parentDirectory) {
    for (int i = 0; i < parentDirectory->subDirectoryCount; i++) {
        if (strcmp(parentDirectory->subDirectories[i].name, subDirName) == 0) {
            for (int j = i; j < parentDirectory->subDirectoryCount - 1; j++) {
                parentDirectory->subDirectories[j] = parentDirectory->subDirectories[j + 1];
            }
            parentDirectory->subDirectoryCount--;
            parentDirectory->subDirectories = (struct Directory*)realloc(parentDirectory->subDirectories, parentDirectory->subDirectoryCount * sizeof(struct Directory));
            printf("Subdirectory '%s' deleted from directory '%s'\n", subDirName, parentDirectory->name);
            return;
        }
    }
    printf("Subdirectory '%s' not found in directory '%s'\n", subDirName, parentDirectory->name);
}

void freeDirectory(struct Directory* directory) {
    free(directory->files);
    free(directory->subDirectories);
}

int main() {
    struct Directory root = createDirectory("Root");
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create File\n");
        printf("2. Create Subdirectory\n");
        printf("3. List Directory Contents\n");
        printf("4. Delete File\n");
        printf("5. Delete Subdirectory\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char fileName[MAX_NAME_LENGTH];
                int fileSize;
                printf("Enter file name: ");
                scanf("%s", fileName);
                printf("Enter file size: ");
                scanf("%d", &fileSize);
                struct File newFile = createFile(fileName, fileSize);
                addFileToDirectory(newFile, &root);
                break;
            }
            case 2: {
                char subDirName[MAX_NAME_LENGTH];
                printf("Enter subdirectory name: ");
                scanf("%s", subDirName);
                struct Directory newSubDir = createDirectory(subDirName);
                addSubDirectory(newSubDir, &root);
                break;
            }
            case 3:
                listDirectoryContents(root);
                break;
            case 4: {
                char fileName[MAX_NAME_LENGTH];
                printf("Enter file name to delete: ");
                scanf("%s", fileName);
                deleteFileFromDirectory(fileName, &root);
                break;
            }
            case 5: {
                char subDirName[MAX_NAME_LENGTH];
                printf("Enter subdirectory name to delete: ");
                scanf("%s", subDirName);
                deleteSubDirectory(subDirName, &root);
                break;
            }
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    // Free the allocated memory
    freeDirectory(&root);

    return 0;
}