/*******************************************************************************

    Object that reads and writes to the hard disk;
    used to read and write player statistics and saved configurations

*******************************************************************************/

#ifndef STATISTICSIO_H
#define STATISTICSIO_H

#include <iostream>
#include <fstream>
#include <string>


class StatisticsIO
{
public:
    StatisticsIO(char *filePath);
    void reset();
    void setPlayerOneScore(int score);
    void setPlayerTwoScore(int score);
    void setVolume(int vol);
    int getPlayerOneScore();
    int getPlayerTwoScore();
    int getVolume();
private:
    enum StatisticalData {
        PLAYER_ONE_HEALTH,
        PLAYER_TWO_HEALTH,
        VOLUME
    };
    void writeToLine(int value, StatisticalData type);
    std::string readLine(StatisticalData type);
    bool isEmpty();
    std::fstream *_file;
    char *_filePath;
};

#endif // STATISTICSIO_H
