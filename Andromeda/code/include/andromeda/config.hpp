#pragma once

#include <map>

#include <pulsar/assert.hpp>
#include <pulsar/crc.hpp>

namespace Andromeda
{
	class Config
	{
	public:
		static Config& Instance()
		{
			static Config instance;
			return instance;
		}

		void Add(uint32_t key, char* value);
		void Add(char* key, char* value);

		void AddCmdLineArgs(int argc, char* argv[]);

		char* Get(uint32_t key);
		char* Get(char* key);
		bool IsSet(uint32_t key);
		bool IsSet(char* key);

	private:
		std::map<uint32_t, char*> m_map;
	};
}