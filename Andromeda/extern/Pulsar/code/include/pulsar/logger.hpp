#pragma once

#include <iostream>
#include <sstream>
#include <vector>

namespace Pulsar
{
	using PrintFunc = void (*)(std::ostream& outputStream, std::ostringstream& buffer);

	struct FormatedLogger
	{
		std::ostream* m_outputStream;
		std::vector<PrintFunc> m_printers;
	};

	class Logger
	{
	public:

		template<typename... Printers>
		void AddOutputStream(std::ostream& outputStream, Printers... printers)
		{
			FormatedLogger formatedLogger;

			formatedLogger.m_outputStream = &outputStream;
			AddPrinter(formatedLogger, printers...);
			m_outputStreams.push_back(formatedLogger);
		}

		template<typename... Printables>
		void Log(Printables... printables)
		{
			PrepareBuffer(printables...);
			LogBuffer();
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

		void LogBuffer();

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