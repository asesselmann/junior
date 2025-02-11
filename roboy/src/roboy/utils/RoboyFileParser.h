/*Copyright (c) 2014, University of Zurich, Department of Informatics, Artificial Intelligence Laboratory
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the names of its contributors 
   may be used to endorse or promote products derived from this software without 
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ROBOYFILEPARSER_H
#define ROBOYFILEPARSER_H

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

#define ERROR_PREFIX "[File Parser] Error: "

class RoboyFileParser
{
    public:
        
        RoboyFileParser(std::string filename);
        
        template <class T> T 
        get(std::string section, std::string key, std::string def = "")
        {
        	std::stringstream buffer;
        	T ret;

        	if(!sections.count(section) || !sections[section]->count(key))
        	{
        		buffer << def;
        		// FIXME: Maybe put a warning here
        	} else {
        		buffer << sections[section]->at(key);
        	}

        	buffer >> ret;
        	return ret;
        }
        
        
    public:
        
        static RoboyFileParser* parser;
        
    private:
                
        void error(std::string msg, std::string arg = "");
        
  //      config(config const&);
        
 //       void operator=(config const&);

        std::string filename;
        
        std::map<std::string, std::map<std::string, std::string>* > sections;
};

#endif   // ROBOYFILEPARSER_H
