#include "../include/SysInfo.hpp"

namespace Sonar
{

	SysInfo::SysInfo( const MemoryFormat &memoryFormat, const bool loadSystemInfo )
	{
		switch ( memoryFormat )
		{
			case MemoryFormat::Bits:
				_memoryFormatMultiplier = 8.0f;

				break;

			case MemoryFormat::Bytes:
				_memoryFormatMultiplier = 1.0f;

				break;

			case MemoryFormat::Kilobytes:
				_memoryFormatMultiplier = MEMORY_MULTIPLIER;

				break;

			case MemoryFormat::Megabytes:
				_memoryFormatMultiplier =  pow( MEMORY_MULTIPLIER, 2.0f );

				break;

				/*
				* NOT NEEDED BUT LEFT INCASE DEFAULT VALUE CHANGED IN HEADER
			case MemoryFormat::Gigabytes:
				_memoryFormatMultiplier = 1024.0f * 1024.0f * 1024.0f;

				break;
				*/
		}

		if ( loadSystemInfo )
		{ LoadSystemInformation( ); }
	}

	const Sonar::SystemInformation &SysInfo::GetSystemInformation( )
	{
		SYSTEMTIME sysTime;
		MEMORYSTATUSEX memStat;

		memStat.dwLength = sizeof( memStat );

		GlobalMemoryStatusEx( &memStat );
		GetSystemTime( &sysTime );

		// Timestamp
		_systemInformation._timestamp._hour = sysTime.wHour;
		_systemInformation._timestamp._minutes = sysTime.wMinute;
		_systemInformation._timestamp._seconds = sysTime.wSecond;
		_systemInformation._timestamp._milliseconds = sysTime.wMilliseconds;
		_systemInformation._timestamp._day = sysTime.wDay;
		_systemInformation._timestamp._month = sysTime.wMonth;
		_systemInformation._timestamp._year = sysTime.wYear;
		_systemInformation._timestamp._dayOfTheWeek = sysTime.wDayOfWeek;

		// Load (in percentage)
		_systemInformation._cpuLoad = GetCPULoad( ) * 100.0f;
		_systemInformation._memoryLoad = memStat.dwMemoryLoad;

		// Memory stats
		_systemInformation._physicalAvailableMemory = memStat.ullAvailPhys / _memoryFormatMultiplier;
		_systemInformation._physicalTotalMemory = memStat.ullTotalPhys / _memoryFormatMultiplier;
		_systemInformation._pageFileAvailableMemory = memStat.ullAvailPageFile /  _memoryFormatMultiplier;
		_systemInformation._pageFileTotalMemory = memStat.ullTotalPageFile / _memoryFormatMultiplier;
		_systemInformation._virtualAvailableMemory = memStat.ullAvailVirtual / _memoryFormatMultiplier;
		_systemInformation._virtualTotalMemory = memStat.ullTotalVirtual / _memoryFormatMultiplier;
		_systemInformation._virtualExtendedAvailableMemory = memStat.ullAvailExtendedVirtual / _memoryFormatMultiplier;

		return _systemInformation;
	}

	void SysInfo::LoadSystemInformation( )
	{
		//First make a delegate object that handles the cases where the computer has multiple CPUs
		std::unique_ptr<CPUInfoDelegate> cpuInfo = std::make_unique<CPUInfoDelegate>( );

		//Then extract the separate CPUs into a vector (of CPUInfo objects)
		std::vector<CPUInfo> cpuInfoVector{ cpuInfo->cpuInfoVector( ) };

		//Print out the number of CPUs, directory from the delegate object
		_systemInformation._numberOfPhysicalCPUs = cpuInfo->numberOfCPUInfoItems( );

		for ( std::vector<CPUInfo>::const_iterator iter = cpuInfoVector.begin( ); iter != cpuInfoVector.end( ); iter++ )
		{
			CPU cpu;

			cpu._cpuNumber = iter->cpuNumber( ) + 1;
			cpu._name = iter->name( );
			cpu._manufacturer = iter->manufacturer( );
			cpu._coreCount = iter->numberOfCores( );
			cpu._clockSpeed = iter->currentClockSpeed( );
			cpu._architecture = iter->architecture( );
			cpu._l2CacheSize = iter->L2CacheSize( );
			cpu._l3CacheSize = iter->L3CacheSize( );
			cpu._temperature = iter->currentTemperature( );

			_systemInformation._cpus.push_back( cpu );
		}

		std::unique_ptr<MotherboardInfoDelegate> moboInfo = std::make_unique<MotherboardInfoDelegate>( );
		std::vector<MotherboardInfo> moboInfoVector = moboInfo->motherboardInfoVector( );
		_systemInformation._numberOfPhysicalMotherboards = moboInfo->numberOfMotherboardInfoItems( );

		for ( std::vector<MotherboardInfo>::const_iterator iter = moboInfoVector.begin( ); iter != moboInfoVector.end( ); iter++ )
		{
			Motherboard motherboard;

			motherboard._motherboardNumber = iter->motherboardNumber( ) + 1;
			motherboard._name = iter->name( );
			motherboard._manufacturer = iter->manufacturer( );
			motherboard._chipset = iter->chipset( );
			motherboard._serialNumber = iter->serialNumber( );
			motherboard._version = iter->version( );

			_systemInformation._motherboards.push_back( motherboard );
		}

		std::unique_ptr<RAMInfoDelegate> ramInfo = std::make_unique<RAMInfoDelegate>( );
		std::vector<RAMInfo> ramInfoVector = ramInfo->ramInfoVector( );
		_systemInformation._numberOfPhysicalRAMSticks = ramInfo->numberOfRAMInfoItems( );

		for ( std::vector<RAMInfo>::const_iterator iter = ramInfoVector.begin( ); iter != ramInfoVector.end( ); iter++ )
		{
			RAM ram;

			ram._ramNumber = iter->ramNumber( ) + 1;
			ram._name = iter->name( );
			ram._manufacturer = iter->manufacturer( );
			ram._capacity = iter->capacity( );
			ram._serialNumber = iter->serialNumber( );
			ram._formFactor = iter->formFactor( );
			ram._partNumber = iter->partNumber( );
			ram._memoryType = iter->memoryType( );
			ram._clockSpeed = iter->clockSpeed( );
			
			_systemInformation._ramSticks.push_back( ram );
		}

		std::unique_ptr<GPUInfoDelegate> gpuInfo = std::make_unique<GPUInfoDelegate>( );
		std::vector<GPUInfo> gpuInfoVector = gpuInfo->gpuInfoVector( );
		_systemInformation._numberOfPhysicalGPUs = gpuInfo->numberOfGPUInfoItems( );
		
		for ( std::vector<GPUInfo>::const_iterator iter = gpuInfoVector.begin( ); iter != gpuInfoVector.end( ); iter++ )
		{
			GPU gpu;

			gpu._gpuNumber = iter->gpuNumber( ) + 1;
			gpu._name = iter->name( );
			gpu._manufacturer = iter->manufacturer( );
			gpu._caption = iter->caption( );
			gpu._ram = iter->adapterRAM( );
			gpu._refreshRate = iter->refreshRate( );
			gpu._driverVersion = iter->driverVersion( );
			gpu._videoArchitecture = iter->videoArchitecture( );
			gpu._videoModeDescription = iter->videoModeDescription( );
			gpu._videoProcessor = iter->videoProcessor( );
			
			_systemInformation._gpus.push_back( gpu );
		}

		std::unique_ptr<OSInfoDelegate> osInfo = std::make_unique<OSInfoDelegate>( );
		std::vector<OSInfo> osInfoVector = osInfo->osInfoVector( );
		_systemInformation._numberOfOSs = osInfo->numberOfOSInfoItems( );

		for ( std::vector<OSInfo>::const_iterator iter = osInfoVector.begin( ); iter != osInfoVector.end( ); iter++ )
		{
			OS os;

			os._osNumber = iter->osNumber( ) + 1;
			os._name = iter->name( );
			os._manufacturer = iter->manufacturer( );
			os._caption = iter->caption( );
			os._version = iter->version( );
			os._currentDateTime = iter->currentUser( );
			os._installDate = iter->installDate( );
			os._buildNumber = iter->buildNumber( );
			os._lastBootUpTime = iter->lastBootUpTime( );
			os._bootDevice = iter->bootDevice( );
			os._totalVirtualMemory = iter->totalVirtualMemory( );
			os._totalVisibleMemory = iter->totalVisibleMemory( );
			os._totalSwapSize = iter->totalSwapSize( );
			os._serialNumber = iter->serialNumber( );
			os._freePhysicalMemory = iter->freePhysicalMemory( );
			os._freeVirtualMemory = iter->freeVirtualMemory( );
			os._freePagingFileSpace = iter->freePagingFileSpace( );
			os._usingPagingFileSpace = iter->usedPagingFileSpace( );
			os._currentDateTime = iter->currentDateTime( );
			
			_systemInformation._oss.push_back( os );
		}
	}

	float SysInfo::CalculateCPULoad( unsigned long long idleTicks, unsigned long long totalTicks )
	{
		static unsigned long long _previousTotalTicks = 0;
		static unsigned long long _previousIdleTicks = 0;

		unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
		unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;

		float ret = 1.0f - ( ( totalTicksSinceLastTime > 0 ) ? ( ( float )idleTicksSinceLastTime ) / totalTicksSinceLastTime : 0 );

		_previousTotalTicks = totalTicks;
		_previousIdleTicks = idleTicks;

		return ret;
	}

	unsigned long long SysInfo::FileTimeToInt64( const FILETIME &ft )
	{ return ( ( ( unsigned long long )( ft.dwHighDateTime ) ) << 32 ) | ( ( unsigned long long )ft.dwLowDateTime ); }

	// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
	// You'll need to call this at regular intervals, since it measures the load between
	// the previous call and the current one.  Returns -1.0 on error.
	float SysInfo::GetCPULoad( )
	{
		FILETIME idleTime, kernelTime, userTime;

		return GetSystemTimes( &idleTime, &kernelTime, &userTime ) ? CalculateCPULoad( FileTimeToInt64( idleTime ), FileTimeToInt64( kernelTime ) + FileTimeToInt64( userTime ) ) : -1.0f;
	}
}