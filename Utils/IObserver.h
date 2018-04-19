#pragma once

class IObserver
{
    public:
        virtual void writeMessageLine(std::string message, std::string mvc) = 0;
        virtual void writeWarningLine(std::string message, std::string mvc) = 0;
        virtual void writeErrorLine(std::string message, std::string mvc) = 0;
        virtual void updateLevel(int newLevel) = 0;
};
