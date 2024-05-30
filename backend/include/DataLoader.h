#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "DBConnection.h"

class DataLoader {
public:
    DataLoader(DBConnection* dbConn);
    void loadCanteenData(const std::string& filePath);
    void loadStallData(const std::string& filePath);
    void loadDishData(const std::string& filePath);
private:
    DBConnection* dbConn;
    void executeQuery(const std::string& query);
};

#endif 
