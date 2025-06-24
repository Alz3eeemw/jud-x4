#include "HistoryManager.h"

void HistoryManager::begin() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
    }
}

bool HistoryManager::saveScan(const float data[10][10], const ScanSettings& settings) {
    String filename = "/scan_" + String(millis()) + ".dat";
    File file = SPIFFS.open(filename, FILE_WRITE);
    if (!file) return false;
    file.write((const uint8_t*)&settings, sizeof(ScanSettings));
    file.write((const uint8_t*)data, sizeof(float) * 10 * 10);
    file.close();
    return true;
}

std::vector<std::string> HistoryManager::listScans() {
    std::vector<std::string> fileList;
    File root = SPIFFS.open("/");
    if (!root) return fileList;
    File file = root.openNextFile();
    while (file) {
        if (String(file.name()).startsWith("/scan_")) {
            fileList.push_back(file.name());
        }
        file = root.openNextFile();
    }
    root.close();
    return fileList;
}

bool HistoryManager::loadScan(const char* filename, float data[10][10], ScanSettings& settings) {
    File file = SPIFFS.open(filename, FILE_READ);
    if (!file) return false;
    file.read((uint8_t*)&settings, sizeof(ScanSettings));
    file.read((uint8_t*)data, sizeof(float) * 10 * 10);
    file.close();
    return true;
}

bool HistoryManager::sendScan(const char* filename, CommunicationManager& comms) {
    ScanSettings loadedSettings;
    float loadedData[10][10];
    if (loadScan(filename, loadedData, loadedSettings)) {
        comms.sendGridSetupCommand(loadedSettings.gridWidth, loadedSettings.gridHeight);
        delay(100);
        for (int y = 0; y < loadedSettings.gridHeight; y++) {
            for (int x = 0; x < loadedSettings.gridWidth; x++) {
                comms.sendPointData(x, y, loadedData[y][x]);
                delay(10);
            }
        }
        return true;
    }
    return false;
}

bool HistoryManager::deleteScan(const char* filename) {
    return SPIFFS.remove(filename);
}
