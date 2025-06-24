#ifndef HISTORY_MANAGER_H
#define HISTORY_MANAGER_H

#include <SPIFFS.h>
#include <FS.h>
#include <vector>
#include <string>
#include "config.h"
#include "CommunicationManager.h"

class HistoryManager {
public:
    void begin();
    bool saveScan(const float data[10][10], const ScanSettings& settings);
    bool loadScan(const char* filename, float data[10][10], ScanSettings& settings);
    bool sendScan(const char* filename, CommunicationManager& comms);
    bool deleteScan(const char* filename);
    std::vector<std::string> listScans();
};

#endif // HISTORY_MANAGER_H
