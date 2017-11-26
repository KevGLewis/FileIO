//
//  lastStart.cpp
//  LastStart
//
//  Created by Kevin Lewis on 10/10/17.
//  Copyright © 2017 Kevin Lewis. All rights reserved.
//

#include "lastStart.hpp"

void lastStartShell(std::string filenameIn){
    
    std::vector<activity> activities; // Holds activities
    int actNumber; // Holds the number of activities in a set
    std::string line; // Used to read lines from file
    int count = 0;
    
    //Open the file data file
    
    std::ifstream fileIn;
    
    fileIn.open(filenameIn);
    
    if (!fileIn) {
        std::cerr << "Unable to open file";
        std::exit(1);
    }
    
    // The follows the following format: first line - number of activities
    // follow by the activities on the preceeding lines.
    // Therefore, first, get the number of activities
    
    std::getline(fileIn, line);
    std::stringstream streamIn(line);
    
    streamIn >> actNumber;
    
    while (!fileIn.eof()){
        
        count++;
        
        std::cout << "Set " << count << std::endl;
        
        activities.clear();
        
        activities = parseFile(fileIn, actNumber);
        
        lastStart(activities);
        
        std::cout << std::endl;
        
        std::getline(fileIn, line);
        streamIn.clear();
        streamIn.str(line);
        
        streamIn >> actNumber;
        
    }
    
    fileIn.close();
}

std::vector<activity> parseFile(std::ifstream &fileIn, int &actNumb){
    
    // The data follows the following format: first line - number of activities
    // follow by the activities on the preceeding lines.
    // Therefore, first, get the number of activities
    
    std::vector<activity> vectorOut(actNumb);
    std::stringstream streamIn;
    std::string line;

    // Get a line from the file and convert it to a stringstream, then push the numbers to
    // the activity struct
    
    for(int i = 0; i < actNumb; i++){
    
        std::getline(fileIn, line);
        
        streamIn.clear();
        streamIn.str(line);
        
        // Data is number, start time, end time
        
        streamIn >> vectorOut.at(i).number;
        streamIn >> vectorOut.at(i).startTime;
        streamIn >> vectorOut.at(i).endTime;

    }
    
    return vectorOut;
}
