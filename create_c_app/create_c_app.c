#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to create a directory
int createDirectory(const char *path) {
    return mkdir(path, 0755); // Creates a directory with read/write/execute permissions for the owner and read/execute permissions for others
}

// Function to create a file with some content
void createFile(const char *path, const char *content) {
    FILE *file = fopen(path, "w");
    if (file) {
        fputs(content, file);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <project_name>\n", argv[0]);
        return 1;
    }

    const char *projectName = argv[1];

    // Create the project directory
    if (createDirectory(projectName) != 0) {
        perror("Error creating project directory");
        return 1;
    }

    // Change into the project directory
    if (chdir(projectName) != 0) {
        perror("Error changing into project directory");
        return 1;
    }

    // Create subdirectories
    createDirectory("_opt");
    createDirectory("bin");
    createDirectory("doc");
    createDirectory("include");
    createDirectory("obj");
    createDirectory("src");
    createDirectory("test");

    // Create Makefile
    createFile("Makefile", "CC = gcc\nCFLAGS = -Wall\n\nall: main\n\nmain: src/main.c\n\t$(CC) $(CFLAGS) -o bin/main src/main.c\n\nclean:\n\trm -f bin/main\n");
    // Set permissions on the Makefile
    chmod("Makefile", 0744); // Read and write permissions for the owner, read-only for others

    // Create style_guide.md
    const char *styleGuideContent = "# Project Style Guide\n\n"
                                    "## Introduction\n"
                                    "This style guide outlines the coding conventions and best practices to follow when working on the [Your Project Name] project. Consistency in code formatting and organization is essential to ensure readability and maintainability of the codebase.\n\n"
                                    "## Table of Contents\n"
                                    "1. [Naming Conventions](#naming-conventions)\n"
                                    "2. [Code Formatting](#code-formatting)\n"
                                    "3. [Comments](#comments)\n"
                                    "4. [Indentation](#indentation)\n"
                                    "5. [Functions](#functions)\n"
                                    "6. [Header Files](#header-files)\n"
                                    "7. [Error Handling](#error-handling)\n"
                                    "8. [Testing](#testing)\n\n"
                                    "Add your custom style guide content here.";

    createFile("style_guide.md", styleGuideContent);

    // Create main.c with "Hello, World!" example
    createFile("src/main.c", "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, World!\\n\");\n    return 0;\n}\n");

    printf("Project '%s' has been created successfully.\n", projectName);

    return 0;
}
