#include "statisticsio.h"
#include <sstream>
#include <stdlib.h>

std::string DEFAULT_SCORE = "0";
std::string DEFAULT_VOLUME = "100";

StatisticsIO::StatisticsIO(char *filePath)
{
    _filePath = filePath;
}

/********************************************************** SETTERS / GETTERS */

void StatisticsIO::setPlayerOneScore(int score)
{
    writeToLine(score, PLAYER_ONE_HEALTH);
}

void StatisticsIO::setPlayerTwoScore(int score)
{
    writeToLine(score, PLAYER_TWO_HEALTH);
}

void StatisticsIO::setVolume(int vol)
{
    writeToLine(vol, VOLUME);
}

int StatisticsIO::getPlayerOneScore()
{
    std::string score = readLine(PLAYER_ONE_HEALTH);
    return atoi(score.c_str());
}

int StatisticsIO::getPlayerTwoScore()
{
    std::string score = readLine(PLAYER_TWO_HEALTH);
    return atoi(score.c_str());
}

int StatisticsIO::getVolume()
{
    std::string vol = readLine(VOLUME);
    return atoi(vol.c_str());
}


/************************************************************* INPUT / OUTPUT */

// reset statistics to default values
void StatisticsIO::reset()
{
    std::ofstream out(_filePath);
    if(out) {
        out << DEFAULT_SCORE << '\n';
        out << DEFAULT_SCORE << '\n';
        out << DEFAULT_VOLUME << '\n';
    } else {
        std::cerr << "could not open file: " << _filePath << '\n';
    }
    out.close();
}

// write a value for the specified data type to a file
void StatisticsIO::writeToLine(int value, StatisticalData type)
{
    std::string stringVal = static_cast<std::ostringstream*>( &(std::ostringstream() << value) )->str();
    std::string output;
    std::string line;

    // read current data and replace with new data
    std::ifstream in;
    in.open(_filePath);
    if(in) {
        for (int i = 0; i < 3; i++) {
            std::getline(in, line);
            if (i == type) {
                output += stringVal;
            } else {
                output += line;
            }
            output += '\n';
        }

        // write data to file
        std::ofstream out;
        out.open(_filePath);
        if(out) {
            out << output.c_str();
            out.close();
        }
    }
}

// read a value for the specified data type from a file
std::string StatisticsIO::readLine(StatisticalData type)
{
    std::ifstream in;
    std::string line;
    int i = 0;

    // find value in file
    in.open(_filePath);
    if (in) {
        while (std::getline(in, line)) {
            if (i == type) {
                return line;
            }
            i++;
        }
    }
    in.close();

    // no value found or issue with file IO
    if (type == VOLUME) {
        return DEFAULT_VOLUME;
    } else {
        return DEFAULT_SCORE;
    }
}
