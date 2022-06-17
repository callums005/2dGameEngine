#pragma once
#include "../Core/PCH.h"

#define CNORMAL	8	
#define CRED	4	| 0x0008
#define CGREEN	10	| 0x0008
#define CYELLOW	6	| 0x0008
#define CBLUE	1	| 0x0008
#define CWHITE	7	| 0x0008

namespace Engine
{
	class Logger
	{
	public:
		template<typename... Args>
		static void Trace(const char* message, Args... args)
		{
			std::scoped_lock lock(m_LogMutex);
			SetConsoleTextAttribute(m_Handle, CWHITE);
			printf("[TRACE]\t");
			printf(message, args...);
			printf("\n");
		}

		template<typename... Args>
		static void Debug(const char* message, Args... args)
		{
			SetConsoleTextAttribute(m_Handle, CGREEN);
			std::scoped_lock lock(m_LogMutex);
			printf("[DEBUG]\t");
			printf(message, args...);
			printf("\n");
		}

		template<typename... Args>
		static void Info(const char* message, Args... args)
		{
			SetConsoleTextAttribute(m_Handle, CNORMAL);
			std::scoped_lock lock(m_LogMutex);
			printf("[INFO]\t");
			printf(message, args...);
			printf("\n");
		}

		template<typename... Args>
		static void Warn(const char* message, Args... args)
		{
			SetConsoleTextAttribute(m_Handle, CYELLOW);
			std::scoped_lock lock(m_LogMutex);
			printf("[WARNING]\t");
			printf(message, args...);
			printf("\n");
		}

		template<typename... Args>
		static void Error(const char* message, Args... args)
		{
			SetConsoleTextAttribute(m_Handle, CRED);
			std::scoped_lock lock(m_LogMutex);
			printf("[ERROR]\t");
			printf(message, args...);
			printf("\n");
		}

		template<typename... Args>
		static void Fatial(const char* message, Args... args)
		{
			SetConsoleTextAttribute(m_Handle, CBLUE);
			std::scoped_lock lock(m_LogMutex);
			printf("[FATIAL]\t");
			printf(message, args...);
			printf("\n");
		}

	private:
		static std::mutex m_LogMutex;
		inline static const HANDLE m_Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	};
}

std::mutex Engine::Logger::m_LogMutex;
