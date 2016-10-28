#ifndef GTUVOS_H
#define GTUVOS_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class GTUVOS{

public:

    // singleton system design
    static GTUVOS* getInstance(){
        if(instance == NULL)
            instance = new GTUVOS();

        return instance;
    }

    bool executeCmd(string str); // execute command and return result

    double getVersion() const; // get system version number
    string getName() const; // get system name

    /*
    * This function is called when Program when the program starts
    *
    * -Set "widget" variable
    * -Set "isItClosed" variable true
    * -Check the our source directory
    * -Call the readInput function for read input from the terminal
    */
    void runOS();

    /*
     * Check the our source directory
     *
     * -Check the our source directory which is called "SourceFileGtuOS".
     * if the "SourceFileGtuOS" directory doesn't exist then create it.
     */
    void checkSourceFileDirectory();

    /*
     * This function is read input from the terminal
     *
     * -Read input from the terminal
     * -Call the parseString function
     * -If "isItClosed" variable true then wait the next input.
     * -if "isItClosed" variable false then interrupt loop
     */
    void readInput();

    /*
     * This function parses the newString, then calls the appropriate function
     *
     * -parse the newString
     * -if newString is meaningful then call the appropriate command
     * -if newString is not meaningful then call the function
     * "writeGivenStringOnTheScreen" and give the error message.
     *
     * Available commands:
     *      -copyGivenFile
     *      -getMailBox
     *      -shutdownOS
     *      -helpOSForCommands
     *
     * @param newString will parsed
     */
    void parseString(string newString);

    /*
     * Print All available commands On The Screen
     *
     * -Use writeGivenStringOnTheScreen function for print
     */
    void helpOSForCommands();

    /*
     * Copy the file to the target path
     *
     * -Copy the file to the target path
     * -If target path have a file which have a same name like given file name
     * then change the given file name.
     *
     * @param file Path
     * @param Target Path
     */
    void copyGivenFile(string filePath, string TargetPath);

    /*
     * Get MailBox Object and run it.
     */
    void getMailBox();

    /*
     * Print Given String On The Screen
     *
     * @param newString will written
     */
    void writeGivenStringOnTheScreen(string newString);

    /*
     * Shutdown Operating System
     *
     * -Set "isItClosed" variable false
     * -Handle other stuff
     */
    void shutdownOS();


    /*EXTRA COMMANDS*/

    /*
     * It works like LINUX 'ls' command
     */
    void ls();

    /*
     * It works like LINUX 'mkdir' command
     */
    void mkdir();

    /*
     * It works like LINUX 'mkdir' command
     */
    void cd();

private:
    void prepareSystem();
    GTUVOS(); // singleton design
    string name;
    double version;
    static GTUVOS *instance;

    vector<string> parseStr(string str);

};


#endif // GTUVOS_H
