#include <pulsar.hpp>

#include <ctime>
#include <iomanip>

namespace Pulsar
{
	void Logger::Log(const char* text)
	{
		for (FormatedLogger log : m_outputStreams)
		{
			for (PrintFunc printer : log.m_printers)
			{
				printer(log.m_outputStream, text);
			}
		}
	}

	///////////////////////
	// Defaults Printers //
	///////////////////////

	void DefaultPrinter(std::ostream* outputStream, const char* text)
	{
		*outputStream << text << std::endl;
	}

	void RawPrinter(std::ostream* outputStream, const char* text)
	{
		*outputStream << text;
	}

	void TimedPrinter(std::ostream* outputStream, const char* text)
	{
		std::time_t t = std::time(nullptr);
		*outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X") << " | " << text << std::endl;
	}

	void TimePrinter(std::ostream* outputStream, const char* text)
	{
		std::time_t t = std::time(nullptr);
		*outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X");
	}

	void SeparatorPrinter(std::ostream* outputStream, const char* text)
	{
		*outputStream << " | ";
	}

	void EndlPrinter(std::ostream* outputStream, const char* text)
	{
		*outputStream << std::endl;
	}
}