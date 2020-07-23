#ifndef OTA_HH
#define OTA_HH

class ota_t {
public:
    // initialize over-the-air update handler
    ota_t(const char * hostname);
    // perform over-the-air updates when requested
    void handle();
};

#endif
