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
#include "RoboyFacialExpressionBehaviour.h"

namespace Roboy
{

RoboyFacialExpressionBehaviour::RoboyFacialExpressionBehaviour(std::vector<RoboyBodyActivity*> bodyActivities) :
        				RoboyBehaviour(bodyActivities)
{
	mutex.lock();
}

RoboyFacialExpressionBehaviour::~RoboyFacialExpressionBehaviour()
{

}

void
RoboyFacialExpressionBehaviour::setFacialExpression(std::string expression)
{
	this->expression = expression;
}

void
RoboyFacialExpressionBehaviour::init()
{
	std::cout << " FACIALEXPRESSION INIT " << std::endl;
}

void
RoboyFacialExpressionBehaviour::execute()
{

	std::cout << " FACIALEXPRESSION EXECUTE " << std::endl;

	RoboyTextToSpeech *festival = ((RoboyTextToSpeech*)bodyActivities[RoboyBodyActivity::TEXT_TO_SPEECH]);

	face->init(expression);

// shouldn't we do this in terminate() ? //
	//usleep(2000000);  // Serge took this out for e.g. keeping it sleeping. You can change it again.
	//face->breakLoop(); // Serge took this out for e.g. keeping it sleeping. You can change it again. 

	isBehaviourFinished = true;
	//		boost::this_thread::interruption_point();

}

void
RoboyFacialExpressionBehaviour::terminate()
{
	std::cout << " FACIALEXPRESSION TERMINATE " << std::endl;
  face->breakLoop();
}


std::string
RoboyFacialExpressionBehaviour::getInfo()
{
	return "Facial Expression";
}
}
