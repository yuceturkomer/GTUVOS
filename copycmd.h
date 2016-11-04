#ifndef COPYCMD_H
#define COPYCMD_H

#include <QApplication>
#include "command.h"
#include <string>
#include "gtuvos.h"

// begin of the library about copyFile function
#include <iostream>
#include <sys/sendfile.h>  // sendfile
#include <fcntl.h>         // open
#include <unistd.h>        // close
#include <sys/stat.h>      // fstat
#include <sys/types.h>     // fstat
#include <dirent.h>        // DIR
// end of the library about copyFile function


// begin of the constant variables about copyFile function
const static int  SUCCESS_STATUS = 0;
const static int  SUCCESS_COPY_FILE = 0;
const static int  IF_THE_FILE_ALREADY_EXISTS_DO_NOTHING = 1;
const static int  IF_THE_FILE_ALREADY_EXISTS_CHANGE_FILE_NAME = 2;
const static int  IF_THE_FILE_ALREADY_EXISTS_OVERWRITE = 3;
const static int  FAIL_COPY_FILE = -1;
const static int  FILE_PATH_NOT_EXIST_OR_NOT_A_FILE = -2;
const static int  TARGET_PATH_NOT_EXIST_OR_NOT_A_DIRECTORY = -3;
const static int  CREATED_FILE_DELETED_DURING_COPY_PROCESS = -4;
// end of the constant variables about copyFile function

using namespace  std;

class CopyCMD : public ICommand
{
public:
    ~CopyCMD();
    CopyCMD(QStringList params);
    void execute(Ui::MainWindow *window);
    /*
     * Copy the file to the target path
     *
     * SUCCESSFUL CASES:
     *
     * If target path have not a file which have a same name like given file name then:
     *      -if the file copy process happens, then return SUCCESS_COPY_FILE.
     *
     * If target path have a file which have a same name like given file name then:
     *      -if ifTheFileAlreadyExists IF_THE_FILE_ALREADY_EXISTS_DO_NOTHING, then do nothing and return IF_THE_FILE_ALREADY_EXISTS_DO_NOTHING
     *      -if ifTheFileAlreadyExists IF_THE_FILE_ALREADY_EXISTS_CHANGE_FILE_NAME, then change the file name which will created and return IF_THE_FILE_ALREADY_EXISTS_CHANGE_FILE_NAME
     *      -if ifTheFileAlreadyExists IF_THE_FILE_ALREADY_EXISTS_OVERWRITE, then overwrite the existing file and return IF_THE_FILE_ALREADY_EXISTS_OVERWRITE
     *
     *
     * UNSUCCESSFUL CASES:
     *
     * If the file copy process fails, then return FAIL_COPY_FILE.
     * If filePath (include file name) is not exist or is not a file name then return FILE_PATH_NOT_EXIST_OR_NOT_A_FILE.
     * If targetPath is not exist or is not a directory name then return TARGET_PATH_NOT_EXIST_OR_NOT_A_DIRECTORY.
     * if the created file was deleted during the process then return CREATED_FILE_DELETED_DURING_COPY_PROCESS.
     *
     * @param filePath which is the path of the file to be copied (include file name)
     * @param targetPath which  the path of the target directory
     * @param ifTheFileAlreadyExists can be IF_THE_FILE_ALREADY_EXISTS_DO_NOTHING or IF_THE_FILE_ALREADY_EXISTS_CHANGE_FILE_NAME or IF_THE_FILE_ALREADY_EXISTS_OVERWRITE.
     * @param theNameOfTheCopyFileCreated is file name which will created. If the function fails then it does not matter.
     * @return It depends on the situation.
     */
    int copyFile(string filePath, string targetPath, int ifTheFileAlreadyExists, string* theNameOfTheCopyFileCreated);

    /*
     * Is given file path a file name
     *
     * @param filePath will checked.
     * @return filePath is a file name then return true. otherwise return false.
     */
    bool isItAFile(string filePath);

    /*
     * Is given directory path a directory name
     *
     * @param dirPath will checked.
     * @return dirPath is a directory name then return true. otherwise return false.
     */
    bool isItADirectory(string dirPath);

    /*
     * Find The File Name In Given Path
     *
     * @param filePath need for search
     * @param theNameOfTheFileToBeCopied will be file name.
     */
    void findTheFileNameInGivenPath(string filePath, string* theNameOfTheFileToBeCopied);

    /*
     * Merge The Given Path And Given File Name
     *
     * @param Path is beginning of the newPath
     * @param fileName is ending of the newPath
     * @param newPath will created.
     */
    void mergethePathAndFileName(string Path, string fileName, string* newPath);

    /*
     * Copy From Source File To Destination File
     *
     * @param sourceFile is source file for copy process
     * @param destinationFile is destination file for copy process
     * @return copy fails then return false otherwise return true.
     */
    bool copyFromSourceFileToDestinationFile(int sourceFile, int destinationFile);

    /*
     * Find The Unique Name In The Path
     *
     * @param filePath is source path for finding process
     * @param newFileName will created.
     * @return is not important
     */
    bool findTheUniqueNameInThePath(string* filePath);
};

#endif // COPYCMD_H
