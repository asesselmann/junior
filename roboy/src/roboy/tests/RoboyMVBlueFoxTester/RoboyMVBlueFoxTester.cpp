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



#include <iostream>
#include <string>

#include "RoboyMVBlueFox.h"
#include "capture/RoboyCaptureMVBlueFox.h"

int main()
{


	std::cerr << " OLE " << std::endl;
	Roboy::RoboyCaptureMVBlueFox* capture = new Roboy::RoboyCaptureMVBlueFox( 0 );
	std::cerr << " OLE2 " << std::endl;
	capture->start();

//	RoboyMVBlueFox* capture = new RoboyMVBlueFox( );

	usleep(10000000);
	
	while(1)
	{
		cv::Mat image = capture->getFrame();

		imshow("Hello from mvBlueFOX", image);

		char key = (char) cv::waitKey(20);

		if ( key == 27 )
			break;


		
	}

	// capture->stop();


	//
	//	
	//	 while(1)
	//	 {
	//		 
	//		 imshow("Hello from mvBlueFOX", imagetmp);
	////		 
	//		 char key = (char) cv::waitKey(20);
	////
	//		 if ( key == 27 )
	//			 break;
	////
	//	 }
	//


	return 0;
}


