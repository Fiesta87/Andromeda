#pragma once

#include <iostream>
#include <vector>

namespace Pulsar
{
	using PrintFunc = void (*)(std::ostream* outputStream, const char* text);

	struct FormatedLogger
	{
		std::ostream* m_outputStream;
		std::vector<PrintFunc> m_printers;
	};

	class Logger
	{
	public:

		template<typename... Printers>
		void AddOutputStream(std::ostream* outputStream, Printers... printers)
		{
			FormatedLogger formatedLogger;

			formatedLogger.m_outputStream = outputStream;
			AddPrinter(formatedLogger, printers...);
			m_outputStreams.push_back(formatedLogger);
		}

		void Log(const char* text);

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

		std::vector<FormatedLogger> m_outputStreams;
	};

	void DefaultPrinter(std::ostream* outputStream, const char* text);
	void RawPrinter(std::ostream* outputStream, const char* text);
	void TimedPrinter(std::ostream* outputStream, const char* text);
	void TimePrinter(std::ostream* outputStream, const char* text);
	void SeparatorPrinter(std::ostream* outputStream, const char* text);
	void EndlPrinter(std::ostream* outputStream, const char* text);
}