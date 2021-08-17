/**
* \brief Using code from https://github.com/tlewiscpp/SystemInfo
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

#include "systeminfo.h"

/**
* \brief creates a static variable to convert Bytes to Megabytes
*/
#define MB 1048576

/**
* \brief Used when converting between different memory units
*/
#define MEMORY_MULTIPLIER 1024.0f

namespace Sonar
{
	/**
	* \brief Memory format
	*/
	enum class MemoryFormat { Bits, Bytes, Kilobytes, Megabytes, Gigabytes };

	/**
	* \brief Timestamp
	*/
	struct Timestamp
	{
		unsigned int _hour;
		unsigned int _minutes;
		unsigned int _seconds;
		unsigned int _milliseconds;
		unsigned int _day;
		unsigned int _month;
		unsigned short _year;
		unsigned short _dayOfTheWeek;
	};

	/**
	* \brief CPU stats
	*/
	struct CPU
	{
		int _cpuNumber = 1; // Which physical CPU it is (starts at 1)
		std::string _name;
		std::string _manufacturer;
		std::string _coreCount;
		std::string _clockSpeed;
		std::string _architecture;
		std::string _l2CacheSize;
		std::string _l3CacheSize;
		std::string _temperature;
	};

	/**
	* \brief Motherboard stats
	*/
	struct Motherboard
	{
		int _motherboardNumber = 1; // Which physical MOBO it is (starts at 1)
		std::string _name;
		std::string _manufacturer;
		std::string _chipset;
		std::string _serialNumber;
		std::string _version;
	};

	/**
	* \brief RAM stats
	*/
	struct RAM
	{
		int _ramNumber = 1; // Which physical RAM stick it is (starts at 1)
		std::string _name;
		std::string _manufacturer;
		std::string _capacity;
		std::string _serialNumber;
		std::string _formFactor;
		std::string _partNumber;
		std::string _memoryType;
		std::string _clockSpeed;
	};

	/**
	* \brief GPU stats
	*/
	struct GPU
	{
		int _gpuNumber = 1; // Which physical GPU it is (starts at 1)
		std::string _name;
		std::string _manufacturer;
		std::string _caption;
		std::string _ram;
		std::string _refreshRate;
		std::string _driverVersion;
		std::string _videoArchitecture;
		std::string _videoModeDescription;
		std::string _videoProcessor;
	};

	/**
	* \brief OS stats
	*/
	struct OS
	{
		int _osNumber = 1; // Which OS it is (starts at 1)
		std::string _name;
		std::string _manufacturer;
		std::string _caption;
		std::string _version;
		std::string _currentUser;
		std::string _installDate;
		std::string _buildNumber;
		std::string _lastBootUpTime;
		std::string _bootDevice;
		std::string _totalVirtualMemory;
		std::string _totalVisibleMemory;
		std::string _totalSwapSize;
		std::string _serialNumber;
		std::string _freePhysicalMemory;
		std::string _freeVirtualMemory;
		std::string _freePagingFileSpace;
		std::string _usingPagingFileSpace;
		std::string _currentDateTime;
	};

	/**
	* \brief System information (all memory is in Bytes)
	*/
	struct SystemInformation
	{
	public:
		Timestamp _timestamp;

		float _cpuLoadAverage = 0.0f, _cpuLoadMin = 0.0f, _cpuLoadMax = 0.0f, _cpuLoadLast = 0.0f;
		unsigned long _memoryLoad;
		float _physicalTotalMemory;
		float _physicalAvailableMemory;
		float _pageFileTotalMemory;
		float _pageFileAvailableMemory;
		float _virtualTotalMemory;
		float _virtualAvailableMemory;
		float _virtualExtendedAvailableMemory;

		int _numberOfPhysicalCPUs;
		std::vector<CPU> _cpus; // Will most likely only be one for most systems

		int _numberOfPhysicalMotherboards;
		std::vector<Motherboard> _motherboards; // Will most likely only be one for most systems

		int _numberOfPhysicalRAMSticks;
		std::vector<RAM> _ramSticks;

		int _numberOfPhysicalGPUs;
		std::vector<GPU> _gpus;

		int _numberOfOSs;
		std::vector<OS> _oss; // Will most likely only be one for most systems
	};

	class SysInfo
	{
	public:
		/**
		* \brief Constructor
		* 
		* \param memoryFormat Memory units to store memory stats in
		* \param loadSystemInfo Should the system info be loaded at the start (can be abit slow so can be disabled, recommend loading during a loading screen)
		*/
		SysInfo( const MemoryFormat &memoryFormat = MemoryFormat::Gigabytes, const bool loadSystemInfo = false );

		/**
		* \brief Default destructor
		*/
		~SysInfo( ) = default;

		/**
		* \brief Get the current system stats
		*
		* \return Output returns the system's statistics
		*/
		const SystemInformation &GetSystemInformation( );

		/**
		* \brief Loads the system information (only needs to be run once)
		*/
		void LoadSystemInformation( );

	private:
		/**
		* \brief Calculate the CPU's load (as a percentage)
		*
		* \param idleTicks Number of ticks whilst idle
		* \param totalTicks Number of total ticks
		*
		* \return Output returns the CPU load
		*/
		float CalculateCPULoad( unsigned long long idleTicks, unsigned long long totalTicks );

		/**
		* \brief Convert file time to int 64
		*
		* \param ft File time
		*
		* \return Output returns the converted file time
		*/
		unsigned long long FileTimeToInt64( const FILETIME &ft );

		/**
		* \brief Get the CPU load
		*
		* \return Output returns the CPU's load
		*/
		float GetCPULoad( );

		/**
		* \brief System information struct
		*/
		SystemInformation _systemInformation{ };

		/**
		* \brief Multipler to convert memory units
		*/
		float _memoryFormatMultiplier = pow( MEMORY_MULTIPLIER, 3.0f );

		unsigned long long _cpuLoadCounter;

	};
}
