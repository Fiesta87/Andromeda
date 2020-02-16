#include <pulsar/logger.hpp>

#include <ctime>
#include <iomanip>

namespace Pulsar
{
	void Logger::LogBuffer(LogLevel level)
	{
		for (FormatedLogger log : m_outputStreams)
		{
			if(((uint8_t)log.m_levels & (uint8_t)level) == (uint8_t)level)
				for (PrintFunc printer : log.m_printers)
				{
					printer(*log.m_outputStream, m_outputBuffer);
				}
		}
		m_outputBuffer.str("");
	}

	///////////////////////
	// Defaults Printers //
	///////////////////////

	void DefaultPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		outputStream << buffer.str() << std::endl;
	}

	void RawPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		outputStream << buffer.str();
	}

	void TimedPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		std::time_t t = std::time(nullptr);
		outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X") << " | " << buffer.str() << std::endl;
	}

	void TimePrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		std::time_t t = std::time(nullptr);
		outputStream << std::put_time(std::localtime(&t), "%d-%m-%Y.%X");
	}

	void SeparatorPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		outputStream << " | ";
	}

	void EndlPrinter(std::ostream& outputStream, std::ostringstream& buffer)
	{
		outputStream << std::endl;
	}
}