#include <andromeda/config.hpp>

#include <string>

namespace Andromeda
{
	void Config::Add(uint32_t key, char* value)
	{
		const auto [it, success] = m_map.insert(std::pair<uint32_t, char*>(key, value));
		PULSAR_SOFTASSERT(success);
	}

	void Config::Add(char* key, char* value)
	{
		size_t keySize = strlen(key);
		if (key[keySize - 1] == '\0')
			keySize--;

		PULSAR_ASSERT(keySize > 0, "empty string can't be used as config key.");
		uint32_t crc = PULSAR_CRC32(key, keySize);
		Add(crc, value);
	}

	void Config::AddCmdLineArgs(int argc, char* argv[])
	{
		std::string delimiterChar = std::string("=");

		for (int i = 1; i < argc; i++)
		{
			std::string str = std::string(argv[i]);
			size_t delimiterIndex = str.find_first_of(delimiterChar);

			if (delimiterIndex != std::string::npos)
			{
				PULSAR_ASSERT(str.length() > delimiterIndex + 2, "no value specified after delimiter '", delimiterChar, "' for cmd line arg : ", str);
				Add(PULSAR_CRC32(argv[i], delimiterIndex), argv[i] + delimiterIndex + 1);
				continue;
			}

			Add(argv[i], nullptr);
		}
	}

	char* Config::Get(uint32_t key)
	{
		auto it = m_map.find(key);
		PULSAR_ASSERT(it != m_map.end(), "key not found.");
		return it->second;
	}

	char* Config::Get(char* key)
	{
		size_t keySize = strlen(key);
		if (key[keySize - 1] == '\0')
			keySize--;

		PULSAR_ASSERT(keySize > 0, "empty string can't be used as config key.");
		uint32_t crc = PULSAR_CRC32(key, keySize);
		return Get(crc);
	}

	bool Config::IsSet(uint32_t key)
	{
		auto it = m_map.find(key);
		return it != m_map.end();
	}

	bool Config::IsSet(char* key)
	{
		size_t keySize = strlen(key);
		if (key[keySize - 1] == '\0')
			keySize--;

		PULSAR_ASSERT(keySize > 0, "empty string can't be used as config key.");
		uint32_t crc = PULSAR_CRC32(key, keySize);
		return IsSet(crc);
	}
}