/**
 * Virtual Operating System
 *
 * File:   VirtualOperatingSystemForm.cpp.cc
 *
 * Description:
 *
 * 
 *
 *
 * @author CSE_343_Software Engineering_Group_2
 * @since Monday 10 October 2016
 */

#include "VirtualOperatingSystemForm.h"

namespace
{
    /**
     * For Constant Variables
     * 
     */
}

namespace GtuVirtualOperatingSystem
{      
    /**
    * Default Constructors
    *
    * Call the runOS function for system preparation
    */
    VirtualOperatingSystemForm::VirtualOperatingSystemForm() {
        runOS(); // For system preparation
    }

    /**
    * Virtual Constructors
    */
    VirtualOperatingSystemForm::~VirtualOperatingSystemForm() {
    }

    /**
    * This function is called when Program when the program starts
    * 
    * -Set "widget" variable
    * -Set "isItClosed" variable true
    * -Check the our source directory
    * -Call the readInput function for read input from the terminal
    */
    void VirtualOperatingSystemForm::runOS(){

        setWidget(); //Set "widget" variable
        setIsItClosed(true); // Set "isItClosed" variable true
        checkSourceFileDirectory(); // Check the our source directory
        readInput(); // for read input from the terminal
    }
    
    /**
    * Check the our source directory
    * 
    * -Check the our source directory which is called "SourceFileGtuOS". 
    * if the "SourceFileGtuOS" directory doesn't exist then create it.  
    */
    void VirtualOperatingSystemForm::checkSourceFileDirectory(){
        
        /**
         * You must implement this function
         */
    }

    /**
    * This function is read input from the terminal
    * 
    * -Read input from the terminal
    * -Call the parseString function
    * -If "isItClosed" variable true then wait the next input.
    * -if "isItClosed" variable false then interrupt loop
    */
    void VirtualOperatingSystemForm::readInput(){
        
        /**
         * You must implement this function
         * You need some Qt skills.
         */
        
    }

    /**
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
    void VirtualOperatingSystemForm::parseString(string newString){
        
        /**
         * You must implement this function
         */
    }

    /**
    * Print All available commands On The Screen
    * 
    * -Use writeGivenStringOnTheScreen function for print
    */
    void VirtualOperatingSystemForm::helpOSForCommands(){
        
        /**
         * You must implement this function
         */
        
    }

    /**
    * Copy the file to the target path
    * 
    * -Copy the file to the target path
    * -If target path have a file which have a same name like given file name 
    * then change the given file name.
    * 
    * @param file Path
    * @param Target Path
    */
    void VirtualOperatingSystemForm::copyGivenFile(string filePath, string TargetPath){
        
        /**
         * You must implement this function
         */
        
    }
    
    /**
    * Get MailBox Object and run it.
    */
    void VirtualOperatingSystemForm::getMailBox(){
        mailbox.runMailBox();
        mailbox.show();
    }

    /**
     * Print Given String On The Screen
     * 
     * @param newString will printed
     */
    void VirtualOperatingSystemForm::writeGivenStringOnTheScreen(string newString){
        
        /**
         * You must implement this function
         * You need some Qt skills.
         */
        
    }
    
    /**
    * Shutdown Operating System
    * 
    * -Set "isItClosed" variable false
    * -Handle other stuff
    */
   void VirtualOperatingSystemForm::shutdownOS() {
       setIsItClosed(false); // Set "isItClosed" variable false
       
       /**
         * You must implement this function
         */
   
   } 

    /*EXTRA COMMANDS*/

    /**
     * It works like LINUX 'ls' command
     */
    void VirtualOperatingSystemForm::ls(){
        
        /**
         * You will implement this function
         */
    }

    /**
     * It works like LINUX 'mkdir' command
     */
    void VirtualOperatingSystemForm::mkdir(){
        
        /**
         * You will implement this function
         */
    }

    /**
     * It works like LINUX 'mkdir' command
     */
    void VirtualOperatingSystemForm::cd(){
        
        /**
         * You will implement this function
         */
    }
}