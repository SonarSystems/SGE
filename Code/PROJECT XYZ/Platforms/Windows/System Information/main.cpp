#include "include/SysInfo.hpp"

//main program code loop
int main( )
{
	


	////setting the I/O for our log file to be "myfile"
	//ofstream myfile;
	//// ios::out means that we're outputting data to the file
	//// ios::app means that all the data we're outputting goes to the end of that log file instead of the start
	//myfile.open( "log.csv", ios::out | ios::app );

	Sonar::SysInfo s;

	//a while loop that gathers and logs data every quarter of a second to gather 4 data points in one second
	while ( 1 )
	{
		//Timestamp + Memory Info, and eventually CPU Load percentage

		Sonar::SystemInformation info = s.GetSystemInformation( );
		

		std::cout
			<< info._timestamp._hour << ":"
			<< info._timestamp._minutes << ":"
			<< info._timestamp._seconds << ":"
			<< info._timestamp._milliseconds << " - "
			<< info._gpus.front( )._name << " - "
			<< info._gpus.front( )._manufacturer << " - "
			<< info._gpus.front( )._caption << " - "
			<< info._gpus.front( )._ram << " - "
			<< info._gpus.front( )._refreshRate << " - "
			<< info._gpus.front( )._driverVersion << " - "
			<< info._gpus.front( )._videoArchitecture << " - "
			<< info._gpus.front( )._videoModeDescription << " - "
			<< info._gpus.front( )._videoProcessor << " - "
			<< std::endl;

		//250 millisecond sleep delay 
		Sleep( 100 );
	}
	//close the log file before terminating the program

	return 0; //standard main() end of program terminator
}

