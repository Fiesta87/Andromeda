#pragma once

#include <iostream>
#include <sstream>
#include <vector>

namespace Pulsar
{
	using PrintFunc = void (*)(std::ostream& outputStream, std::ostringstream& buffer);

	enum class LogLevel : uint8_t
	{
		None = 0x00,
		All = 0xFF,
		Debug = 0x01,
		Info = 0x02,
		Warning = 0x04,
		Critical = 0x08,
		Fatal = 0x10
	};

	struct FormatedLogger
	{
		std::ostream* m_outputStream;
		LogLevel m_levels;
		std::vector<PrintFunc> m_printers;
	};

	class Logger
	{
	public:

		template<typename... Printers>
		void AddOutputStream(std::ostream& outputStream, LogLevel levels, Printers... printers)
		{
			FormatedLogger formatedLogger;

			formatedLogger.m_outputStream = &outputStream;
			formatedLogger.m_levels = levels;
			AddPrinter(formatedLogger, printers...);
			m_outputStreams.push_back(formatedLogger);
		}

		template<typename... Printables>
		void Log(LogLevel level, Printables... printables)
		{
			PrepareBuffer(printables...);
			LogBuffer(level);
		}

		template<typename... Printables>
		void Log(uint8_t level, Printables... printables)
		{
			PrepareBuffer(printables...);
			LogBuffer((LogLevel)level);
		}

		template<typename... Printables>
		void LogDebug(Printables... printables)
		{
			Log(LogLevel::Debug, printables...);
		}

		template<typename... Printables>
		void LogInfo(Printables... printables)
		{
			Log(LogLevel::Info, printables...);
		}

		template<typename... Printables>
		void LogWarning(Printables... printables)
		{
			Log(LogLevel::Warning, printables...);
		}

		template<typename... Printables>
		void LogCritical(Printables... printables)
		{
			Log(LogLevel::Critical, printables...);
		}

		template<typename... Printables>
		void LogFatal(Printables... printables)
		{
			Log(LogLevel::Fatal, printables...);
		}

	private:

		template<typename Printer, typename... Printers>
		void AddPrinter(FormatedLogger& formatedLogger, Printer printer, Printers... printers)
		{
			formatedLogger.m_printers.push_back(printer);
			AddPrinter(formatedLogger, printers...);
		}

		template<typename Printer>
		void AddPrinter(FormatedLogger& formatedLogger, Printer printer)
		{
			formatedLogger.m_printers.push_back(printer);
		}

		void PrepareBuffer()
		{}

		template<typename Printable>
		void PrepareBuffer(Printable printable)
		{
			m_outputBuffer << printable;
		}

		template<typename Printable, typename... Printables>
		void PrepareBuffer(Printable printable, Printables... printables)
		{
			m_outputBuffer << printable;
			PrepareBuffer(printables...);
		}

		void LogBuffer(LogLevel level);

		std::ostringstream m_outputBuffer;
		std::vector<FormatedLogger> m_outputStreams;
	};

	void DefaultPrinter(std::ostream& outputStream, std::ostringstream& buffer);
	void RawPrinter(std::ostream& outputStream, std::ostringstream& buffer);
	void TimedPrinter(std::ostream& outputStream, std::ostringstream& buffer);
	void TimePrinter(std::ostream& outputStream, std::ostringstream& buffer);
	void SeparatorPrinter(std::ostream& outputStream, std::ostringstream& buffer);
	void EndlPrinter(std::ostream& outputStream, std::ostringstream& buffer);
}